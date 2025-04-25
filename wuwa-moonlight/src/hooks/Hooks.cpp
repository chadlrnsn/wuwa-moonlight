#include "Hooks.h"

#include <includes.h>
#include <globals.h>
#include <UnrealEngineRenderer.h>
#include <MinHook.h>
#include <logger.h>

using namespace globals;
using namespace SDK;

#ifndef ProcessDebugFlags
#define ProcessDebugFlags ((PROCESSINFOCLASS)31)
#endif

#ifndef ProcessDebugObjectHandle
#define ProcessDebugObjectHandle ((PROCESSINFOCLASS)30)
#endif

namespace originals
{
	LoadLibraryW_t oLoadLibraryW = nullptr;
	IsDebuggerPresent_t oIsDebuggerPresent = nullptr;
	NtQueryInformationProcess_t oNtQueryInformationProcess = nullptr;
}

/* Anti-AntiCheat */
HMODULE WINAPI hkLoadLibraryW(LPCWSTR libFileName) noexcept
{
	for (const auto& dll : blockedDlls)
	{
		if (wcsstr(libFileName, dll) != nullptr)
		{
			LOG_INFO("Blocked dll: %ws", libFileName);
			return nullptr;
		}
	}

	return originals::oLoadLibraryW(libFileName);
}

BOOL WINAPI hkIsDebuggerPresent() noexcept
{
	return FALSE;
}

NTSTATUS NTAPI hkNtQueryInformationProcess(
	HANDLE ProcessHandle,
	PROCESSINFOCLASS ProcessInformationClass,
	PVOID ProcessInformation,
	ULONG ProcessInformationLength,
	PULONG ReturnLength) noexcept
{
	NTSTATUS status = originals::oNtQueryInformationProcess(ProcessHandle, ProcessInformationClass, ProcessInformation, ProcessInformationLength, ReturnLength);

	if (NT_SUCCESS(status))
	{
		switch (ProcessInformationClass)
		{
		case ProcessDebugPort: // 7
			*static_cast<PHANDLE>(ProcessInformation) = nullptr;
			break;
		case ProcessDebugFlags: // 31
			*static_cast<PULONG>(ProcessInformation) = 1;
			break;
		case ProcessDebugObjectHandle: // 30
			*static_cast<PHANDLE>(ProcessInformation) = nullptr;
			break;
		}
	}

	return status;
}

bool Hooks::hkACE_BypassSetup() noexcept
{
	if (MH_CreateHook(static_cast<LPVOID>(&LoadLibraryW), static_cast<LPVOID>(&hkLoadLibraryW), reinterpret_cast<LPVOID*>(&originals::oLoadLibraryW)) != MH_OK)
		return false;

	if (MH_EnableHook(static_cast<LPVOID>(&LoadLibraryW)) != MH_OK)
		return false;

	return true;
}

void Hooks::hkACE_BypassCleanup() noexcept
{
	MH_DisableHook(static_cast<LPVOID>(&LoadLibraryW));
	MH_Uninitialize();
}

void Hooks::AntiDebug() noexcept
{
	HMODULE hNtdll = GetModuleHandleA("ntdll.dll");
	if (hNtdll)
	{
		FARPROC pNtQueryInformationProcess = GetProcAddress(hNtdll, "NtQueryInformationProcess");
		if (pNtQueryInformationProcess)
		{
			if (MH_CreateHook(pNtQueryInformationProcess, static_cast<LPVOID>(&hkNtQueryInformationProcess), reinterpret_cast<LPVOID*>(&originals::oNtQueryInformationProcess)) != MH_OK)
			{
				return;
			}

			if (MH_EnableHook(pNtQueryInformationProcess) != MH_OK)
			{
				return;
			}
		}
	}

	MH_CreateHook(static_cast<LPVOID>(&IsDebuggerPresent), static_cast<LPVOID>(&hkIsDebuggerPresent), reinterpret_cast<LPVOID*>(&originals::oIsDebuggerPresent));
	MH_EnableHook(static_cast<LPVOID>(&IsDebuggerPresent));
}

void __fastcall hkProcessEvent(UObject* caller, UFunction* function, void* params)
{
	// if (config::multihit::enabled)
	// 	multihit.Call(caller, function, params, oProcessEvent);

	oProcessEvent(caller, function, params);
}

void Hooks::InGame::ProcessEvent() noexcept
{
	try {
		void* ProcessEventAddr = reinterpret_cast<void*>(InSDKUtils::GetImageBase() + SDK::Offsets::ProcessEvent);
		LOG_INFO("ProcessEvent address: %p", ProcessEventAddr);

		while (true)
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
	catch (...) {
		// Обработка ошибок
	}
}

void hkPostRender(UGameViewportClient* viewport, UCanvas* canvas)
{
	if (canvas && engine)
	{
		ue4::UE_RenderText(canvas, engine->SmallFont, L"Moonlight", { 10, 10 }, { 1, 1 }, FLinearColor(1, 1, 1, 1));
		// if (config::esp::enable)
		// esp.Render(canvas);
	}

	oPostRender(viewport, canvas);
}

void Hooks::InGame::PostRender() noexcept
{
	try {
		while (true)
		{
			auto Engine = UEngine::GetEngine();
			if (!Engine)
			{
				LOG_INFO("Failed to get Engine instance");
				Sleep(1000);
				continue;
			}

			

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

			auto Viewport = Engine->GameViewport;
			if (!Viewport)
			{
				LOG_INFO("Failed to get Viewport");
				Sleep(1000);
				continue;
			}

			//LOG_INFO("EGameViewPort found: %p", (uintptr_t)EViewPort);
			LOG_INFO("GameViewport found: %p", (uintptr_t)Viewport);

			void** VTable = *reinterpret_cast<void***>(Viewport);
			const int PostRenderIndex = 0x69;
			void* PostRenderAddress = VTable[PostRenderIndex];

			MH_STATUS status = MH_CreateHook(PostRenderAddress, static_cast<LPVOID>(&hkPostRender), reinterpret_cast<LPVOID*>(&oPostRender));
			if (status != MH_OK)
			{
				LOG_INFO("Failed to create hook PostRender: %s", MH_StatusToString(status));
				Sleep(1000);
				continue;
			}

			status = MH_EnableHook(PostRenderAddress);
			if (status != MH_OK)
			{
				LOG_INFO("Failed to enable hook PostRender: %s", MH_StatusToString(status));
				Sleep(1000);
				continue;
			}

			LOG_INFO("PostRender hooked successfully: %p", PostRenderAddress);
			return;
		}
	}
	catch (...) {}
}

void Hooks::InGame::Initialize() noexcept
{
	try {
		PostRender();
		ProcessEvent();
	}
	catch (...) {}
}

void Hooks::RemoveHooks() noexcept
{
	try {
		MH_DisableHook(MH_ALL_HOOKS);
		MH_RemoveHook(MH_ALL_HOOKS);
		MH_Uninitialize();
	}
	catch (...) {}
}