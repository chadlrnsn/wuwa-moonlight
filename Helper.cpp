#include "Helper.h"

Helper::Helper()
{
	pID = NULL;
	processHandle = NULL;
}

Helper::Helper(DWORD pID) {
	this->pID = pID;
	HANDLE processHandle = NULL;
	processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);
	if (processHandle == INVALID_HANDLE_VALUE || processHandle == NULL) {
		std::cerr << "Failed to open process -- invalid handle" << std::endl;
		std::cerr << "Error code: " << GetLastError() << std::endl;
		throw "Failed to open process";
	}
	else {
		//std::cout << "Helper:: process handle sucessfully created!" << std::endl;
		this->processHandle = processHandle;
	}
}


Helper::~Helper()
{
	CloseHandle(this->processHandle);
}

void Helper::SetpID(DWORD pID) { this->pID = pID; }
DWORD Helper::GetpID() { return this->pID; }
HANDLE Helper::GetprocessHandle() { return this->processHandle; }

uintptr_t Helper::GetModuleBaseAddress(TCHAR* lpszModuleName) {
	uintptr_t dwModuleBaseAddress = 0;
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID);
	MODULEENTRY32 ModuleEntry32 = { 0 };
	ModuleEntry32.dwSize = sizeof(MODULEENTRY32);

	if (Module32First(hSnapshot, &ModuleEntry32))
	{
		do {
			if (_tcscmp(ModuleEntry32.szModule, lpszModuleName) == 0)
			{
				dwModuleBaseAddress = (uintptr_t)ModuleEntry32.modBaseAddr;
				break;
			}
		} while (Module32Next(hSnapshot, &ModuleEntry32));


	}
	CloseHandle(hSnapshot);
	return dwModuleBaseAddress;
}

uintptr_t Helper::GetDynamicAddress(uintptr_t baseAddress, vector<DWORD> offsets) {
	uintptr_t dynamicAddress = baseAddress;
	for (int i = 0; i < offsets.size() - 1; i++)
	{
		ReadProcessMemory(this->processHandle, (LPCVOID)(dynamicAddress + offsets[i]), &dynamicAddress, sizeof(offsets.at(i)), NULL);
		//std::cout << "Current Adress: " << std::hex << healthAddress << std::endl;
	}
	dynamicAddress += offsets[offsets.size() - 1];
	return dynamicAddress;
}

void Helper::SetpBaseAddress(char moduleName[]) {
	this->pBaseAddress = this->GetModuleBaseAddress(_T(moduleName));
}

uintptr_t Helper::GetAddressFromSignature(vector<int> signature) {
	if (this->pBaseAddress == NULL || this->processHandle == NULL) {
		return NULL;
	}

	// ISO C++ 20 std::byte
	std::vector<std::byte> memBuffer(this->pSize);
	if (!ReadProcessMemory(this->processHandle, (LPCVOID)(this->pBaseAddress), memBuffer.data(), this->pSize, NULL)) {
		std::cout << GetLastError() << std::endl;
		return NULL;
	}
	for (int i = 0; i < this->pSize; i++) {
		for (uintptr_t j = 0; j < signature.size(); j++) {

			// ISO C++ 20 std::to_integer<int>
			if (signature.at(j) != -1 && signature[j] != std::to_integer<int>(memBuffer[i + j]))
				//std::cout << std::hex << signature.at(j) << std::hex << memBuffer[i + j] << std::endl;
				break;
			if (signature[j] == std::to_integer<int>(memBuffer[i + j]) && j > 0)
				std::cout << std::hex << int(signature[j]) << std::hex << int(memBuffer[i + j]) << j << std::endl;
			if (j + 1 == signature.size())
				return this->pBaseAddress + i;
		}
	}
	return NULL;
}


uintptr_t Helper::GetBaseAddress(const HANDLE hProcess) {
	if (hProcess == NULL)
		return NULL; // No access to the process

	HMODULE lphModule[1024]; // Array that receives the list of module handles
	DWORD lpcbNeeded(NULL); // Output of EnumProcessModules, giving the number of bytes requires to store all modules handles in the lphModule array

	if (!EnumProcessModules(hProcess, lphModule, sizeof(lphModule), &lpcbNeeded))
		return NULL; // Impossible to read modules

	TCHAR szModName[MAX_PATH];
	if (!GetModuleFileNameEx(hProcess, lphModule[0], szModName, sizeof(szModName) / sizeof(TCHAR)))
		return NULL; // Impossible to get module info

	return (DWORD)lphModule[0]; // Module 0 is apparently always the EXE itself, returning its address
}

uintptr_t Helper::GetBaseModuleAddress(LPCSTR name) {
	if (name == NULL)
		return NULL;

	return (uintptr_t)GetModuleHandle(name);
}

bool Helper::UnloadModule( LPCSTR name )
{
	HMODULE hModule = GetModuleHandle(name);
	if (hModule == nullptr) {
		std::cerr << "Module not found: " << name << std::endl;
		return false;
	}

	if (!FreeLibrary(hModule)) {
		std::cerr << "Failed to free module: " << name << std::endl;
		return false;
	}

	std::cout << "Successfully unloaded module: " << name << std::endl;
	return true;
}
