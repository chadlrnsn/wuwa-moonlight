#pragma once
#include <string>
#include <Windows.h>

#include <wuwa-base/util.h>

int FindProcessId(const std::string& processName);
void WaitForCloseProcess(const std::string& processName);

std::optional<std::string> SelectFile(const char* filter, const char* title);