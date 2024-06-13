#pragma once
#include <string>
#include <Windows.h>

#include <wuwa-base/util.h>

int FindProcessId(const std::string& processName);
void WaitForCloseProcess(const std::string& processName);

std::optional<std::string> SelectFile(const char* filter, const char* title);
std::optional<std::string> SelectDirectory(const char* title);
std::optional<std::string> GetOrSelectPath(CSimpleIni& ini, const char* section, const char* name, const char* friendName, const char* filter);