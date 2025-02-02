#include "manual_map.h"
#include "injector/load_libary.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <filesystem>
#include <logger.h>
#include <psapi.h>
#include <algorithm> // Для работы с transform

using namespace std;

// Перечисление для типов инжекта
enum class InjectType {
	LoadLibrary,
	ManualMap,
	EarlyManualMap
};

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

// Функция для мониторинга создания нового процесса
DWORD WaitForProcessCreation(const std::string& processName, DWORD* outPID = nullptr) {
	DWORD pid = 0;
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	LOG_INFO("Waiting for process %s...", processName.c_str());

	while (pid == 0) {
		HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
		
		if (Process32First(snapshot, &entry)) {
			do {
				if (_stricmp(entry.szExeFile, processName.c_str()) == 0) {
					pid = entry.th32ProcessID;
					if (outPID) *outPID = pid;
					break;
				}
			} while (Process32Next(snapshot, &entry));
		}
		
		CloseHandle(snapshot);
		
		if (pid == 0)
			Sleep(100); // Ожидаем 100 мс перед следующей проверкой
	}
	
	LOG_INFO("Process %s found, PID: %d", processName.c_str(), pid);
	return pid;
}

// Функция для ожидания инициализации процесса
bool WaitForProcessInitialization(HANDLE hProcess, int maxWaitTimeMs = 30000) {
	int waitTime = 0;
	const int checkInterval = 100; // Проверяем каждые 100 мс
	
	LOG_INFO("Waiting for process initialization...");
	
	// Проверка основных библиотек
	bool kernelLoaded = false;
	bool ntdllLoaded = false;
	
	while (waitTime < maxWaitTimeMs) {
		// Проверка загруженных модулей
		HMODULE hModules[1024];
		DWORD cbNeeded;
		
		if (EnumProcessModules(hProcess, hModules, sizeof(hModules), &cbNeeded)) {
			DWORD moduleCount = cbNeeded / sizeof(HMODULE);
			
			// Даже если процесс не загрузил много модулей, мы проверяем наличие критических DLL
			if (moduleCount > 3) {
				for (DWORD i = 0; i < moduleCount; i++) {
					char modName[MAX_PATH];
					if (GetModuleFileNameExA(hProcess, hModules[i], modName, sizeof(modName))) {
						std::string moduleName = modName;
						std::transform(moduleName.begin(), moduleName.end(), moduleName.begin(), ::tolower);
						
						if (moduleName.find("kernel32.dll") != std::string::npos)
							kernelLoaded = true;
						else if (moduleName.find("ntdll.dll") != std::string::npos)
							ntdllLoaded = true;
					}
				}
				
				// Если обе критические библиотеки загружены, процесс достаточно инициализирован
				if (kernelLoaded && ntdllLoaded) {
					LOG_INFO("Process loaded critical modules, ready for injection");
					return true;
				}
			}
			
			// Много модулей тоже означает готовность
			if (moduleCount > 10) {
				LOG_INFO("Process loaded %d modules, ready for injection", moduleCount);
				return true;
			}
		}
		
		Sleep(checkInterval);
		waitTime += checkInterval;
		
		// Проверка не завершился ли процесс
		DWORD exitCode = 0;
		if (GetExitCodeProcess(hProcess, &exitCode) && exitCode != STILL_ACTIVE) {
			LOG_ERROR("Process terminated prematurely, code: %d", exitCode);
			return false;
		}
	}
	
	// Если истекло время ожидания, но процесс все еще жив, попробуем инжектить
	// В некоторых случаях это может сработать
	LOG_INFO("Timeout waiting for full initialization, but process is still active. Attempting injection anyway.");
	return true;
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

// Функция для загрузки DLL в файловый буфер
bool LoadDllFile(const std::string& dllPath, BYTE** pSrcData, SIZE_T* fileSize) {
	std::ifstream File(dllPath, std::ios::binary | std::ios::ate);

	if (File.fail()) {
		LOG_ERROR("Opening the file failed: %X", (DWORD)File.rdstate());
		File.close();
		return false;
	}

	*fileSize = File.tellg();
	if (*fileSize < 0x1000) {
		LOG_ERROR("Filesize invalid.");
		File.close();
		return false;
	}

	*pSrcData = new BYTE[(UINT_PTR)*fileSize];
	if (!*pSrcData) {
		LOG_ERROR("Can't allocate dll file.");
		File.close();
		return false;
	}

	File.seekg(0, std::ios::beg);
	File.read((char*)(*pSrcData), *fileSize);
	File.close();
	
	return true;
}

int main() {
	LOG_INFO("Simple dll injector...");

	std::string p = GetExecutablePath();
	std::filesystem::path paths(p);
	auto dllPath = paths.parent_path() / "WWMoonlight.dll";
	LOG_INFO("DLL Path: %s", dllPath.string().c_str());
	
	// Выбор типа инжекта
	InjectType injectType;
	int choice;
	
	LOG_INFO("Choose inject type:");
	LOG_INFO("1. LoadLibrary");
	LOG_INFO("2. Manual Map");
	LOG_INFO("3. Early Manual Map (inject when game starts)");
	
	std::cout << "Your choice: ";
	std::cin >> choice;
	
	switch (choice) {
		case 1: injectType = InjectType::LoadLibrary; break;
		case 2: injectType = InjectType::ManualMap; break;
		case 3: injectType = InjectType::EarlyManualMap; break;
		default:
			LOG_ERROR("Invalid choice, using LoadLibrary");
			injectType = InjectType::LoadLibrary;
	}
	
	std::string targetProcess = "Client-Win64-Shipping.exe";
	DWORD PID = 0;
	
	if (injectType == InjectType::EarlyManualMap) {
		LOG_INFO("Waiting for game to start...");
		LOG_INFO("Start the game now");
		
		PID = WaitForProcessCreation(targetProcess);
	} else {
		LOG_INFO("Waiting for started game...");
		
		do {
			PID = GetProcessIdByName(targetProcess.c_str());
			Sleep(100);
		} while (PID == 0);
	}

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
	
	// Для раннего инжекта ожидаем инициализации процесса
	if (injectType == InjectType::EarlyManualMap) {
		if (!WaitForProcessInitialization(hProc)) {
			CloseHandle(hProc);
			system("PAUSE");
			return -5;
		}
	}

	// Выполнение инжекта в зависимости от выбранного типа
	bool success = false;
	
	if (injectType == InjectType::LoadLibrary) {
		// LoadLibrary инжект
		std::wstring wideDllPath = std::filesystem::path(dllPath).wstring();
		LOG_INFO("Injection DLL with LoadLibraryW...");
		success = LoadLibraryInject(hProc, wideDllPath);
	} else {
		// Manual Map инжект (используется как для обычного, так и для раннего инжекта)
		BYTE* pSrcData = nullptr;
		SIZE_T fileSize = 0;
		
		if (!LoadDllFile(dllPath.string(), &pSrcData, &fileSize)) {
			CloseHandle(hProc);
			system("PAUSE");
			return -6;
		}
		
		LOG_INFO("Injection DLL with Manual Mapping...");
		success = ManualMapDll(hProc, pSrcData, fileSize);
		
		delete[] pSrcData;
	}

	if (!success) {
		CloseHandle(hProc);
		LOG_ERROR("Injection error.");
		system("PAUSE");
		return -7;
	}

	CloseHandle(hProc);
	LOG_INFO("Injection successfully completed!");
	return 0;
}