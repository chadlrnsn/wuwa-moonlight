#pragma once
#include <string>
#include <vector>
#include <windows.h>
#include <thread>
#include <globals.h>

#ifndef IMGUI_DEFINE_MATH_OPERATORS
#define IMGUI_DEFINE_MATH_OPERATORS
#endif // !IMGUI_DEFINE_MATH_OPERATORS

#include <imgui_internal.h>
#include <imgui.h>
#include <imgui-nav/nav_elements.h>
#include <imgui-notify/backends/IconsFontAwesome6.h>
#include <imgui-notify/backends/ImGuiNotify.hpp>
#include <Features/Features.h>

/**
 * @brief Calculates a responsive size based on the input size, width multiplier, and height multiplier.
 * 
 * @tparam T The type of the multipliers.
 * @param size The original size.
 * @param mulwide The multiplier for the width.
 * @param multall The multiplier for the height.
 * @return The calculated responsive size.
 */
template <typename T>
ImVec2 ResponsiveSize(ImVec2 size, T mulwide, T multall) {
    return ImVec2(size.x * mulwide, size.y * multall);
}

class Menu
{
private:
    bool bWatermark = true;

    enum Headers {
        PLAYER,
        ESP,
        MISC,
        CONFIG,
//#ifdef _DEBUG
//        DEBUG,
//#endif
        HEADERS_COUNT
    };

public:
    bool bShowBuild = true;
    bool IsOpen = false;
    float baseFontSize = 14.0f;
    float iconFontSize = baseFontSize * 2.0f / 3.0f;
    bool bOnceStyle = false;
    bool bOnceScaledMenu = false;

public:
    void RealCursorShow();
    void Setup();
    void SetUpColors(ImGuiStyle& style, ImVec4* colors);

    // https://github.com/ocornut/imgui/issues/4356#issuecomment-1535547717
    void PreventMoveOutOfWndBounds(const char* wndName);

    void RenderMenu();
    void RenderWatermark();
    void RenderNotify();
};


inline ImFont* regular;
inline ImFont* medium;
inline ImFont* bold;
inline ImFont* title;
inline ImFont* icons;