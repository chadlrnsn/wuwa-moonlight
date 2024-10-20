#pragma once
#include <stdafx.h>
#include <Hooks/d3d11hook.h>
#include <logger/logger.h>

#include <Menu/Menu.h>
#include <Helper/Helper.h>
#include <Hooks/Hooks.h>
#include <wuwa-base/util.h>
#include <globals.h>

DWORD WINAPI MainThread(HMODULE hMod, LPVOID lpReserved);
BOOL APIENTRY DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved);
bool CreateConsole();
void IndependentHooks();
void updateGlobals() noexcept;
void keyHandleFunc();

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


void updateGlobals() noexcept {

	while (!g_break) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		Helper::UpdateGlobals();
	}

}

void keyHandleFunc()
{
	while (!g_break) {

		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		if (GetAsyncKeyState(VK_F9) & 1) {
			LOG_INFO("Uninjecting...");
			g_break = true;
			break;
		}
	}
}

DWORD WINAPI MainThread(HMODULE hMod, LPVOID lpReserved)
{
	if (MH_Initialize() != MH_OK) {
		LOG_ERROR("Failed to init MinHook");
		return FALSE;
	}
	
	LOG_INFO("MinHook initialized");

	std::thread keyHandle(keyHandleFunc);
	std::thread globals(updateGlobals);
	//std::thread Indpndhk(IndependentHooks);

	keyHandle.detach();
	globals.detach();
	//Indpndhk.detach();

	while (!g_break) {
		if (Helper::IsGameExploitable()) {
			speedhack.Run();
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	D3D11Hook::Uninitialize();
	Hooks::RemoveHooks();

	LOG_INFO("Now you can close console and re-inject or inject another cheetos!\n");

	FreeLibraryAndExitThread(hMod, 0);
	return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{

	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);

#ifdef _DEBUG
		CreateConsole();
#endif // _DEBUG

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