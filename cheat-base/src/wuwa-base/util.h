#pragma once
#include <string>
#include <stdexcept>
#include <memory>
#include <optional>
#include <vector>
#include <wuwa-base/Logger.h>

#include <filesystem>
#include <SimpleIni/SimpleIni.h>

// for logs in console basicly
#include <cstdio>
#include <io.h>
#include <fcntl.h>


#define LOG_LAST_ERROR(fmt, ...) util::LogLastError(__FILE__, __LINE__, fmt, __VA_ARGS__)

#define UPDATE_DELAY(delay) \
							static ULONGLONG s_LastUpdate = 0;       \
                            ULONGLONG currentTime = GetTickCount64();\
                            if (s_LastUpdate + (delay) > currentTime)  \
                                return;                              \
							s_LastUpdate = currentTime;

#define UPDATE_DELAY_VAR(type, name, delay) \
							static type name = {};                   \
							static ULONGLONG s_LastUpdate = 0;       \
                            ULONGLONG currentTime = GetTickCount64();\
                            if (s_LastUpdate + (delay) > currentTime)  \
                                return name;                         \
                            s_LastUpdate = currentTime;

namespace util
{
	std::optional<std::string> SelectFile(const char* filter, const char* title);
	std::optional<std::string> SelectDirectory(const char* title);
	std::optional<std::string> GetOrSelectPath(CSimpleIni& ini, const char* section, const char* name, const char* friendName, const char* filter);

	void OpenURL(const char* url);
	std::string GetLastErrorAsString(DWORD errorId = 0);
	int64_t GetCurrentTimeMillisec();

	std::string GetModulePath(HMODULE hModule = nullptr);

	void SetCurrentPath(const std::filesystem::path& curren_path);
	std::filesystem::path GetCurrentPath();

	std::vector<std::string> StringSplit(const std::string& delimiter, const std::string& content);
	std::string SplitWords(const std::string& value);
	std::string MakeCapital(std::string value);
	std::string to_hex_string(uint8_t* barray, int length);
	bool IsLittleEndian();

	std::string base64_encode(BYTE const* buf, unsigned int bufLen);
	std::vector<BYTE> base64_decode(std::string const&);

	int64_t GetTimezoneBias();

	void OpenConsole();

	template<typename ... Args>
	std::string string_format(const std::string& format, Args ... args)
	{
		int size_s = std::snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
		if (size_s <= 0) { throw std::runtime_error("Error during formatting."); }
		auto size = static_cast<size_t>(size_s);
		auto buf = std::make_unique<char[]>(size);
		std::snprintf(buf.get(), size, format.c_str(), args ...);
		return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
	}

	template<typename ... Args>
	void LogLastError(const char* filepath, int line, const char* fmt, Args ... args)
	{
		auto errorId = ::GetLastError();
		auto newFmt = string_format("%s. Error: %d %s", fmt, errorId, GetLastErrorAsString(errorId).c_str());
		//Logger::Log(Logger::Level::Error, filepath, line, newFmt.c_str(), args ...);
	}

	template<typename T>
	bool IsValidPointer(T* ptr)
	{
		if (ptr == nullptr)
			return false;
		MEMORY_BASIC_INFORMATION mbi;
		if (VirtualQuery(ptr, &mbi, sizeof(mbi)) == 0)
			return false;
		if (mbi.Protect & (PAGE_NOACCESS | PAGE_GUARD))
			return false;
		return true;
	}
}


