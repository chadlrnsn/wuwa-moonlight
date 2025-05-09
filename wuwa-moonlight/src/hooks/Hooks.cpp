#include "Hooks.h"

#include <includes.h>
#include <globals.h>
#include <UnrealEngineRenderer.h>
#include <MinHook.h>
#include <logger.h>
#include <Features/Features.h>
#include <d3d11hook.h>
#include <KuroSDK_parameters.hpp>

using namespace globals;
using namespace SDK;


void __fastcall hkProcessEvent(UObject* caller, UFunction* function, void* params)
{
	multihit->Call(caller, function, params);
	speedhack->Call(caller, function, params);
	oProcessEvent(caller, function, params);
}

void Hooks::InGame::ProcessEvent()
{
	try {
		void* ProcessEventAddr = reinterpret_cast<void*>(InSDKUtils::GetImageBase() + SDK::Offsets::ProcessEvent);
		original_ProcessEvent = ProcessEventAddr;
		LOG_INFO("ProcessEvent address: %p", ProcessEventAddr);

		while (!globals::g_break)
		{
			if ((InSDKUtils::GetImageBase() + SDK::Offsets::ProcessEvent) <= InSDKUtils::GetImageBase())
			{
				LOG_INFO("Invalid ProcessEvent address");
				break;
			}

			LOG_INFO("Trying to hook ProcessEvent at %p", ProcessEventAddr);

			MH_STATUS status = MH_CreateHook(ProcessEventAddr, static_cast<LPVOID>(&hkProcessEvent), reinterpret_cast<LPVOID*>(&oProcessEvent));
			if (status != MH_OK)
			{
				LOG_INFO("Failed to create hook: %s", MH_StatusToString(status));

				std::this_thread::sleep_for(std::chrono::seconds(1));
				continue;
			}

			status = MH_EnableHook(ProcessEventAddr);
			if (status != MH_OK)
			{
				LOG_INFO("Failed to enable hook: %s", MH_StatusToString(status));
				std::this_thread::sleep_for(std::chrono::seconds(1));
				continue;
			}

			LOG_INFO("ProcessEvent hook created and enabled successfully");
			break;
		}
	}
	catch (...) {}
}

void hkPostRender(UGameViewportClient* viewport, UCanvas* canvas)
{
	if (canvas)
	{
		ue4::UE_RenderText(canvas, globals::font_roboto, L"Moonlight", { 10, 10 }, { 1, 1 }, FLinearColor(1, 1, 1, 1));
	}

	oPostRender(viewport, canvas);
}

void Hooks::InGame::PostRender()
{
	try {
		while (!globals::g_break)
		{
			//auto Engine = UEngine::GetEngine();
			//if (!Engine)
			//{
			//	LOG_INFO("Failed to get Engine instance");
			//	Sleep(1000);
			//	continue;
			//}
 

			//auto World = UWorld::GetWorld();
			//if (!World)
			//{
			//	LOG_INFO("Failed to get World instance");
			//	Sleep(1000);
			//	continue;
			//}

			//auto GameInstance = World->OwningGameInstance;
			//if (!GameInstance)
			//{
			//	LOG_INFO("Failed to get GameInstance");
			//	Sleep(1000);
			//	continue;
			//}

			//auto localPlayers = GameInstance->LocalPlayers;
			//if (!localPlayers)
			//{
			//	LOG_INFO("Failed to get LocalPlayers");
			//	Sleep(1000);
			//	continue;
			//}

			//auto EViewPort = Engine->GameViewport;
			//if (!EViewPort)
			//{
			//	LOG_INFO("Failed to get EViewPort");
			//	Sleep(1000);
			//	continue;
			//}
			if (!engine) return LOG_WARN("No Engine");

			auto Viewport = engine->GameViewport;
			if (!Viewport)
			{
				LOG_INFO("Failed to get Viewport");
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				continue;
			}

			//LOG_INFO("EGameViewPort found: %p", (uintptr_t)EViewPort);
			LOG_SUCCESS("GameViewport found: %p", (uintptr_t)Viewport);

			void** VTable = *reinterpret_cast<void***>(Viewport);
			const int PostRenderIndex = 0x69;
			void* PostRenderAddress = VTable[PostRenderIndex];
			original_PostRender = PostRenderAddress;

			MH_STATUS status = MH_CreateHook(PostRenderAddress, static_cast<LPVOID>(&hkPostRender), reinterpret_cast<LPVOID*>(&oPostRender));
			if (status != MH_OK)
			{
				LOG_ERROR("Failed to create hook PostRender: %s", MH_StatusToString(status));
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				continue;
			}

			status = MH_EnableHook(PostRenderAddress);
			if (status != MH_OK)
			{
				LOG_ERROR("Failed to enable hook PostRender: %s", MH_StatusToString(status));
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				continue;
			}

			LOG_SUCCESS("PostRender hooked successfully: %p", PostRenderAddress);
			return;
		}
	}
	catch (...) {}
}

void Hooks::InGame::Initialize()
{
	try {
		PostRender();
		ProcessEvent();
	}
	catch (const std::exception &ex) {
		LOG_ERROR("Exception caught in Hooks::InGame::Initialize(): %s", ex.what());
	}
}

void Hooks::InGame::Uninitialize()
{
	MH_STATUS status;
	try {
		// Отключаем хук PostRender
		if (original_PostRender != nullptr) {
			status = MH_DisableHook(original_PostRender);
			if (status != MH_OK) {
				LOG_ERROR("Failed to disable PostRender hook: %s", MH_StatusToString(status));
			} else {
				LOG_SUCCESS("PostRender hook disabled successfully");
			}
			
			status = MH_RemoveHook(original_PostRender);
			if (status != MH_OK) {
				LOG_ERROR("Failed to remove PostRender hook: %s", MH_StatusToString(status));
			} else {
				LOG_SUCCESS("PostRender hook removed successfully");
			}
		}
		
		// Отключаем хук ProcessEvent
		if (original_ProcessEvent != nullptr) {
			status = MH_DisableHook(original_ProcessEvent);
			if (status != MH_OK) {
				LOG_ERROR("Failed to disable ProcessEvent hook: %s", MH_StatusToString(status));
			} else {
				LOG_SUCCESS("ProcessEvent hook disabled successfully");
			}
			
			status = MH_RemoveHook(original_ProcessEvent);
			if (status != MH_OK) {
				LOG_ERROR("Failed to remove ProcessEvent hook: %s", MH_StatusToString(status));
			} else {
				LOG_SUCCESS("ProcessEvent hook removed successfully");
			}
		}
		
		LOG_SUCCESS("InGame hooks successfully removed.");
	}
	catch (const std::exception &ex) {
		LOG_ERROR("Exception caught in Hooks::InGame::Uninitialize(): %s", ex.what());
	}
}

void Hooks::Uninitialize()
{
	Hooks::InGame::Uninitialize();
	Hooks::DebugBypassDisable();
	D3D11Hook::Uninitialize();

	MH_STATUS status = MH_Uninitialize();
	if (status != MH_OK)
	{
		LOG_ERROR("Failed to uninitialize MinHook: %s", MH_StatusToString(status));
		return;
	}

	LOG_SUCCESS("MinHook uninitialized successfully");
}
