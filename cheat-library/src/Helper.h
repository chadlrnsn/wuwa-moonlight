#pragma once
#include <Windows.h>  //DWORD, HANDLE
#include <TlHelp32.h> //CreateToolhelp32Snapshot
#include <tchar.h>    //_tcscmp
#include <Psapi.h>    //GetModuleInformation
#include <vector>
#include <iostream>
#include <SDK.hpp>
#include <globals.h>
#include <algorithm>

using namespace std;
using namespace globals;
using namespace SDK;


namespace Helper {

	bool ContainsSubstring(const std::string& str, const std::string& sub);
	void devlog(const char* fmt, ...);
	bool IsFullyLoaded(SDK::UWorld* World) noexcept;

	void UE_RenderText(
		UCanvas* canvas,
		UFont* font,
		FString text,
		FVector2D Position = { 0, 0 },
		FVector2D Scale = { 1, 1 },
		FLinearColor color = { 1, 1, 1, 1 }
	);

	void UE_RenderTextEx(
		UCanvas* canvas,
		UFont* font,
		FString text,
		FVector2D Position = { 0, 0 },
		FVector2D Scale = { 1, 1 },
		FLinearColor color = { 1, 1, 1, 1 },
		bool centeredX = false,
		bool centeredY = false,
		bool outline = false,
		FLinearColor outlineColor = { 0, 0, 0, 1 }
	);
}

#define LOG(fmt, ...) HelperNS::devlog("[*] " fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...) HelperNS::devlog("[WARN] " fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) HelperNS::devlog("[ERROR] " fmt, ##__VA_ARGS__)