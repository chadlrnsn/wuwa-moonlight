#pragma once
#include <Windows.h>  //DWORD, HANDLE
#include <TlHelp32.h> //CreateToolhelp32Snapshot
#include <tchar.h>    //_tcscmp
#include <Psapi.h>    //GetModuleInformation
#include <vector>
#include <iostream>

using namespace std;

class Helper
{
private:
	DWORD pID;
	DWORD pBaseAddress; //Base Address of exe
	DWORD pSize;		//Size of exe module
	HANDLE processHandle;
	LPCSTR moduleName = "Client-Win64-Shipping.exe";

public:
	Helper();
	Helper(DWORD pID);
	~Helper();
	uintptr_t GetModuleBaseAddress(TCHAR* lpszModuleName);
	uintptr_t GetDynamicAddress(uintptr_t baseAddress, vector<DWORD> offsets);
	uintptr_t GetAddressFromSignature(vector<int> signature);
	void SetpID(DWORD pID);
	void SetpBaseAddress(char moduleName[]);
	DWORD GetpID();
	HANDLE GetprocessHandle();
	uintptr_t GetBaseAddress(const HANDLE hProcess);
	uintptr_t GetBaseModuleAddress( LPCSTR name );

	bool UnloadModule(LPCSTR name);

	// todo
	HMODULE GetCurrentModuleName();

};
