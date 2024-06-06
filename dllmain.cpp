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


typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (Menu::IsOpened && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

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

	// Получаем размеры окна
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


	ImGui::NewFrame();

	UIWaterMark::Watermark();

	if (Menu::IsOpened)
		Menu::Init();

	// Ограничение позиции окна ImGui
	ImVec2 windowPos = ImGui::GetWindowPos();
	ImVec2 windowSize = ImGui::GetWindowSize();
	bool updatePos = false;

	if (windowPos.x < 0.0f) {
		windowPos.x = 0.0f;
		updatePos = true;
	}
	if (windowPos.y < 0.0f) {
		windowPos.y = 0.0f;
		updatePos = true;
	}
	if (windowPos.x + windowSize.x > windowWidth) {
		windowPos.x = windowWidth - windowSize.x;
		updatePos = true;
	}
	if (windowPos.y + windowSize.y > windowHeight) {
		windowPos.y = windowHeight - windowSize.y;
		updatePos = true;
	}

	if (updatePos) {
		ImGui::SetWindowPos(windowPos);
	}



	ImGui::Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}


DWORD WINAPI HackThread(HMODULE hModule)
{


	// Тут консоль бы не помешала
	//AllocConsole();
	//FILE* f;
	//freopen_s(&f, "CONOUT$", "w", stdout);
	//freopen_s(&f, "CONOUT$", "w", stderr);


	// Закрываем консоль при завершении работы потока
	//FreeConsole();
	FreeLibraryAndExitThread(hModule, 0);
	return 0;
}


DWORD WINAPI KeyHandler(LPVOID lpReserved)
{

	while (true) {

		if (GetAsyncKeyState(VK_INSERT) & 1)
			Menu::IsOpened = !Menu::IsOpened;


		if (GetAsyncKeyState(VK_END) & 1) {
			kiero::shutdown();
			return 0;
		}

	}

	return TRUE;
}

DWORD WINAPI MainThread(LPVOID lpReserved)
{
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

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		CreateThread(NULL, 0, KeyHandler, hMod, 0, NULL);
		//(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hMod, 0, nullptr));
		// CloseHandle itn't closing after releasing all memory
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}