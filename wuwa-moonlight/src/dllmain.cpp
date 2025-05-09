#include <dllmain.h>
#include <d3d11hook.h>
#include <logger.h>
#include <Hooks.h>
#include <UpdateVars.h>
#include <config.h>
#include <Features/Features.h>
#include <gui/Menu.hpp>
#include <Config/ConfigHelper.h>

using namespace SDK;
using namespace globals;

template<typename Func>
void SafeExecute(Func func, const char* featureName) {
    try {
        func();
    }
    catch (const std::exception& e) {
        LOG_ERROR("Exception in %s: %s", featureName, e.what());
    }
    catch (...) {
        LOG_ERROR("Unknown exception in %s", featureName);
    }
}

void HandleKey()
{
	while (!g_break) {

		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		if (GetAsyncKeyState(VK_END) & 0x8000) {
			LOG_INFO("Uninjecting...");
			g_break = true;
		}

		g_menu->HandleKey();
	}
}

void updateGlobals() 
{
	while (!g_break) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		utils::UpdateGlobals();
		UGAkStatics = (UAkGameplayStatics*)UAkGameplayStatics::StaticClass();
		KuroStaticLib = (UKuroStaticLibrary*)UKuroStaticLibrary::StaticClass();
	}
}

void handleFunctions()
{
	while (!g_break) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		if (!player_controller) {
			font_roboto = 0;
			FN_TsAnimNotifyReSkillEvent_C = 0;
		} 
		else if (!font_roboto) {
			auto font = viewport->FindObject<UFont>("Font Roboto.Roboto");
			if (font) {
				LOG_SUCCESS("Font founded!");
				font_roboto = font;
			}
		} else if (!FN_TsAnimNotifyReSkillEvent_C) {
			auto reskill = viewport->FindObject<UFunction>("Function TsAnimNotifyReSkillEvent.TsAnimNotifyReSkillEvent_C.K2_Notify");
			if (reskill) {
				LOG_SUCCESS("K2_Notify founded!");
				FN_TsAnimNotifyReSkillEvent_C = reskill->Index;
			}
		}

		if (!FN_KuroSDKEvent) {
			auto func = UObject::FindObject<UFunction>("Function KuroSDK.KuroSDKManager.KuroSDKEvent", EClassCastFlags::Function);
			if (func) {
				FN_KuroSDKEvent = func->Index;
				LOG_SUCCESS("Function KuroSDKEvent found");
			}
		}
	}
}

DWORD WINAPI MainThread(HMODULE hMod, LPVOID lpReserved)
{
	Logger::Init("Moonlight");

	if (MH_Initialize() != MH_OK) LOG_ERROR("Failed to init MinHook");
	else LOG_SUCCESS("MinHook initialized");

	Hooks::DebugBypass();

	// MUST BE INITIALIZED ABOVE -> std::vector<std::unique_ptr<std::thread>> threads
	D3D11Hook::Initialize();

	while (!FindWindowA("UnrealWindow", 0)) std::this_thread::sleep_for(std::chrono::milliseconds(100));

	std::vector<std::unique_ptr<std::thread>> threads;

	try {
		threads.emplace_back(std::make_unique<std::thread>(HandleKey));
	 	threads.emplace_back(std::make_unique<std::thread>(updateGlobals));
		threads.emplace_back(std::make_unique<std::thread>(handleFunctions));

		for (const auto& thread : threads) {
			LOG_SUCCESS("Thread created! 0x%llx", thread->get_id());
			thread->detach();
		}
	}
	catch (const std::exception& e) {
		LOG_ERROR("Failed to create threads: %s", e.what());
		throw;
	}

	Hooks::InGame::Initialize();

	LOG_INFO("Enjoy DLC!");

	while (!g_break)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));

        SafeExecute([&]() { fpsUnlock->Run(); }, "FpsUnlock");
        SafeExecute([&]() { ptpsafe->Run(); }, "TPSafe");
        SafeExecute([&]() { speedhack->Run(); }, "SpeedHack");
        SafeExecute([&]() { fly->Run(); }, "Fly");
        SafeExecute([&]() { esp->Run(); }, "ESP");
	}

	threads.clear();
	Hooks::Uninitialize();
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
		ConfigHelper::Initialize();
		break;
	case DLL_PROCESS_DETACH:
		globals::g_break = true;
		ConfigHelper::QuickSave();
		break;
	}

	return TRUE;
}