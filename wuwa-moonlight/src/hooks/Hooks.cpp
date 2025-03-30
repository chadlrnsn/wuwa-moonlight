#include "Hooks.h"

#include <includes.h>
#include <globals.h>
#include <Features/Features.h>
#include <UnrealEngineRenderer.h>
#include <MinHook.h>

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
	try {
		for (const auto& dll : blockedDlls)
		{
			if (wcsstr(libFileName, dll) != nullptr)
			{
				// Используем printf вместо шифрованных строк для предотвращения проблем компиляции
                // В будущем можно включить шифрование после настройки компиляции
				printf("Blocked dll: %ws\n", libFileName);
				return nullptr;
			}
		}
	}
	catch (...) {
		// Обработка ошибок
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
		try {
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
		catch (...) {
			// Обработка ошибок
		}
	}

	return status;
}

bool Hooks::hkACE_BypassSetup() noexcept
{
	try {
		if (MH_CreateHook(static_cast<LPVOID>(&LoadLibraryW), static_cast<LPVOID>(&hkLoadLibraryW), reinterpret_cast<LPVOID*>(&originals::oLoadLibraryW)) != MH_OK)
			return false;
	
		if (MH_EnableHook(static_cast<LPVOID>(&LoadLibraryW)) != MH_OK)
			return false;
	}
	catch (...) {
		return false;
	}
		
	return true;
}

void Hooks::hkACE_BypassCleanup() noexcept
{
	try {
		MH_DisableHook(static_cast<LPVOID>(&LoadLibraryW));
		MH_Uninitialize();
	}
	catch (...) {
		// Обработка ошибок
	}
}

void Hooks::AntiDebug() noexcept
{
	try {
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
	catch (...) {
		// Обработка ошибок
	}
}

void __fastcall hkProcessEvent(UObject* caller, UFunction* function, void* params)
{
	try {
		// printf("%s %s\n", caller->GetFullName().c_str(), function->GetFullName().c_str());

		if (config::multihit::enabled)
			multihit.Call(caller, function, params, oProcessEvent);
		// if (config::godmode::enabled)
			// godmode.Call(caller, function, params, oProcessEvent);

		speedhack.Call(caller, function, params, oProcessEvent);
	}
	catch (...) {
		// Обработка ошибок
	}

	oProcessEvent(caller, function, params);
}

void Hooks::InGame::ProcessEvent() noexcept
{
	try {
		void* ProcessEventAddr = reinterpret_cast<void*>(InSDKUtils::GetImageBase() + SDK::Offsets::ProcessEvent);
		printf("ProcessEvent address: %p\n", ProcessEventAddr);

		while (true)
		{
			if ((InSDKUtils::GetImageBase() + SDK::Offsets::ProcessEvent) <= InSDKUtils::GetImageBase())
			{
				printf("Invalid ProcessEvent address\n");
				break;
			}

			printf("Trying to hook ProcessEvent at %p\n", ProcessEventAddr);

			MH_STATUS status = MH_CreateHook(ProcessEventAddr, static_cast<LPVOID>(&hkProcessEvent), reinterpret_cast<LPVOID*>(&oProcessEvent));
			if (status != MH_OK)
			{
				printf("Failed to create hook: %s\n", MH_StatusToString(status));

				std::this_thread::sleep_for(std::chrono::seconds(1));
				continue;
			}

			status = MH_EnableHook(ProcessEventAddr);
			if (status != MH_OK)
			{
				printf("Failed to enable hook: %s\n", MH_StatusToString(status));
				std::this_thread::sleep_for(std::chrono::seconds(1));
				continue;
			}

			printf("ProcessEvent hook created and enabled successfully\n");
			break;
		}
	}
	catch (...) {
		// Обработка ошибок
	}
}

void __fastcall hkPostRender(UGameViewportClient* viewport, UCanvas* canvas)
{
	try {
		if (canvas && engine)
		{
			ue4::UE_RenderText(canvas, engine->SmallFont, L"Moonlight", { 10, 10 }, { 1, 1 }, FLinearColor(1, 1, 1, 1));
			// if (config::esp::enable)
			// esp.Render(canvas);
		}
	}
	catch (...) {
		// Обработка ошибок
	}

	oPostRender(viewport, canvas);
}

void Hooks::InGame::PostRender() noexcept
{
	try {
		while (true)
		{
			UEngine* Engine = UEngine::GetEngine();
			if (!Engine)
			{
				printf("Failed to get Engine instance\n");
				Sleep(1000);
				continue;
			}

			UGameViewportClient* Viewport = Engine->GameViewport;
			if (!Viewport)
			{
				printf("Failed to get GameViewport\n");
				Sleep(1000);
				continue;
			}

			printf("GameViewport found: %p\n", static_cast<void*>(Viewport));

			void** VTable = *reinterpret_cast<void***>(Viewport);
			const size_t PostRenderIndex = 105;
			void* PostRenderAddress = VTable[PostRenderIndex];

			MH_STATUS status = MH_CreateHook(PostRenderAddress, static_cast<LPVOID>(&hkPostRender), reinterpret_cast<LPVOID*>(&oPostRender));
			if (status != MH_OK)
			{
				printf("Failed to create hook PostRender: %s\n", MH_StatusToString(status));
				Sleep(1000);
				continue;
			}

			status = MH_EnableHook(PostRenderAddress);
			if (status != MH_OK)
			{
				printf("Failed to enable hook PostRender: %s\n", MH_StatusToString(status));
				Sleep(1000);
				continue;
			}

			printf("PostRender hooked successfully: %p\n", PostRenderAddress);
			return;
		}
	}
	catch (...) {
		// Обработка ошибок
	}
}

void Hooks::InGame::Initialize() noexcept
{
	try {
		PostRender();
		ProcessEvent();
	}
	catch (...) {
		// Обработка ошибок
	}
}

void Hooks::RemoveHooks() noexcept
{
	try {
		MH_DisableHook(MH_ALL_HOOKS);
		MH_RemoveHook(MH_ALL_HOOKS);
		MH_Uninitialize();
	}
	catch (...) {
		// Обработка ошибок
	}
}