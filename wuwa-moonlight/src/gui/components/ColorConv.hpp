#pragma once
#include <imgui.h>

namespace ImGui {
	ImColor Conv_FloatToColor(float color[4]);
	ImVec4 Conv_ColorToVec4(ImColor color);
}