#pragma once
#include <string>
#include <vector>
#include "../imgui/imgui_internal.h"
#include "../imgui/imgui.h"
#include <windows.h>
#include "../kiero/kiero.h"
#include "Settings.h"
#include "../SDK/SDK.hpp"
#include "../Features/UnloadDLL.h"

using namespace UnrealEngine;

void GetWindowClientSize(HWND hwnd, int& width, int& height)
{
    RECT rect;
    GetClientRect(hwnd, &rect);
    width = rect.right - rect.left;
    height = rect.bottom - rect.top;
}

template <typename T>
ImVec2 ResponsiveSize(ImVec2 size, T mulwide, T multall) {
    return ImVec2(size.x * mulwide, size.y * multall);
}

namespace Menu 
{
    bool IsOpened = true;
    static int page = 0;

    struct Button {
        const char* btnLable;
        std::string status;
        char* lastupd;
    };

    static std::vector<Button> Buttons = {
        { "Player", "", nullptr },
        { "ESP", "", nullptr },
        { "Misc", "", nullptr },
        { "Config", "", nullptr },
        { "Debug", "", nullptr }
    };

    void RealCursorShow();
    void SetUpColors(ImGuiStyle& style, ImVec4* colors, float windowSize[]);
    void StyleColorsOrangeDark(ImGuiStyle& style, ImVec4* colors, float windowSize[1]);

    // https://github.com/ocornut/imgui/issues/4356#issuecomment-1535547717
    void PreventMoveOutOfWndBounds(const char* wndName);

    void Init();
};
