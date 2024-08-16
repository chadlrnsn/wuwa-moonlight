#pragma once
#include "dllmain.h"
#include <Hooks/d3d11hook.h>
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

void GlobalsThread() noexcept {

	static bool originals = false;
	while (g_bRunning) {

		if (!UEngine::GetEngine()) continue;
		Engine = UEngine::GetEngine();

		if (!UWorld::GetWorld()) continue;
		World = UWorld::GetWorld();
		
		GameInstance = World->OwningGameInstance;

		if (!GameInstance) continue;

		LocalPlayer = World->OwningGameInstance->LocalPlayers[0];

		if (!LocalPlayer) continue;

		PlayerController = LocalPlayer->PlayerController;

		if (!PlayerController) continue;

		AcknowledgedPawn = PlayerController->AcknowledgedPawn;

		if (IsFullyLoaded() && AcknowledgedPawn && !AcknowledgedPawn->IsDefaultObject() && FN_TsAnimNotifyReSkillEvent_C == nullptr) {
			FN_TsAnimNotifyReSkillEvent_C = World->FindObject<UFunction>("Function TsAnimNotifyReSkillEvent.TsAnimNotifyReSkillEvent_C.K2_Notify");
		}
	}
	std::cout << "Thread ended" << std::endl;
}

void FeaturesThread() noexcept
{

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

	Hooks::hkACE_BypassSetup();
	Hooks::AntiDebug();
	D3D11Hook::Initialize();
	Hooks::InGame::Initialize();

	std::thread globals(GlobalsThread);
	std::thread features(FeaturesThread);


	while (true) {

		if (GetAsyncKeyState(QuitKey) & 1) {
			g_bRunning = false;
			break;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}


	features.join();
	globals.join();
	
	D3D11Hook::Uninitialize();
	Hooks::RemoveHooks();

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

		break;

	case DLL_PROCESS_DETACH:
		FreeConsole();
		fclose(dummy);
		break;
	}

	return TRUE;
}