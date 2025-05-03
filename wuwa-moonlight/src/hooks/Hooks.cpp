#include "Hooks.h"

#include <includes.h>
#include <globals.h>
#include <UnrealEngineRenderer.h>
#include <MinHook.h>
#include <logger.h>
#include <Features/Features.h>

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

	    // Новый указатель для CreateThread
    typedef HANDLE (WINAPI *CreateThreadFunc)(
        LPSECURITY_ATTRIBUTES lpThreadAttributes,
        SIZE_T dwStackSize,
        LPTHREAD_START_ROUTINE lpStartAddress,
        LPVOID lpParameter,
        DWORD dwCreationFlags,
        LPDWORD lpThreadId
    );
    CreateThreadFunc oCreateThread = nullptr;

	    // Для NtCreateThreadEx
    typedef NTSTATUS (NTAPI *NtCreateThreadExFunc)(
        OUT PHANDLE ThreadHandle,
        IN ACCESS_MASK DesiredAccess,
        IN PVOID ObjectAttributes OPTIONAL,
        IN HANDLE ProcessHandle,
        IN PVOID StartRoutine,
        IN PVOID Argument OPTIONAL,
        IN ULONG CreateFlags,
        IN SIZE_T ZeroBits OPTIONAL,
        IN SIZE_T StackSize OPTIONAL,
        IN SIZE_T MaximumStackSize OPTIONAL,
        IN PVOID AttributeList OPTIONAL
    );
    NtCreateThreadExFunc oNtCreateThreadEx = nullptr;
}

HANDLE WINAPI hkCreateThread(
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    SIZE_T dwStackSize,
    LPTHREAD_START_ROUTINE lpStartAddress,
    LPVOID lpParameter,
    DWORD dwCreationFlags,
    LPDWORD lpThreadId
) {
    // Здесь можно добавить логирование или анализ создаваемых потоков
    // Например, вы можете захотеть проверить адрес начала выполнения (lpStartAddress)
    // или другие параметры, которые могут указывать на действия отладчика

    // Опционально: добавьте свою логику здесь
    // Например, вы можете проверить lpStartAddress и решить, блокировать поток или нет

    // Вызов оригинальной функции
    return originals::oCreateThread(
        lpThreadAttributes,
        dwStackSize,
        lpStartAddress,
        lpParameter,
        dwCreationFlags,
        lpThreadId
    );
}

NTSTATUS NTAPI hkNtCreateThreadEx(
    OUT PHANDLE ThreadHandle,
    IN ACCESS_MASK DesiredAccess,
    IN PVOID ObjectAttributes OPTIONAL,
    IN HANDLE ProcessHandle,
    IN PVOID StartRoutine,
    IN PVOID Argument OPTIONAL,
    IN ULONG CreateFlags,
    IN SIZE_T ZeroBits OPTIONAL,
    IN SIZE_T StackSize OPTIONAL,
    IN SIZE_T MaximumStackSize OPTIONAL,
    IN PVOID AttributeList OPTIONAL
) {
    // Можно добавить логирование или анализ создаваемых потоков
    // ProcessHandle может помочь определить, создается ли поток в текущем процессе или в другом
    
    // Вызов оригинальной функции
    return originals::oNtCreateThreadEx(
        ThreadHandle,
        DesiredAccess,
        ObjectAttributes,
        ProcessHandle,
        StartRoutine,
        Argument,
        CreateFlags,
        ZeroBits,
        StackSize,
        MaximumStackSize,
        AttributeList
    );
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
	HMODULE hKernel32 = GetModuleHandleA("kernel32.dll");

	while (!hNtdll || !hKernel32) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		hNtdll = GetModuleHandleA("ntdll.dll");
		hKernel32 = GetModuleHandleA("kernel32.dll");
	}

	LOG_INFO("Ntdll: 0x%p", hNtdll);
	LOG_INFO("hKernel32: 0x%p", hKernel32);


    if (hNtdll)
    {
        // Существующий хук для NtQueryInformationProcess
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

		// Хук для NtCreateThreadEx
        // FARPROC pNtCreateThreadEx = GetProcAddress(hNtdll, "NtCreateThreadEx");
        // if (pNtCreateThreadEx)
        // {
        //     if (MH_CreateHook(pNtCreateThreadEx, static_cast<LPVOID>(&hkNtCreateThreadEx), reinterpret_cast<LPVOID*>(&originals::oNtCreateThreadEx)) != MH_OK)
        //     {
        //         return;
        //     }
        //     if (MH_EnableHook(pNtCreateThreadEx) != MH_OK)
        //     {
        //         return;
        //     }
        // }
    }

    // if (hKernel32)
    // {
    //     // Хук для CreateThread
    //     FARPROC pCreateThread = GetProcAddress(hKernel32, "CreateThread");
    //     if (pCreateThread)
    //     {
    //         if (MH_CreateHook(pCreateThread, static_cast<LPVOID>(&hkCreateThread), reinterpret_cast<LPVOID*>(&originals::oCreateThread)) != MH_OK)
    //         {
	// 			LOG_SUCCESS("Successfully hooked CreateThread");
    //             return;
    //         }
    //         if (MH_EnableHook(pCreateThread) != MH_OK)
    //         {
    //             return;
    //         }
    //     }
    // }
    
    // Существующий хук для IsDebuggerPresent
    MH_CreateHook(static_cast<LPVOID>(&IsDebuggerPresent), static_cast<LPVOID>(&hkIsDebuggerPresent), reinterpret_cast<LPVOID*>(&originals::oIsDebuggerPresent));
    MH_EnableHook(static_cast<LPVOID>(&IsDebuggerPresent));
}

void __fastcall hkProcessEvent(UObject* caller, UFunction* function, void* params)
{
	multihit.get()->Call(caller, function, params);
	speedhack.get()->Call(caller, function, params);
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
	}

	oPostRender(viewport, canvas);
}

void Hooks::InGame::PostRender() noexcept
{
	try {
		while (true)
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

void Hooks::InGame::Initialize() noexcept
{
	try {
		PostRender();
		ProcessEvent();
	}
	catch (const std::exception &ex) {
		LOG_ERROR("Exception caught in Hooks::InGame::Initialize(): %s", ex.what());
	}
}

void Hooks::InGame::Uninitialize() noexcept
{
	try {
		MH_STATUS status;

		status = MH_DisableHook(static_cast<LPVOID>(&hkPostRender)); 
		if (status != MH_OK) {
			LOG_ERROR("Hooks::InGame::Uninitialize: %s", MH_StatusToString(status));
		}

		status = MH_DisableHook(static_cast<LPVOID>(&hkProcessEvent));
		if (status != MH_OK) {
			LOG_ERROR("Hooks::InGame::Uninitialize: %s", MH_StatusToString(status));
		}

		LOG_SUCCESS("Hooks::InGame::Uninitialize: Succesfully disabled InGame hooks.");
	}
	catch (const std::exception &ex) {
		LOG_ERROR("Exception caught in Hooks::InGame::Initialize(): %s", ex.what());
	}
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