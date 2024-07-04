#pragma once
#include "dllmain.h"
#define MenuKey VK_INSERT
#define QuitKey VK_END

using namespace SDK;
using namespace SDKTools;
using namespace SDKTools::World;
using namespace SDKTools::Player;


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

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	ImGuiIO& io = ImGui::GetIO();
	io.MouseDrawCursor = menu.IsOpen;

	if (menu.IsOpen && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;
	

	return menu.IsOpen ? menu.IsOpen : CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
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
		else {
			return oPresent(pSwapChain, SyncInterval, Flags);
		}
	}


	if (!menu.bOnceStyle) {
		menu.Setup();
		menu.bOnceStyle = true;
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();

	ImGui::NewFrame();
	
	if (!firstnotify)
	{
		ImGui::InsertNotification({ ImGuiToastType::Warning, 20000, "This cheat is for free use, if you bought it - you got scamed" });
		firstnotify = true;
	}


	fpsUnlock.DrawFPS();
	menu.RenderWatermark();

	const char* wnds[] = {
		"Moonlight",
		"FPS",
	};

	for (int i = 0; i < std::size(wnds); i++)
		menu.PreventMoveOutOfWndBounds(wnds[i]);

	if (menu.IsOpen)
		menu.RenderMenu();

	menu.RenderNotify();

	ImGui::Render();
	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	return oPresent(pSwapChain, SyncInterval, Flags);
}

HRESULT __stdcall hkPresent_visuals(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{

	return hkPresent(pSwapChain, SyncInterval, Flags);
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

DWORD WINAPI KeyHandler(LPVOID lpReserved)
{

	while (!g_bUnload) {

		// checking we on another window or no
		if (window) {
			if (GetForegroundWindow() != window)
			{ 
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				continue;
			}
		}

		if (GetAsyncKeyState(MenuKey) & 1)
			menu.IsOpen = !menu.IsOpen;


		if (GetAsyncKeyState(QuitKey) & 1) {
			g_bUnload = true;
			kiero::shutdown();
			ExitProcess(EXIT_SUCCESS);
			FreeLibraryAndExitThread((HMODULE)lpReserved, 0);
			return 0;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	return 0;
}

DWORD WINAPI FeaturesThread(LPVOID lpReserved)
{
	speedhack.Setup();
	god.Setup();
	fly.Setup();
	gravityScale.Setup();
	walkFloorZ.Setup();
	walkFloorAngle.Setup();
	fpsUnlock.Setup();

	UEngine* Engine;
	UWorld* World;

	while (!g_bUnload)
	{

		// checking we on another window or no
		if (window && GetForegroundWindow() != window)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			continue;
		}

		Engine = UEngine::GetEngine();
		if (!Engine)
			continue;

		void* enginePtr[1] = { Engine };
		fpsUnlock.Run(enginePtr, 1);

		World = UWorld::GetWorld();
		if (!IsValidPointer(World))
			continue;

		// this is important
		if (!IsFullyLoaded())
			continue;


		ULocalPlayer* LocalPlayer = World->OwningGameInstance->LocalPlayers[0];
		APlayerController* PlayerController = LocalPlayer->PlayerController;
		APawn* AcknowledgedPawn = PlayerController->AcknowledgedPawn;
		UPawnMovementComponent* MovementComponent = AcknowledgedPawn->GetMovementComponent();

		void* acknowledgePawnPtr[2] = { AcknowledgedPawn, World };

		speedhack.Run(acknowledgePawnPtr, 1);
		god.Run(acknowledgePawnPtr, 1);
		gravityScale.Run(acknowledgePawnPtr, 1);
		walkFloorZ.Run(acknowledgePawnPtr, 1);
		walkFloorAngle.Run(acknowledgePawnPtr, 1);

		hitMultiplier.Run(acknowledgePawnPtr, 1);

		UPawnMovementComponent* MoveComponent = AcknowledgedPawn->GetMovementComponent();
		void* flyArgs[2] = { AcknowledgedPawn, MoveComponent };
		fly.Run(flyArgs, 1);;

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	return TRUE;

}

DWORD WINAPI MainThread(HMODULE hMod, LPVOID lpReserved)
{

	AllocConsole();
	FILE* dummy;
	freopen_s(&dummy, "CONOUT$", "w", stdout);
	freopen_s(&dummy, "CONOUT$", "w", stderr);
	freopen_s(&dummy, "CONOUT$", "w", stdin);

	HMODULE addr = GetModuleHandleA(0);
	std::cout << "Base address: " << addr << std::endl;
	std::cout << "Builded at " << BuildInfo << std::endl;

		
	static bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			if (kiero::bind(8, (void**)&oPresent, hkPresent))
				kiero::bind(8, (void**)&oPresent, hkPresent_visuals);

			kiero::bind(13, (void**)&oResizeBuffers, hkResizeBuffers);
			init_hook = true;
		}

	} while (!init_hook);

	return TRUE;
}


BOOL APIENTRY DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	DisableThreadLibraryCalls(hMod);
	switch (dwReason)
	{

	case DLL_PROCESS_ATTACH:
		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainThread, hMod, 0, nullptr);
		CreateThread(nullptr, 0, KeyHandler, hMod, 0, nullptr);
		CreateThread(nullptr, 0, FeaturesThread, hMod, 0, nullptr);
		hModule = hMod;
		break;

	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}

	return TRUE;
}