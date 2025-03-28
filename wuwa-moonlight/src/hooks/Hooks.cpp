#include "Hooks.h"

#include <includes.h>
#include <globals.h>
#include <Features/Features.h>
#include <UnrealEngineRenderer.h>
#include <Minhook.h>

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
HMODULE WINAPI hkLoadLibraryW(LPCWSTR libFileName)
{
	for (LPCWSTR dll : blockedDlls)
	{
		if (wcsstr(libFileName, dll) != 0)
		{
#ifdef _DEBUG
			std::wcout << "Blocked dll: " << dll << std::endl;
#endif
			return nullptr;
		}
	}

	return originals::oLoadLibraryW(libFileName);
}

BOOL __stdcall hkIsDebuggerPresent()
{
	return FALSE;
}

NTSTATUS NTAPI hkNtQueryInformationProcess(
	HANDLE ProcessHandle,
	PROCESSINFOCLASS ProcessInformationClass,
	PVOID ProcessInformation,
	ULONG ProcessInformationLength,
	PULONG ReturnLength)
{
	NTSTATUS status = originals::oNtQueryInformationProcess(ProcessHandle, ProcessInformationClass, ProcessInformation, ProcessInformationLength, ReturnLength);

	if (NT_SUCCESS(status))
	{
		switch (ProcessInformationClass)
		{
		case ProcessDebugPort: // 7
			*(PHANDLE)ProcessInformation = NULL;
			break;
		case ProcessDebugFlags: // 31
			*(PULONG)ProcessInformation = 1;
			break;
		case ProcessDebugObjectHandle: // 30
			*(PHANDLE)ProcessInformation = NULL;
			break;
		}
	}

	return status;
}

void Hooks::hkACE_BypassSetup()
{
	MH_CreateHook(&LoadLibraryW, &hkLoadLibraryW, reinterpret_cast<LPVOID*>(&originals::oLoadLibraryW));
	MH_EnableHook(&LoadLibraryW);
}

void Hooks::hkACE_BypassCleanup()
{
	MH_DisableHook(&LoadLibraryW);
	MH_Uninitialize();
}

void Hooks::AntiDebug()
{
	HMODULE hNtdll = GetModuleHandleA("ntdll.dll");
	if (hNtdll)
	{
		FARPROC pNtQueryInformationProcess = GetProcAddress(hNtdll, "NtQueryInformationProcess");
		if (pNtQueryInformationProcess)
		{
			if (MH_CreateHook(pNtQueryInformationProcess, &hkNtQueryInformationProcess, reinterpret_cast<LPVOID*>(&originals::oNtQueryInformationProcess)) != MH_OK)
			{
				return;
			}

			if (MH_EnableHook(pNtQueryInformationProcess) != MH_OK)
			{
				return;
			}
		}
	}

	MH_CreateHook(&IsDebuggerPresent, &hkIsDebuggerPresent, reinterpret_cast<LPVOID*>(&originals::oIsDebuggerPresent));
	MH_EnableHook(&IsDebuggerPresent);
}

void __fastcall hkProcessEvent(UObject* caller, UFunction* function, void* params)
{

	// printf("%s %s\n", caller->GetFullName().c_str(), function->GetFullName().c_str());

	if (config::multihit::enabled)
		multihit.Call(caller, function, params, oProcessEvent);
	// if (config::godmode::enabled)
		// godmode.Call(caller, function, params, oProcessEvent);

	speedhack.Call(caller, function, params, oProcessEvent);

	oProcessEvent(caller, function, params);
}

void Hooks::InGame::ProcessEvent()
{
	void* ProcessEventAddr = reinterpret_cast<void*>(InSDKUtils::GetImageBase() + SDK::Offsets::ProcessEvent);
	printf("ProcessEvent address: %llx\n", ProcessEventAddr);

	while (true)
	{
		if ((InSDKUtils::GetImageBase() + SDK::Offsets::ProcessEvent) <= InSDKUtils::GetImageBase())
		{
			printf("Invalid ProcessEvent address\n");
			break;
		}

		printf("Trying to hook ProcessEvent at %llx\n", ProcessEventAddr);

		MH_STATUS status = MH_CreateHook(ProcessEventAddr, &hkProcessEvent, reinterpret_cast<LPVOID*>(&oProcessEvent));
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

void __fastcall hkPostRender(UGameViewportClient* viewport, UCanvas* canvas)
{

	if (canvas && engine)
	{
		ue4::UE_RenderText(canvas, engine->SmallFont, L"Moonlight", { 10, 10 }, { 1, 1 }, FLinearColor(1, 1, 1, 1));
		// if (config::esp::enable)
		// esp.Render(canvas);
	}

	oPostRender(viewport, canvas);
}

void Hooks::InGame::PostRender()
{
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

		printf("GameViewport found: %llx\n", (uintptr_t)Viewport);

		void** VTable = *reinterpret_cast<void***>(Viewport);
		const size_t PostRenderIndex = 105;
		void* PostRenderAddress = VTable[PostRenderIndex];

		MH_STATUS status = MH_CreateHook(PostRenderAddress, &hkPostRender, reinterpret_cast<LPVOID*>(&oPostRender));
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

		printf("PostRender hooked successfully: %llx\n", (uintptr_t)PostRenderAddress);
		return;
	}
}

void Hooks::InGame::Initialize()
{
	PostRender();
	ProcessEvent();
}

void Hooks::RemoveHooks()
{
	MH_DisableHook(MH_ALL_HOOKS);
	MH_RemoveHook(MH_ALL_HOOKS);
	MH_Uninitialize();
}