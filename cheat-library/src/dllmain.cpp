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

void HookThread() {


	// this neen for in-game hooks and d3d11 hooks
	while (!GetModuleHandleA("kernel32.dll") && !GetModuleHandleA("ntdll.dll") && !GetModuleHandleA("Client-Win64-ShippingBase.dll")) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	printf("Modules loaded\n");


	Hooks::InGame::Initialize();
	D3D11Hook::Initialize();

}


void GlobalsThread() {

	static bool originals = false;
	while (g_bRunning) {

		Engine = UEngine::GetEngine();
		if (!Engine) continue;

		World = UWorld::GetWorld();
		if (!World) continue;

		if (!originals) {
			tfuncs::ReSkillEvent_C = World->FindObject("Function TsAnimNotifyReSkillEvent.TsAnimNotifyReSkillEvent_C.K2_Notify");
			//FN_KuroDestructibleActor_C_ApplyDamage = World->FindObject("Function BP_KuroDestructibleActor.BP_KuroDestructibleActor_C.ApplyDamage");
			originals = true;
		}

		if (IsFullyLoaded(World)) {
			GameInstance = World->OwningGameInstance;
			LocalPlayer = GameInstance->LocalPlayers[0];
			PlayerController = LocalPlayer->PlayerController;
			AcknowledgedPawn = PlayerController->AcknowledgedPawn;
			MovementComponent = AcknowledgedPawn->GetMovementComponent();
			Levels = World->Levels;
		}
	}
	std::cout << "Thread ended" << std::endl;
}

void FeaturesThread()
{
	while (g_bRunning)
	{
		fpsUnlock.Run();
		if (!IsFullyLoaded(World))
			continue;


		//void* acknowledgePawnPtr[2] = { AcknowledgedPawn, World };

		//speedhack.Run(acknowledgePawnPtr, 1);
		//god.Run(acknowledgePawnPtr, 1);
		//gravityScale.Run(acknowledgePawnPtr, 1);
		//walkFloorZ.Run(acknowledgePawnPtr, 1);
		//walkFloorAngle.Run(acknowledgePawnPtr, 1);

		//void* flyArgs[2] = { AcknowledgedPawn, MovementComponent };
		//fly.Run(flyArgs, 1);

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	return;
}

DWORD WINAPI MainThread(HMODULE hMod, LPVOID lpReserved)
{
	std::thread features(FeaturesThread);
	std::thread hooks(HookThread);
	std::thread globals(GlobalsThread);

	if (MH_Initialize() != MH_OK) {
		std::cerr << "Failed to init MinHook" << std::endl;
	}
	else
		printf("MinHook initialized");




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

	globals.join();
	features.join();

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