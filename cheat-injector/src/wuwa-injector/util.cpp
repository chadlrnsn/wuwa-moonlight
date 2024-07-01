#include "pch.h"
#include "util.h"

#include <TlHelp32.h>

#include <iostream>
#include <sstream>
#include <filesystem>

#include <codecvt>
#include <shellapi.h>
#include <commdlg.h>
#include <shtypes.h>
#include <shobjidl_core.h>
#include <shlobj_core.h>

int FindProcessId(const std::string& processName)
{
    int pid = -1;

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 process;
    ZeroMemory(&process, sizeof(process));
    process.dwSize = sizeof(process);

    if (Process32First(snapshot, &process))
    {
        do
        {
            if (std::string(process.szExeFile) == processName)
            {
                pid = process.th32ProcessID;
                break;
            }
        } while (Process32Next(snapshot, &process));
    }

    CloseHandle(snapshot);

    return pid;
}

void WaitForCloseProcess(const std::string& processName)
{
    int pid = FindProcessId(processName);
    if (pid == -1)
        return;

    std::cout << "Found '" << processName << "' process. Waiting for closing..." << std::endl;

#ifdef _DEBUG
    std::stringstream stream;
    stream << "taskkill /F /T /IM " << processName;
    int retval = system(stream.str().c_str());

    std::cout << "Trying to kill process." << std::endl;
#endif

    HANDLE hProc = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
    DWORD exitCode = 0;
    while (hProc && (GetExitCodeProcess(hProc, &exitCode), exitCode == STILL_ACTIVE)) {
        Sleep(1000);
    }

    if (hProc != NULL)
        CloseHandle(hProc);
}

std::optional<std::string> SelectDirectory(const char* title)
{
    auto currPath = std::filesystem::current_path();

    if (!SUCCEEDED(CoInitialize(nullptr)))
        return {};

    IFileDialog* pfd;
    if (!SUCCEEDED(CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pfd))))
        return {};

    const size_t titleSize = strlen(title) + 1;
    wchar_t* wcTitle = new wchar_t[titleSize];
    mbstowcs(wcTitle, title, titleSize);

    DWORD dwOptions;
    IShellItem* psi;
    if (!SUCCEEDED(pfd->GetOptions(&dwOptions)) ||
        !SUCCEEDED(pfd->SetOptions(dwOptions | FOS_PICKFOLDERS)) ||
        !SUCCEEDED(pfd->SetTitle(wcTitle)) ||
        !SUCCEEDED(pfd->Show(NULL)) ||
        !SUCCEEDED(pfd->GetResult(&psi)))
    {
        pfd->Release();
        return {};
    }

    WCHAR* folderName;
    if (!SUCCEEDED(psi->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, &folderName)))
    {
        pfd->Release();
        psi->Release();
        return {};
    }

    pfd->Release();
    psi->Release();

    std::filesystem::current_path(currPath);

    std::u16string u16(reinterpret_cast<const char16_t*>(folderName));
    return std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}.to_bytes(u16);
}

std::optional<std::string> SelectFile(const char* filter, const char* title)
{
    auto currPath = std::filesystem::current_path();

    // common dialog box structure, setting all fields to 0 is important
    OPENFILENAME ofn = { 0 };
    TCHAR szFile[260] = { 0 };

    // Initialize remaining fields of OPENFILENAME structure
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = filter;
    ofn.lpstrTitle = title;
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    std::optional<std::string> result = {};
    if (GetOpenFileName(&ofn) == TRUE)
        result = std::string(szFile);

    std::filesystem::current_path(currPath);
    return result;
}

std::optional<std::string> GetOrSelectPath(CSimpleIni& ini, const char* section, const char* name, const char* friendName, const char* filter)
{
    auto savedPath = ini.GetValue(section, name);
    if (savedPath != nullptr)
        return std::string(savedPath);

    //LOG_DEBUG("%s path not found. Please point to it manually.", friendName);
    printf("%s path not found. Please point to it manually.\n", friendName);

    auto titleStr = util::string_format("Select %s", friendName);
    auto selectedPath = filter == nullptr ? SelectDirectory(titleStr.c_str()) : SelectFile(filter, titleStr.c_str());
    if (!selectedPath)
        return {};

    ini.SetValue(section, name, selectedPath->c_str());
    return selectedPath;
}