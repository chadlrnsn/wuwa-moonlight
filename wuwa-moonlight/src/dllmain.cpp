#include <dllmain.h>
#include <d3d11hook.h>
#include <logger.h>
#include <Hooks.h>
#include <UpdateVars.h>
#include <config.h>

using namespace SDK;
using namespace globals;


DWORD WINAPI MainThread(HMODULE hMod, [[maybe_unused]] LPVOID lpReserved)
{
	Logger::Init("Moonlight");

	if (MH_Initialize() != MH_OK) LOG_ERROR("Failed to init MinHook");
	else LOG_SUCCESS("MinHook initialized");

	if (!Hooks::hkACE_BypassSetup()) LOG_ERROR("Failed to setup ACE bypass");
	else LOG_SUCCESS("ACE bypass setup");

	Hooks::AntiDebug();
	D3D11Hook::Initialize();
	Hooks::InGame::Initialize();

	LOG_INFO("You can detach this dll from your process with F9\n");
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		
		if (GetAsyncKeyState(VK_END) & 0x8000)
		{
			LOG_INFO("Detaching dll...");
			break;
		}

		try
		{
			utils::UpdateGlobals();
		}
		catch (const std::exception& e)
		{
			LOG_ERROR("Exception caught in UpdateThread: %s", e.what());
		}
	}


	D3D11Hook::Uninitialize();
	Hooks::RemoveHooks();

	Logger::Shutdown();

	FreeLibraryAndExitThread(hMod, 0);
	return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hMod, DWORD dwReason, [[maybe_unused]] LPVOID lpReserved)
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