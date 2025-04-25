#pragma once
#ifndef IMGUI_DEFINE_MATH_OPERATORS
#define IMGUI_DEFINE_MATH_OPERATORS
#endif // !IMGUI_DEFINE_MATH_OPERATORS


#include <d3d11.h>
#include <dxgi.h>
#include "kiero.h"
#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"
#include "gui/Menu.hpp"
#include "globals.h"

namespace D3D11Hook {
	void Initialize();
	void Uninitialize();
}