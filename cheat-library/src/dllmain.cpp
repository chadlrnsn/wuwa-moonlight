#pragma once

#include "dllmain.h"
#include <Hooks/d3d11hook.h>
#include <logger/logger.h>

using namespace SDK;
using namespace globals;

FILE* f;

bool CreateConsole() 
{
	if (AllocConsole()) {
		freopen_s(&f, "CONOUT$", "w", stdout);
		freopen_s(&f, "CONOUT$", "w", stderr);
		freopen_s(&f, "CONIN$", "r", stdin);


		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD dwMode = 0;
		GetConsoleMode(hOut, &dwMode);
		dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		SetConsoleMode(hOut, dwMode);
		return true;

	}

	return false;
}


void IndependentHooks() {
	Hooks::hkACE_BypassSetup();
	Hooks::AntiDebug();
	D3D11Hook::Initialize();
	Hooks::InGame::Initialize();
}

void keyHandleFunc()
{
	while (!g_break) {

		if (GetAsyncKeyState(config::binds::quit_key) & 1) {
			g_break = false;
			LOG_INFO("Uninjecting...");
			break;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

DWORD WINAPI MainThread(HMODULE hMod, LPVOID lpReserved)
{

	if (MH_Initialize() != MH_OK) {
		LOG_ERROR("Failed to init MinHook");
	}
	
	LOG_DEBUG("MinHook initialized");

	std::thread keyHandle(keyHandleFunc);
	//std::thread Indpndhk(IndependentHooks);
	//std::thread ft(features);

	keyHandle.detach();
	//Indpndhk.detach();

	LOG_INFO("You can detach this dll from your process with F9\n");

	while (!g_break) {

		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		engine = UEngine::GetEngine();
		if (!engine) {
			LOG_WARN("No engine");
			continue;
		}

		fpsUnlock.Run();
		
		world = UWorld::GetWorld();
		if (!world) {
			LOG_WARN("No world found");
			continue;
		}

		if (!util::IsPointerReadable(&world->OwningGameInstance)) {
			LOG_ERROR("Pointer on LocalPlayer not readable!");
			continue;
		}

		game_instance = world->OwningGameInstance;

		if (!game_instance) {
			LOG_WARN("No game_instance");
			continue;
		}
	
		if (!util::IsPointerReadable(&game_instance->LocalPlayers)) {
			LOG_ERROR("Pointer on LocalPlayer not readable!");
			continue;
		}

		local_players = game_instance->LocalPlayers;

		if (!local_players) {
			LOG_WARN("no local_players");
			continue;
		}

		if (local_players.Num() < 1) {
			LOG_WARN("local_players < 1");
			continue;
		}

		local_player = local_players[0];

		if (!local_player) {
			LOG_WARN("no self");
			continue;
		}

		if (!util::IsPointerReadable(&local_player->PlayerController)) {
			LOG_ERROR("Pointer on LocalPlayer not readable!");
			continue;
		}

		player_controller = local_player->PlayerController;

		if (!player_controller) {
			LOG_WARN("no player controller");
			continue;
		}

		if (!util::IsPointerReadable(&player_controller->AcknowledgedPawn)) {
			LOG_ERROR("Pointer on LocalPlayer not readable!");
			continue;
		}

		pawn = player_controller->AcknowledgedPawn;

		if (!pawn) {
			LOG_WARN("no pawn");
			continue;
		}

		if (!pawn->IsControlled() or !pawn->IsPawnControlled()) {
			LOG_WARN("something not controlled pawn");
			continue;
		}

		//speedhack.Run();
		//gravityScale.Run();

		//walkFloorZ.Run(PlayerController);
		//walkFloorAngle.Run();
		//fly.Run();
		//esp.Run();

	}

	//ft.join();
	
	D3D11Hook::Uninitialize();
	Hooks::RemoveHooks();

	LOG_INFO("Now you can close console and re-inject or inject another cheetos!\n");

	FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(hMod), 0);
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
		fclose(f);
		FreeLibrary(hMod);
		break;
	}

	return TRUE;
}