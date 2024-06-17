#pragma once
#include <thread>
#include <Windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include <kiero.h>
#include <imgui.h>
#include <imgui_impl_win32.h>
#include <imgui_impl_dx11.h>
#include <Menu/Menu.hpp>
#include <Helper.h>
#include <globals.h>
#include <wuwa-base/Logger.h>
#include <wuwa-base/util.h>
#include <SDKTools/SDKTools.hpp>

typedef HRESULT(__stdcall* ResizeBuffers)(IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags);
ResizeBuffers oResizeBuffers = nullptr;
typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
Present oPresent;

typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;

// to unload dll
typedef BOOL(WINAPI* PFreeLibrary)(_In_ HMODULE hModule);
typedef VOID(WINAPI* PExitThread)(_In_ DWORD dwExitCode);
typedef unsigned int (WINAPI* PTHREADPROC)(LPVOID lParam);

typedef struct _DLLUNLOADINFO
{
    PFreeLibrary	m_fpFreeLibrary;
    PExitThread		m_fpExitThread;
    HMODULE		    m_hFreeModule;
} DLLUNLOADINFO, *PDLLUNLOADINFO;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
HRESULT ResizeSwapChain(IDXGISwapChain* pSwapChain, ID3D11Device* pDevice, ID3D11DeviceContext* pContext,
    ID3D11RenderTargetView** pRenderTargetView, UINT Width, UINT Height);

volatile bool g_bUnload = false;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;
IDXGISwapChain* pSwapChain;
HMODULE hModule;

uintptr_t BaseAddr;
Menu menu;

void InitImGui();
void CreateRenderTarget(IDXGISwapChain* pSwapChain);
void CleanupRenderTarget();

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
HRESULT __stdcall hkResizeBuffers(IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags);

// Hack stuff
DWORD WINAPI KeyHandler(LPVOID lpReserved);
DWORD WINAPI FeaturesThread(LPVOID lpReserved);
DWORD WINAPI MainThread(HMODULE hMod, LPVOID lpReserved);
BOOL APIENTRY DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved);
