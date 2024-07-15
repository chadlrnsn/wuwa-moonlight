#pragma once
#include <iostream>	
#include <Windows.h>
#include <minhook/include/MinHook.h>

typedef HMODULE(WINAPI* LoadLibraryW_t)(LPCWSTR lpLibFileName);

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
};

HMODULE WINAPI hkLoadLibraryW(LPCWSTR libFileName);

namespace Hooks {
	void hkACE_BypassSetup();
	void hkACE_BypassCleanup();
	void RemoveHooks();
}