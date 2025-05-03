#pragma once
#include <windows.h>
#include <MinHook.h>
#include <winternl.h>
#include <globals.h>

using LoadLibraryW_t = HMODULE(WINAPI*)(LPCWSTR lpLibFileName);
using IsDebuggerPresent_t = BOOL(WINAPI*)();
using NtQueryInformationProcess_t = NTSTATUS(NTAPI*)(
	HANDLE ProcessHandle,
	PROCESSINFOCLASS ProcessInformationClass,
	PVOID ProcessInformation,
	ULONG ProcessInformationLength,
	PULONG ReturnLength
);

constexpr LPCWSTR blockedDlls[] = {
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

HMODULE WINAPI hkLoadLibraryW(LPCWSTR libFileName) noexcept;
BOOL WINAPI hkIsDebuggerPresent() noexcept;
NTSTATUS NTAPI hkNtQueryInformationProcess(
	HANDLE ProcessHandle,
	PROCESSINFOCLASS ProcessInformationClass,
	PVOID ProcessInformation,
	ULONG ProcessInformationLength,
	PULONG ReturnLength
) noexcept;

namespace Hooks {
    void DebugBypass();
    void DebugBypassDisable();
}