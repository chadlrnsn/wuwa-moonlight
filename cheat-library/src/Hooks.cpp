#include "Hooks.h"
#ifndef ProcessDebugFlags
#define ProcessDebugFlags ((PROCESSINFOCLASS)31)
#endif

#ifndef ProcessDebugObjectHandle
#define ProcessDebugObjectHandle ((PROCESSINFOCLASS)30)
#endif

namespace originals {
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
#else
			printf("Blocked anticheat dll: %s", dll);
#endif
			return nullptr;
		}
	}

	return originals::oLoadLibraryW(libFileName);
}

BOOL __stdcall hkIsDebuggerPresent() {
	return FALSE;
}

NTSTATUS NTAPI hkNtQueryInformationProcess(
	HANDLE ProcessHandle,
	PROCESSINFOCLASS ProcessInformationClass,
	PVOID ProcessInformation,
	ULONG ProcessInformationLength,
	PULONG ReturnLength
) {
	NTSTATUS status = originals::oNtQueryInformationProcess(ProcessHandle, ProcessInformationClass, ProcessInformation, ProcessInformationLength, ReturnLength);

	if (NT_SUCCESS(status)) {
		switch (ProcessInformationClass) {
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
	if (MH_Initialize() != MH_OK) {
		return;
	}

	if (MH_CreateHook(&LoadLibraryW, &hkLoadLibraryW, reinterpret_cast<LPVOID*>(&originals::oLoadLibraryW)) != MH_OK) {
		return;
	}

	if (MH_EnableHook(&LoadLibraryW) != MH_OK) {
		return;
	}
}

void Hooks::hkACE_BypassCleanup()
{
	MH_DisableHook(&LoadLibraryW);
	MH_Uninitialize();
}

void Hooks::AntiDebug()
{
	if (MH_Initialize() != MH_OK) {
		return;
	}

	HMODULE hNtdll = GetModuleHandleA("ntdll.dll");
	if (hNtdll) {
		FARPROC pNtQueryInformationProcess = GetProcAddress(hNtdll, "NtQueryInformationProcess");
		if (pNtQueryInformationProcess) 
		{
			if (MH_CreateHook(pNtQueryInformationProcess, &hkNtQueryInformationProcess, reinterpret_cast<LPVOID*>(&originals::oNtQueryInformationProcess)) != MH_OK) {
				return;
			}

			if (MH_EnableHook(pNtQueryInformationProcess) != MH_OK) {
				return;
			}
		}
	}

	if (MH_CreateHook(&IsDebuggerPresent, &hkIsDebuggerPresent, reinterpret_cast<LPVOID*>(&originals::oIsDebuggerPresent)) != MH_OK) {
		return;
	}

	if (MH_EnableHook(&IsDebuggerPresent) != MH_OK) {
		return;
	}
}

void Hooks::RemoveHooks() {
	MH_DisableHook(MH_ALL_HOOKS);
	MH_RemoveHook(MH_ALL_HOOKS);
	MH_Uninitialize();
}