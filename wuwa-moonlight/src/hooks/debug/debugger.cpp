#include "debugger.hpp"


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

    typedef HANDLE (WINAPI *CreateThreadFunc)(
        LPSECURITY_ATTRIBUTES lpThreadAttributes,
        SIZE_T dwStackSize,
        LPTHREAD_START_ROUTINE lpStartAddress,
        LPVOID lpParameter,
        DWORD dwCreationFlags,
        LPDWORD lpThreadId
    );
    CreateThreadFunc oCreateThread = nullptr;

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


void Hooks::DebugBypass()
{
    HMODULE hNtdll = NULL;
	HMODULE hKernel32 = NULL;
	MH_STATUS status;

	while (!hNtdll || !hKernel32) { 
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		if (globals::g_break) break;
		hNtdll = GetModuleHandleA("ntdll.dll");
		hKernel32 = GetModuleHandleA("kernel32.dll");
	}

	LOG_INFO("Ntdll: 0x%p", hNtdll);
	LOG_INFO("hKernel32: 0x%p", hKernel32);


    if (hNtdll)
    {
        FARPROC pNtQueryInformationProcess = GetProcAddress(hNtdll, "NtQueryInformationProcess");
        if (pNtQueryInformationProcess)
        {
			status = MH_CreateHook(pNtQueryInformationProcess, static_cast<LPVOID>(&hkNtQueryInformationProcess), reinterpret_cast<LPVOID*>(&originals::oNtQueryInformationProcess));
            if (status != MH_OK)
            {
				LOG_ERROR("NtQueryInformationProcess hook error: %s", MH_StatusToString(status));
                return;
            }
			status = MH_EnableHook(pNtQueryInformationProcess);
            if (status != MH_OK)
            {
				LOG_ERROR("NtQueryInformationProcess enable hook error: %s", MH_StatusToString(status));
                return;
            }
        }

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

    if (hKernel32)
    {
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

		status = MH_CreateHook(static_cast<LPVOID>(&LoadLibraryW), static_cast<LPVOID>(&hkLoadLibraryW), reinterpret_cast<LPVOID*>(&originals::oLoadLibraryW));
		if (status != MH_OK)
		{
			LOG_ERROR("LoadLibraryW create hook error: %s", MH_StatusToString(status));
		}

		status = MH_EnableHook(static_cast<LPVOID>(&LoadLibraryW));
		if (status != MH_OK)
		{
			LOG_ERROR("LoadlibraryW enable hook error");
		}

		status = MH_CreateHook(static_cast<LPVOID>(&IsDebuggerPresent), static_cast<LPVOID>(&hkIsDebuggerPresent), reinterpret_cast<LPVOID*>(&originals::oIsDebuggerPresent));
		if (status != MH_OK)
		{
			LOG_ERROR("IsDebuggerPresent create hook error: %s", MH_StatusToString(status));
		}
		status = MH_EnableHook(static_cast<LPVOID>(&IsDebuggerPresent));
		if (status != MH_OK)
		{
			LOG_ERROR("IsDebuggerPresent enable hook error: %s", MH_StatusToString(status));
		}
    }
}

void Hooks::DebugBypassDisable()
{
    // idont care about status 
    MH_STATUS status;
    
    status = MH_DisableHook(static_cast<LPVOID>(&hkLoadLibraryW));
    if (status != MH_OK)
    {
        LOG_ERROR("LoadLibraryW disable hook error: %s", MH_StatusToString(status));
    }

    status = MH_DisableHook(static_cast<LPVOID>(&hkIsDebuggerPresent));
    if (status != MH_OK) 
    {
        LOG_ERROR("IsDebuggerPresent disable hook error: %s", MH_StatusToString(status));
    }

    status = MH_DisableHook(static_cast<LPVOID>(&hkNtQueryInformationProcess));
    if (status != MH_OK)
    {
        LOG_ERROR("NtQueryInformationProcess disable hook error: %s", MH_StatusToString(status));
    }
    // MH_DisableHook(static_cast<LPVOID>(&hk));
    // MH_DisableHook(static_cast<LPVOID>(&));

    status = MH_RemoveHook(static_cast<LPVOID>(&hkLoadLibraryW));
    if (status != MH_OK)
    {
        LOG_ERROR("LoadLibraryW remove hook error: %s", MH_StatusToString(status));
    }

    status = MH_RemoveHook(static_cast<LPVOID>(&hkIsDebuggerPresent));
    if (status != MH_OK)
    {
        LOG_ERROR("IsDebuggerPresent remove hook error: %s", MH_StatusToString(status));
    }

    status = MH_RemoveHook(static_cast<LPVOID>(&hkNtQueryInformationProcess));
    if (status != MH_OK)
    {
        LOG_ERROR("NtQueryInformationProcess remove hook error: %s", MH_StatusToString(status));
    }
    // MH_RemoveHook(static_cast<LPVOID>(&hk));
    // MH_RemoveHook(static_cast<LPVOID>(&));
}