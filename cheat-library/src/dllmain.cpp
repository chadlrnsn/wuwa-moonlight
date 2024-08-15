#pragma once
#include "dllmain.h"
#include <Hooks/d3d11hook.h>
#include <Hooks/tFunctions.h>
#define MenuKey VK_INSERT
#define QuitKey VK_F9

using namespace SDK;
using namespace globals;

FILE* dummy;
std::atomic<bool> g_bRunning = true;

void CreateConsole() {
	AllocConsole();
	freopen_s(&dummy, "CONOUT$", "w", stdout);
	freopen_s(&dummy, "CONOUT$", "w", stderr);
}

void HookThread() {


	// this neen for in-game hooks and d3d11 hooks
	//while (!GetModuleHandleA("kernel32.dll") && !GetModuleHandleA("ntdll.dll") && !GetModuleHandleA("Client-Win64-ShippingBase.dll")) {
	//	std::this_thread::sleep_for(std::chrono::seconds(1));
	//}
	//printf("Modules loaded\n");


	Hooks::InGame::Initialize();
	D3D11Hook::Initialize();

}


void GlobalsThread() noexcept {

	static bool originals = false;
	while (g_bRunning) {

		Engine = UEngine::GetEngine();
		World = UWorld::GetWorld();

		if (!Engine || !World) continue;

		GameInstance = World->OwningGameInstance;

		if (!GameInstance) continue;

		LocalPlayer = World->OwningGameInstance->LocalPlayers[0];

		if (!LocalPlayer) continue;

		PlayerController = LocalPlayer->PlayerController;

		if (!PlayerController) continue;

		AcknowledgedPawn = PlayerController->AcknowledgedPawn;
	}
	std::cout << "Thread ended" << std::endl;
}

void FeaturesThread() noexcept
{

	TFunction tf;
	tf.Init();

	while (g_bRunning)
	{
		fpsUnlock.Run();
		if (!IsFullyLoaded())
			continue;

		speedhack.Run();
		gravityScale.Run();
		walkFloorZ.Run();
		walkFloorAngle.Run();
		fly.Run();

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	return;
}

DWORD WINAPI MainThread(HMODULE hMod, LPVOID lpReserved)
{
	if (MH_Initialize() != MH_OK) {
		std::cerr << "Failed to init MinHook" << std::endl;
	}
	else
		printf("MinHook initialized\n");

	std::thread features(FeaturesThread);
	std::thread hooks(HookThread);
	std::thread globals(GlobalsThread);


	hooks.join();

	while (true) {

		if (GetAsyncKeyState(QuitKey) & 1) {
			g_bRunning = false;
			Hooks::RemoveHooks();
			break;
		}

		g_ShouldDrawImGui = g_bRunning;

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	features.join();
	globals.join();

	FreeLibraryAndExitThread(hMod, 0);
	return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{

	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);

		CreateConsole();

		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainThread, hMod, 0, nullptr);

		Hooks::hkACE_BypassSetup();
		Hooks::AntiDebug();

		break;

	case DLL_PROCESS_DETACH:
		FreeConsole();
		fclose(dummy);
		break;
	}

	return TRUE;
}