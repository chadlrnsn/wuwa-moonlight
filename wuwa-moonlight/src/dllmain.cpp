#include <dllmain.h>
#include <d3d11hook.h>
#include <logger.h>
#include <Hooks/Hooks.h>
#include <UpdateVars.h>
#include <config.h>

using namespace SDK;
using namespace globals;

FILE* dummy;
std::atomic<bool> g_bRunning{ true };



void IndependentHooks()
{
	Hooks::hkACE_BypassSetup();
	Hooks::AntiDebug();
	D3D11Hook::Initialize();
	Hooks::InGame::Initialize();
}

void features() noexcept
{
	while (g_bRunning)
	{
		utils::UpdateGlobals();
		// FN_TsAnimNotifyStateCounterAttack_C = c_viewport->FindObject("Function TsAnimNotifyStateCounterAttack.TsAnimNotifyStateCounterAttack_C.K2_NotifyBegin");
	}
}

DWORD WINAPI MainThread(HMODULE hMod, LPVOID lpReserved)
{
	Logger::Init("LetItHappen");

	if (MH_Initialize() != MH_OK)
	{
		std::cerr << "Failed to init MinHook" << std::endl;
	}
	else
		printf("MinHook initialized\n");

	std::thread Indpndhk(IndependentHooks);
	std::thread ft(features);

	Indpndhk.join();

	printf("You can detach this dll from your process with F9\n");
	while (true)
	{

		if (GetAsyncKeyState(config::binds::quit_key) & 1)
		{
			g_bRunning = false;
			break;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	ft.join();

	D3D11Hook::Uninitialize();
	Hooks::RemoveHooks();

	Logger::Shutdown();

	FreeLibraryAndExitThread(hMod, 0);
	return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);
		CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, hMod, 0, 0));
		break;
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}