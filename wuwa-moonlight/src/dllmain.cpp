#include <dllmain.h>
#include <d3d11hook.h>
#include <logger.h>
#include <Hooks.h>
#include <UpdateVars.h>
#include <config.h>
#include <Features/Features.h>
#include <gui/Menu.hpp>

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

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		
		if (GetAsyncKeyState(VK_END) & 0x8000)
		{
			LOG_INFO("Detaching dll...");
			break;
		}

		if (GetAsyncKeyState(config::binds::menu_key) & 1) g_menu->Toggle();

		try
		{
			utils::UpdateGlobals();
			fpsUnlock.get()->Run();
			esp.get()->Run();
		}
		catch (...)
		{
			std::exception_ptr ex = std::current_exception();
			try
			{
				std::rethrow_exception(ex);
			}
			catch (std::bad_exception const& e)
			{
				LOG_ERROR("Exception caught: %s", e.what());
			}
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