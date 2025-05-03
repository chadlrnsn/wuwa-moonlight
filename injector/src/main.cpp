#include "manual_map.h"
#include "injector/load_libary.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <filesystem>
#include <logger.h>

using namespace std;

std::string GetExecutablePath() {
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	return std::string(buffer);
}

bool IsCorrectTargetArchitecture(HANDLE hProc) {
	BOOL bTarget = FALSE;
	if (!IsWow64Process(hProc, &bTarget)) {
		LOG_INFO("Can't confirm target process architecture: 0x%X", GetLastError());
		return false;
	}

	BOOL bHost = FALSE;
	IsWow64Process(GetCurrentProcess(), &bHost);

	return (bTarget == bHost);
}

#ifdef UNICODE

DWORD GetProcessIdByName(const wchar_t* name) {
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry) == TRUE) {
		while (Process32Next(snapshot, &entry) == TRUE) {
			if (_wcsicmp(entry.szExeFile, name) == 0) {
				CloseHandle(snapshot);
				return entry.th32ProcessID;
			}
		}
	}

	CloseHandle(snapshot);
	return 0;
}

#else 

DWORD GetProcessIdByName(const std::string& name) {
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry) == TRUE) {
		while (Process32Next(snapshot, &entry) == TRUE) {
			if (_stricmp(entry.szExeFile, name.c_str()) == 0) {
				CloseHandle(snapshot);
				return entry.th32ProcessID;
			}
		}
	}

	CloseHandle(snapshot);
	return 0;
}

#endif

int main() {

	LOG_INFO("Simple dll injector...");

	std::string p = GetExecutablePath();
	std::filesystem::path paths(p);
	auto dllPath = paths.parent_path() / "WWMoonlight.dll";
	LOG_INFO("DLL Path: %s", dllPath.string().c_str());
	DWORD PID;
	
	LOG_INFO("Waiting for game...");

	do {
		PID = GetProcessIdByName("Client-Win64-Shipping.exe");
		Sleep(100);
	} while (PID == 0);

	if (PID == 0) {
		LOG_INFO("Process not found");
		system("pause");
		return -1;
	}

	LOG_INFO("Process pid: %d", PID);

	TOKEN_PRIVILEGES priv = { 0 };
	HANDLE hToken = NULL;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {
		priv.PrivilegeCount = 1;
		priv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

		if (LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &priv.Privileges[0].Luid))
			AdjustTokenPrivileges(hToken, FALSE, &priv, 0, NULL, NULL);

		CloseHandle(hToken);
	}

	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);
	if (!hProc) {
		DWORD Err = GetLastError();
		LOG_ERROR("OpenProcess failed: 0x%X", Err);
		system("PAUSE");
		return -2;
	}

	if (!IsCorrectTargetArchitecture(hProc)) {
		LOG_ERROR("Invalid Process Architecture.");
		CloseHandle(hProc);
		system("PAUSE");
		return -3;
	}

	if (GetFileAttributesA(dllPath.string().c_str()) == INVALID_FILE_ATTRIBUTES) {
		LOG_ERROR("Dll file doesn't exist");
		CloseHandle(hProc);
		system("PAUSE");
		return -4;
	}

	// std::ifstream File(dllPath, std::ios::binary | std::ios::ate);

	// if (File.fail()) {
	// 	LOG_ERROR("Opening the file failed: %X", (DWORD)File.rdstate());
	// 	File.close();
	// 	system("PAUSE");
	// 	return -5;
	// }

	// auto FileSize = File.tellg();
	// if (FileSize < 0x1000) {
	// 	LOG_ERROR("Filesize invalid.");
	// 	File.close();
	// 	CloseHandle(hProc);
	// 	system("PAUSE");
	// 	return -6;
	// }

	// BYTE* pSrcData = new BYTE[(UINT_PTR)FileSize];
	// if (!pSrcData) {
	// 	LOG_ERROR("Can't allocate dll file.");
	// 	File.close();
	// 	CloseHandle(hProc);
	// 	system("PAUSE");
	// 	return -7;
	// }

	// File.seekg(0, std::ios::beg);
	// File.read((char*)(pSrcData), FileSize);
	// File.close();

	// LOG_INFO("Mapping...");
	// if (!ManualMapDll(hProc, pSrcData, FileSize)) {
	// 	delete[] pSrcData;
	// 	CloseHandle(hProc);
	// 	LOG_ERROR("Error while mapping.");
	// 	LOG_ERROR("Error while mapping.");
	// 	system("PAUSE");
	// 	return -8;
	// }

	std::wstring wideDllPath = std::filesystem::path(dllPath).wstring();

	LOG_INFO("Injecting DLL using LoadLibraryW...");
	if (!LoadLibraryInject(hProc, wideDllPath)) {
		CloseHandle(hProc);
		LOG_ERROR("Error while mapping.");
		system("PAUSE");
		return -8;
	}

	CloseHandle(hProc);
	LOG_INFO("Injection successful!");
	return 0;
}