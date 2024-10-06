#pragma once
#pragma execution_character_set( "utf-8" )

#include "dllmain.h"
#include <Hooks/d3d11hook.h>
#include <logger/logger.h>

using namespace SDK;
using namespace globals;

FILE* dummy;
std::atomic<bool> g_bRunning{ true };

void CreateConsole() {
	if (AllocConsole()) {
		freopen_s(&dummy, "CONOUT$", "w", stdout);
		freopen_s(&dummy, "CONOUT$", "w", stderr);

		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD dwMode = 0;
		GetConsoleMode(hOut, &dwMode);
		dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		SetConsoleMode(hOut, dwMode);
	}
}


void IndependentHooks() {
	Hooks::hkACE_BypassSetup();
	Hooks::AntiDebug();
	D3D11Hook::Initialize();
	Hooks::InGame::Initialize();
}

void features() noexcept {
	while (g_bRunning) {

		engine = UEngine::GetEngine();
		if (!engine) { 
			LOG_WARN("No engine");
			continue;
		}

		fpsUnlock.Run();

		if (!UWorld::GetWorld()) continue;
		world = UWorld::GetWorld();

		game_instance = world->OwningGameInstance;

		if (!game_instance)
			continue;

		local_player = game_instance->LocalPlayers[0];
		if (!local_player)
			continue;

		player_controller = local_player->PlayerController;
		if (!player_controller)
			continue;

		pawn = player_controller->AcknowledgedPawn;
		if (!pawn)
			continue;


		//inline UWorld* world;
		//inline UGameInstance* game_instance;
		//inline ULocalPlayer* local_player;
		//inline APlayerController* player_controller;
		//inline APawn* pawn;

		speedhack.Run();
		gravityScale.Run();

		//walkFloorZ.Run(PlayerController);
		//walkFloorAngle.Run();
		//fly.Run();
		//esp.Run();

		auto c_viewport = local_player->ViewportClient;

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