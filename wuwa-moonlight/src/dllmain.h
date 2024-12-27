#pragma once
#ifndef IMGUI_DEFINE_MATH_OPERATORS
#define IMGUI_DEFINE_MATH_OPERATORS
#endif // !IMGUI_DEFINE_MATH_OPERATORS

#include <thread>
#include <Windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include <kiero.h>
#include <imgui.h>
#include <backends/imgui_impl_win32.h>
#include <backends/imgui_impl_dx11.h>
#include <Menu/Menu.hpp>
#include <globals.h>
#include <SDK.hpp>
#include <Hooks/Hooks.h>
#include <mutex>
#include <shared_mutex>
#include <utils/UpdateVars.h>

DWORD WINAPI MainThread(HMODULE hMod, LPVOID lpReserved);
BOOL APIENTRY DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved);
