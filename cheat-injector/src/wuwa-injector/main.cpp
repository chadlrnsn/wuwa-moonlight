#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <filesystem>

#include <SimpleIni.h>

#include "injector.h"
#include "util.h"
#include <resource.h>
#include <wuwa-base/Logger.h>

const std::string GlobalWuwaProcName = "Client-Win64-Shipping.exe";
const char* DLLPath = "moonlight.dll";
const char* BypassDLLPath = "bypass.dll";

static CSimpleIni ini;

bool OpenGameProcess(HANDLE* phProcess, HANDLE* phThread, const char* additionalParam);

int main(int argc, char* argv[])
{
	//Logger::SetLevel(Logger::Level::Debug, Logger::LoggerType::ConsoleLogger);

	auto path = std::filesystem::path(argv[0]).parent_path();
	current_path(path);

	WaitForCloseProcess(GlobalWuwaProcName);

	Sleep(1000); // Wait for unloading all dlls.

	ini.SetUnicode();
	ini.LoadFile("cfg.ini");

	HANDLE hProcess, hThread;
	bool success = OpenGameProcess(&hProcess, &hThread, "-fileopenlog");
	if (!success)
	{
		std::cout << "Failed to open Client-Win64-Shipping process." << std::endl;
		system("pause");
		return 1;
	}

	current_path(path);
	ini.SaveFile("cfg.ini");

	std::string filename = (argc == 2 ? argv[1] : DLLPath);
	std::filesystem::path currentDllPath = std::filesystem::current_path() / filename;

#ifdef _DEBUG
	std::filesystem::path tempDllPath = std::filesystem::temp_directory_path() / filename;

	std::error_code ec;
	std::filesystem::copy_file(currentDllPath, tempDllPath, std::filesystem::copy_options::update_existing, ec);
	if (ec)
	{
		//LOG_ERROR("Copy dll failed: %s", ec.message().c_str());
		printf("Copy dll failed: %s\n", ec.message().c_str());
		std::system("pause");
	}

	InjectDLL(hProcess, tempDllPath.string());
#else
	InjectDLL(hProcess, currentDllPath.string());
#endif

	Sleep(2000);
	ResumeThread(hThread);

	CloseHandle(hProcess);
}

bool OpenGameProcess(HANDLE* phProcess, HANDLE* phThread, const char* additionalParam)
{
	HANDLE hToken;
	BOOL TokenRet = OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken);

	if (!TokenRet)
	{
		//LOG_LAST_ERROR("Privilege escalation failed!");
		printf("Privilege escalation failed!\n");
		return false;
	}

	auto filePath = GetOrSelectPath(ini, "Inject", "wuwapath", "wuwa path", "Executable\0Client-Win64-Shipping.exe;\0");
	auto commandline = ini.GetValue("Inject", "WuwaCommandLine");

	bool useAdditionalParamExists = ini.KeyExists("Inject", "UseAdditionalParam");

	if (!useAdditionalParamExists) {
		ini.SetBoolValue("Inject", "UseAdditionalParam", false);
		ini.SaveFile("cfg.ini");
	}

	bool useAdditionalParam = ini.GetBoolValue("Inject", "UseAdditionalParam", false);

	std::string newCommandLine;
	if (commandline != nullptr) {
		newCommandLine = commandline;
	}

	if (useAdditionalParam && additionalParam != nullptr) {
		if (!newCommandLine.empty()) {
			newCommandLine += " ";
		}
		newCommandLine += additionalParam;
		std::cout << "Launching the program with an additional parameter: " << additionalParam << std::endl;
	}
	else {
		std::cout << "Launching the program without an additional parameter" << std::endl;
	}

	LPSTR lpstr = newCommandLine.empty() ? nullptr : const_cast<LPSTR>(newCommandLine.c_str());

	//LPSTR lpstr = commandline == nullptr ? nullptr : const_cast<LPSTR>(commandline);
	if (!filePath)
		return false;

	DWORD pid = FindProcessId("explorer.exe");
	if (pid == 0)
	{
		//LOG_ERROR("Can't find 'explorer' pid!");
		printf("Can't find 'explorer' pid!");
		return false;
	}

	std::string CurrentDirectory = filePath.value();
	int pos = CurrentDirectory.rfind("\\", CurrentDirectory.length());
	CurrentDirectory = CurrentDirectory.substr(0, pos);

	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	SIZE_T lpsize = 0;
	InitializeProcThreadAttributeList(NULL, 1, 0, &lpsize);

	char* temp = new char[lpsize];
	LPPROC_THREAD_ATTRIBUTE_LIST AttributeList = (LPPROC_THREAD_ATTRIBUTE_LIST)temp;
	InitializeProcThreadAttributeList(AttributeList, 1, 0, &lpsize);
	if (!UpdateProcThreadAttribute(AttributeList, 0, PROC_THREAD_ATTRIBUTE_PARENT_PROCESS,
		&handle, sizeof(HANDLE), NULL, NULL))
	{
		//LOG_WARNING("UpdateProcThreadAttribute failed ! (%d).\n", GetLastError());
		printf("UpdateProcThreadAttribute failed ! (%d).\n", GetLastError());
	}

	STARTUPINFOEXA si{};
	si.StartupInfo.cb = sizeof(si);
	si.lpAttributeList = AttributeList;

	PROCESS_INFORMATION pi{};
	BOOL result = CreateProcessAsUserA(hToken, const_cast<LPSTR>(filePath->data()), lpstr,
		0, 0, 0, EXTENDED_STARTUPINFO_PRESENT | CREATE_SUSPENDED, 0,
		(LPSTR)CurrentDirectory.data(), (LPSTARTUPINFOA)&si, &pi);

	bool isOpened = result;
	if (isOpened)
	{
		ini.SaveFile("cfg.ini");
		*phThread = pi.hThread;
		*phProcess = pi.hProcess;
	}
	else
	{
		//LOG_LAST_ERROR("Failed to create game process.");
		printf("Failed to create game process.\n");
		//LOG_ERROR("If you have problem with Client-Win64-Shipping.exe path. You can change it manually in cfg.ini.");
		printf("If you have problem with Client-Win64-Shipping.exe path. You can change it manually in cfg.ini.\n");
	}

	DeleteProcThreadAttributeList(AttributeList);
	delete[] temp;
	return isOpened;
}
