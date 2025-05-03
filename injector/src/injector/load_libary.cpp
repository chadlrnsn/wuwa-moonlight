#include "load_libary.h"
#include <logger.h>

/**
 * Injects a DLL into a process using LoadLibraryW technique
 * 
 * @param hProc Handle to target process
 * @param dllPath Wide string path to the DLL
 * @return true if successful, false otherwise
 */
bool LoadLibraryInject(HANDLE hProc, const std::wstring& dllPath) {
    // Allocate memory in target process for DLL path
    SIZE_T pathSize = (dllPath.length() + 1) * sizeof(wchar_t);
    LPVOID pRemotePath = VirtualAllocEx(hProc, NULL, pathSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    
    if (!pRemotePath) {
        LOG_ERROR("VirtualAllocEx failed: 0x%X", GetLastError());
        return false;
    }
    
    // Write DLL path to allocated memory
    if (!WriteProcessMemory(hProc, pRemotePath, dllPath.c_str(), pathSize, NULL)) {
        LOG_ERROR("WriteProcessMemory failed: 0x%X", GetLastError());
        VirtualFreeEx(hProc, pRemotePath, 0, MEM_RELEASE);
        return false;
    }
    
    // Get LoadLibraryW address
    HMODULE hKernel32 = GetModuleHandleA("kernel32.dll");
    if (!hKernel32) {
        LOG_ERROR("Failed to get kernel32.dll handle: 0x%X", GetLastError());
        VirtualFreeEx(hProc, pRemotePath, 0, MEM_RELEASE);
        return false;
    }
    
    FARPROC pLoadLibraryW = GetProcAddress(hKernel32, "LoadLibraryW");
    if (!pLoadLibraryW) {
        LOG_ERROR("Failed to get LoadLibraryW address: 0x%X", GetLastError());
        VirtualFreeEx(hProc, pRemotePath, 0, MEM_RELEASE);
        return false;
    }
    
    // Create remote thread to call LoadLibraryW
    HANDLE hThread = CreateRemoteThread(
        hProc, 
        NULL, 
        0, 
        (LPTHREAD_START_ROUTINE)pLoadLibraryW, 
        pRemotePath, 
        0, 
        NULL
    );
    
    if (!hThread) {
        LOG_ERROR("CreateRemoteThread failed: 0x%X", GetLastError());
        VirtualFreeEx(hProc, pRemotePath, 0, MEM_RELEASE);
        return false;
    }
    
    // Wait for thread to complete
    LOG_INFO("Remote thread created, waiting for completion...");
    WaitForSingleObject(hThread, INFINITE);
    
    // Get thread exit code
    DWORD exitCode = 0;
    GetExitCodeThread(hThread, &exitCode);
    
    // Cleanup
    CloseHandle(hThread);
    VirtualFreeEx(hProc, pRemotePath, 0, MEM_RELEASE);
    
    if (exitCode == 0) {
        LOG_ERROR("LoadLibraryW failed in target process");
        return false;
    }
    
    LOG_INFO("DLL successfully injected via LoadLibraryW (Handle: 0x%p)", (HMODULE)exitCode);
    return true;
}
