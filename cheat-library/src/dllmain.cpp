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

	static bool styleInitialized = false;
	if (!styleInitialized) {
		menu.Setup();
		styleInitialized = true;
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();

	ImGui::NewFrame();
	
	// Show FPS
	fpsUnlock.DrawFPS();
	//

	menu.RenderWatermark();
	menu.PreventMoveOutOfWndBounds("Moonlight");

	//menu.ShowCenteredPopupSubmit("ALERT", "This cheat is opensource if you purchase it from someone u got scammed!", "Ok", &AlertMessage);
	if (menu.IsOpen)
		menu.Render();

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

DWORD WINAPI KeyHandler(LPVOID lpReserved)
{

	while (!g_bUnload) {

		if (GetAsyncKeyState(MenuKey) & 1)
			menu.IsOpen = !menu.IsOpen;


		if (GetAsyncKeyState(QuitKey) & 1) {
			g_bUnload = true;
			kiero::shutdown();
			ExitProcess(EXIT_SUCCESS);
			FreeLibraryAndExitThread((HMODULE)lpReserved, 0);
			// Temporary disabled due to crash
			//DllSelfUnloading((HMODULE)hModule);
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

	while (!g_bUnload)
	{
		UEngine* Engine;
		UWorld* World;

		Engine = UEngine::GetEngine();
		if (!Engine)
			continue;

		void* userSettings[1] = { Engine };
		fpsUnlock.Run(userSettings, 1);

		World = UWorld::GetWorld();
		if (!World)
			continue;

		// this is important
		if (!IsPersistentLevelLoaded(World) || !IsPlayerLoaded(World))
			continue;

		TArray<ULocalPlayer*> LocalPlayers = World->OwningGameInstance->LocalPlayers;
		ULocalPlayer* LocalPlayer = nullptr;

		if (!(LocalPlayers.Num() > 0))
			continue;

		LocalPlayer = World->OwningGameInstance->LocalPlayers[0];

		APlayerController* PlayerController = LocalPlayer->PlayerController;
		APawn* APawn = PlayerController->AcknowledgedPawn;

		void* AcknowledgePawnPtr[2] = { APawn, World };

		speedhack.Run( AcknowledgePawnPtr, 1 );
		god.Run( AcknowledgePawnPtr, 1 );
		gravityScale.Run( AcknowledgePawnPtr, 1 );
		walkFloorZ.Run( AcknowledgePawnPtr, 1 );
		walkFloorAngle.Run(AcknowledgePawnPtr , 1 );

		UPawnMovementComponent* MoveComponent = APawn->GetMovementComponent();
		void* flyArgs[2] = { MoveComponent, APawn };
		fly.Run(flyArgs, 1);

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

	HANDLE hProc = GetCurrentProcess();
	Helper proc;

	BaseAddr = proc.GetBaseModuleAddress("Client-Win64-Shipping.exe");
	std::cout << "Base address: " << BaseAddr << " hex: " << std::hex << BaseAddr << std::endl;
	std::cout << "Builded at " << BuildInfo << std::endl;

		
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)&oPresent, hkPresent);
			kiero::bind(13, (void**)&oResizeBuffers, hkResizeBuffers);
			init_hook = true;
		}

	} while (!init_hook);

	return TRUE;
}


// TO FIX CRASH
// https://www.unknowncheats.me/forum/c-and-c-/146497-release-source-self-unloading-dll.html
//unsigned int WINAPI DllUnloadThreadProc(LPVOID lParam)
//{
//	PDLLUNLOADINFO pDllUnloadInfo = (PDLLUNLOADINFO)lParam;
//
//	//  
//	// FreeLibrary dll  
//	//  
//	(pDllUnloadInfo->m_fpFreeLibrary)(pDllUnloadInfo->m_hFreeModule);
//
//	//
//	// Exit Thread
//	// This thread return value is freed memory.
//	// So you don't have to return this thread.
//	//
//	pDllUnloadInfo->m_fpExitThread(0);
//	return 0;
//}
//
//VOID DllSelfUnloading(_In_ const HMODULE hModule)
//{
//	PVOID pMemory = NULL;
//	ULONG ulFuncSize;
//	unsigned int uintThreadId = 0;
//
//	pMemory = VirtualAlloc(NULL, 0x1000, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
//	if (pMemory != NULL)
//	{
//		ulFuncSize = (ULONG_PTR)DllUnloadThreadProc - (ULONG_PTR)DllSelfUnloading;
//		if ((ulFuncSize >> 31) & 0x01)
//		{
//			ulFuncSize = (ULONG_PTR)DllSelfUnloading - (ULONG_PTR)DllUnloadThreadProc;
//		}
//
//		memcpy(pMemory, DllUnloadThreadProc, ulFuncSize);
//
//		((PDLLUNLOADINFO)(((ULONG_PTR)pMemory) + 0x500))->m_fpFreeLibrary =
//			(PFreeLibrary)GetProcAddress(GetModuleHandle(_T("kernel32.dll")), "FreeLibrary");
//
//		((PDLLUNLOADINFO)(((ULONG_PTR)pMemory) + 0x500))->m_fpExitThread =
//			(PExitThread)GetProcAddress(GetModuleHandle(_T("kernel32.dll")), "ExitThread");
//
//		((PDLLUNLOADINFO)(((ULONG_PTR)pMemory) + 0x500))->m_hFreeModule = hModule;
//
//		_beginthreadex(NULL, 0, (PTHREADPROC)pMemory, (PVOID)(((ULONG_PTR)pMemory) + 0x500), 0, &uintThreadId);
//	}
//}

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