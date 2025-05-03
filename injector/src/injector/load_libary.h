#pragma once

#include <Windows.h>
#include <string>

bool LoadLibraryInject(HANDLE hProc, const std::wstring& dllPath);
