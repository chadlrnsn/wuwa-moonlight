#pragma once
#include "dllmain.h"
#include <Hooks/d3d11hook.h>

using namespace SDK;
using namespace globals;

FILE* dummy;
std::atomic<bool> g_bRunning{ true };

void CreateConsole() {
	AllocConsole();
	freopen_s(&dummy, "CONOUT$", "w", stdout);
	freopen_s(&dummy, "CONOUT$", "w", stderr);
}


void IndependentHooks() {
	Hooks::hkACE_BypassSetup();
	Hooks::AntiDebug();
	D3D11Hook::Initialize();
	Hooks::InGame::Initialize();
}

void features() noexcept {
	while (g_bRunning) {

		Engine = UEngine::GetEngine();

		if (!Engine) continue;
		fpsUnlock.Run();
		
		if (!Engine) continue;

		World = UWorld::GetWorld();

		if (!World) 
			continue;

		GameInstance = World->OwningGameInstance;
		if (!GameInstance)
			continue;

		LocalPlayer = GameInstance->LocalPlayers[0];
		if (!LocalPlayer)
			continue;

		PlayerController = LocalPlayer->PlayerController;
		if (!PlayerController)
			continue;

		AcknowledgedPawn = PlayerController->AcknowledgedPawn;
		if (!AcknowledgedPawn)
			continue;

		speedhack.Run();
		//gravityScale.Run();

		//walkFloorZ.Run(PlayerController);
		//walkFloorAngle.Run();
		//fly.Run();
		//esp.Run();

		auto c_viewport = LocalPlayer->ViewportClient;

		//if (!c_viewport) return;

		//if (FN_TsAnimNotifyReSkillEvent_C != c_viewport->FindObject("Function TsAnimNotifyReSkillEvent.TsAnimNotifyReSkillEvent_C.K2_Notify")) continue
		//FN_TsAnimNotifyReSkillEvent_C = c_viewport->FindObject("Function TsAnimNotifyReSkillEvent.TsAnimNotifyReSkillEvent_C.K2_Notify");
		//FN_TsAnimNotifyStateCounterAttack_C = c_viewport->FindObject("Function TsAnimNotifyStateCounterAttack.TsAnimNotifyStateCounterAttack_C.K2_NotifyBegin");


	}
}

DWORD WINAPI MainThread(HMODULE hMod, LPVOID lpReserved)
{

	if (MH_Initialize() != MH_OK) {
		std::cerr << "Failed to init MinHook" << std::endl;
	}
	else
		printf("MinHook initialized\n");

	std::thread Indpndhk(IndependentHooks);
	std::thread ft(features);

	Indpndhk.join();

	printf("You can detach this dll from your process with F9\n");
	while (true) {

		if (GetAsyncKeyState(config::binds::quit_key) & 1) {
			g_bRunning = false;
			break;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	ft.join();
	
	D3D11Hook::Uninitialize();
	Hooks::RemoveHooks();

	printf("Now you can close console and re-inject or inject another cheetos!\n");

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