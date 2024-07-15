#include "Hooks.h"

namespace originals {
	LoadLibraryW_t oLoadLibraryW = nullptr;
}


/* Anti-AntiCheat */
HMODULE WINAPI hkLoadLibraryW(LPCWSTR libFileName)
{
	for (LPCWSTR dll : blockedDlls)
	{
		if (wcsstr(libFileName, dll) != 0)
		{
			std::wcout << "Blocked dll: " << dll << std::endl;
			return nullptr;
		}
	}

	return originals::oLoadLibraryW(libFileName);
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

void Hooks::RemoveHooks() {
	MH_DisableHook(MH_ALL_HOOKS);
	MH_RemoveHook(MH_ALL_HOOKS);
	MH_Uninitialize();
}