#pragma once
#include <thread>
#include "Menu/Menu.h"
#include <Windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include "kiero/kiero.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include "Menu/Watermark.h"
#include "Console/Console.hpp"
#include "Helper.h"
#include "Globals.h"

#define BaseModule L"Client-Win64-Shipping.exe"
#define MenuKey VK_INSERT
#define QuitKey VK_END

typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
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
}DLLUNLOADINFO, * PDLLUNLOADINFO;

unsigned int WINAPI DllUnloadThreadProc(LPVOID lParam);
void DllSelfUnloading(_In_ const HMODULE hModule);

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;
uintptr_t BaseAddr;
HMODULE hModule;

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (Menu::IsOpened && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam)) {
		return true;
	}

	return Menu::IsOpened ? Menu::IsOpened : CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool init = false;
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}

	// Get Window size
	int windowWidth, windowHeight;
	GetWindowClientSize(window, windowWidth, windowHeight);
	float pwindowSize[2] = { windowWidth / 2, windowHeight / 3 };


	ImGuiStyle& style = ImGui::GetStyle();
	ImVec4* colors = style.Colors;

	Menu::StyleColorsOrangeDark(style, colors, pwindowSize);

	bool showSettingsWindow = true;
	bool showAnotherWindow = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();

	// show real cursor
	Menu::RealCursorShow();

	ImGui::NewFrame();

	UIWaterMark::Watermark();

	Menu::PreventMoveOutOfWndBounds(" ");

	if (Menu::IsOpened)
		Menu::Init();

	ImGui::Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}

DWORD WINAPI KeyHandler(LPVOID lpReserved)
{

	while (true) {

		if (GetAsyncKeyState(VK_INSERT) & 1)
			Menu::IsOpened = !Menu::IsOpened;


		if (GetAsyncKeyState(VK_END) & 1) {
			kiero::shutdown();
			DllSelfUnloading((HMODULE)hModule);

			return 0;
		}

		std::this_thread::sleep_for(100ms);
	}

	return TRUE;
}

DWORD WINAPI MainThread(HMODULE hMod, LPVOID lpReserved)
{

	HANDLE hProc = GetCurrentProcess();
	Helper proc;
	con = &Console::Instance(true);
	if (con != nullptr)
		std::cout << "Console Allocated\n"; // Replace with Logging Create Console
	
	BaseAddr = proc.GetBaseModuleAddress("Client-Win64-Shipping.exe");
	std::cout << "Base address: " << BaseAddr << " hex: " << std::hex << BaseAddr << std::endl;
	
	
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)&oPresent, hkPresent);
			init_hook = true;
		}

	} while (!init_hook);

	return TRUE;
}


// https://www.unknowncheats.me/forum/c-and-c-/146497-release-source-self-unloading-dll.html
unsigned int WINAPI DllUnloadThreadProc(LPVOID lParam)
{
	PDLLUNLOADINFO pDllUnloadInfo = (PDLLUNLOADINFO)lParam;

	//  
	// FreeLibrary dll  
	//  
	(pDllUnloadInfo->m_fpFreeLibrary)(pDllUnloadInfo->m_hFreeModule);

	//
	// Exit Thread
	// This thread return value is freed memory.
	// So you don't have to return this thread.
	//
	pDllUnloadInfo->m_fpExitThread(0);
	return 0;
}


VOID DllSelfUnloading(_In_ const HMODULE hModule)
{
	PVOID pMemory = NULL;
	ULONG ulFuncSize;
	unsigned int uintThreadId = 0;

	pMemory = VirtualAlloc(NULL, 0x1000, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (pMemory != NULL)
	{
		ulFuncSize = (ULONG_PTR)DllUnloadThreadProc - (ULONG_PTR)DllSelfUnloading;
		if ((ulFuncSize >> 31) & 0x01)
		{
			ulFuncSize = (ULONG_PTR)DllSelfUnloading - (ULONG_PTR)DllUnloadThreadProc;
		}

		memcpy(pMemory, DllUnloadThreadProc, ulFuncSize);

		((PDLLUNLOADINFO)(((ULONG_PTR)pMemory) + 0x500))->m_fpFreeLibrary =
			(PFreeLibrary)GetProcAddress(GetModuleHandle(_T("kernel32.dll")), "FreeLibrary");

		((PDLLUNLOADINFO)(((ULONG_PTR)pMemory) + 0x500))->m_fpExitThread =
			(PExitThread)GetProcAddress(GetModuleHandle(_T("kernel32.dll")), "ExitThread");

		((PDLLUNLOADINFO)(((ULONG_PTR)pMemory) + 0x500))->m_hFreeModule = hModule;

		_beginthreadex(NULL, 0, (PTHREADPROC)pMemory, (PVOID)(((ULONG_PTR)pMemory) + 0x500), 0, &uintThreadId);
	}
}

BOOL APIENTRY DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{

	DisableThreadLibraryCalls(hMod);
	switch (dwReason)
	{

	case DLL_PROCESS_ATTACH:
		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainThread, hMod, 0, nullptr);
		CreateThread(nullptr, 0, KeyHandler, hMod, 0, nullptr);
		hModule = hMod;
		break;

	case DLL_PROCESS_DETACH:
		if (con && con->IsAllocated())
			con->Free();

		kiero::shutdown();
		break;
	}

	return TRUE;
}