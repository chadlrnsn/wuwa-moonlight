#pragma once
#include <iostream>	
#include <Windows.h>
#include <Minhook.h>
#include <winternl.h>

typedef HMODULE(WINAPI* LoadLibraryW_t)(LPCWSTR lpLibFileName);
typedef BOOL(WINAPI* IsDebuggerPresent_t)();
typedef NTSTATUS(NTAPI* NtQueryInformationProcess_t)(
	HANDLE ProcessHandle,
	PROCESSINFOCLASS ProcessInformationClass,
	PVOID ProcessInformation,
	ULONG ProcessInformationLength,
	PULONG ReturnLength
	);


/* Blocks ACE (special thanks to @rottingexistence) */
const LPCWSTR blockedDlls[] = {
	L"ACE-Base64.dll",
	L"ACE-SSC64.dll",
	L"ACE-DRV64.dll",
	L"ACE-DFS64.dll",
	L"ACE-CSI64.dll",
	L"ACE-ATS64.dll",
	L"ACE-IDS64.dll",
	L"ACE-Trace.dll",
	L"ACE-Safe.dll",
	L"ACE-Tips64.dll",
	L"SGuardAgent64.dll",
	L"CrashSight64.dll",
	L"PerfSight.dll",
};

HMODULE WINAPI hkLoadLibraryW(LPCWSTR libFileName);

// Anti-AntiDebug
BOOL WINAPI hkIsDebuggerPresent();

NTSTATUS NTAPI hkNtQueryInformationProcess(
	HANDLE ProcessHandle,
	PROCESSINFOCLASS ProcessInformationClass,
	PVOID ProcessInformation,
	ULONG ProcessInformationLength,
	PULONG ReturnLength
);

namespace Hooks {
	void hkACE_BypassSetup();
	void hkACE_BypassCleanup();
	void AntiDebug();
	void RemoveHooks();

	namespace InGame {
		void PostRender();
		void ProcessEvent();
		void Initialize();
	}
}