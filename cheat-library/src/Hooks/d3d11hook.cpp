#include <stdafx.h>

#include "d3d11hook.h"
#include <kiero/kiero.h>
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_dx11.h>
#include <imgui/backends/imgui_impl_win32.h>
#include <Menu/Menu.h>
#include <globals.h>
#include <config.h>

typedef HRESULT(__stdcall* ResizeBuffers)(IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags);
ResizeBuffers oResizeBuffers = nullptr;
typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
Present oPresent;

typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;
IDXGISwapChain* pSwapChain;
HMODULE hModule;
Menu menu;
bool firstnotify = false;

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}

void CleanupRenderTarget()
{
	if (mainRenderTargetView) {
		mainRenderTargetView->Release();
		mainRenderTargetView = nullptr;
	}
}

void CreateRenderTarget(IDXGISwapChain* pSwapChain)
{
	ID3D11Texture2D* pBackBuffer = nullptr;
	pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	if (pBackBuffer) {
		pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
		pBackBuffer->Release();
	}
}


LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
	if (menu.IsOpen) {
		ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
		return true;
	}

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	static bool init = false;
	if (!init) {
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice))) {
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;

			CreateRenderTarget(pSwapChain);

			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
		}
		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}

	ImGuiIO& io = ImGui::GetIO();
	io.MouseDrawCursor = menu.IsOpen;

	if (GetAsyncKeyState(config::binds::menu_key) & 1) menu.IsOpen = !menu.IsOpen;

	if (!menu.bOnceStyle) {
		menu.Setup();
		menu.bOnceStyle = true;
	}


	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();

	ImGui::NewFrame();


	const char* wnds[] = { "Moonlight","FPS", };

	//for (int i = 0; i < std::size(wnds); i++) menu.PreventMoveOutOfWndBounds(wnds[i]);
	//menu.PreventMoveOutOfWndBounds("Moonlight");

	if (menu.IsOpen) menu.RenderMenu();
	//fpsUnlock.DrawFPS();

	ImGui::Render();
	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	return oPresent(pSwapChain, SyncInterval, Flags);
}

HRESULT __stdcall hkResizeBuffers(IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags)
{
	CleanupRenderTarget();
	HRESULT hr = oResizeBuffers(pSwapChain, BufferCount, Width, Height, NewFormat, SwapChainFlags);
	if (SUCCEEDED(hr))
	{
		CreateRenderTarget(pSwapChain);
	}
	return hr;
}


void D3D11Hook::Initialize()
{
	static bool init = false;
	static size_t ampects = 25;
	static size_t counter = 0;
	do {
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success) {
			kiero::bind(8, (void**)&oPresent, hkPresent);
			kiero::bind(13, (void**)&oResizeBuffers, hkResizeBuffers);
#ifdef _DEBUG
			printf("kiero binded\n");
#endif
			init = true;
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
		counter++;
	} while (!init || (counter < ampects));

	if (kiero::getRenderType() != kiero::RenderType::D3D11) {
		printf("kiero initialized with unknown render type\n");
		MessageBoxA(NULL, "kiero initialized with unknown render type\n", "DirectX Error", MB_OK);
	}
	else {
		printf("kiero initialized with D3D11 if you dont see menu it might be bug or idk\n");
	}
}

void D3D11Hook::Uninitialize() {

	if (oWndProc)
	{
		SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)oWndProc);
		oWndProc = nullptr;
	}

	CleanupRenderTarget();

	if (window)
		window = nullptr;
}