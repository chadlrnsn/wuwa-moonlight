#pragma once
#include <string>
#include <vector>
#include <windows.h>
#include "../imgui/imgui_internal.h"
#include "../imgui/imgui.h"
#include "../SDK/SDK.hpp"

using namespace UnrealEngine;


template <typename T>
ImVec2 ResponsiveSize(ImVec2 size, T mulwide, T multall) {
    return ImVec2(size.x * mulwide, size.y * multall);
}

class Menu 
{
private:
    bool IsOpen;
    int page;
    bool bWatermark;

    struct Button {
        const char* btnLable;
        std::string status;
        char* lastupd;
    };

    std::vector<Button> Buttons = {
        { "Player", "", nullptr },
        { "ESP", "", nullptr },
        { "Misc", "", nullptr },
        { "Config", "", nullptr },
        { "Debug", "", nullptr }
    };

public:
    Menu();
    ~Menu();
    bool IsOpened();
    bool SetIsOpen(bool boolean);
    void RealCursorShow();
    void SetUpColors(ImGuiStyle& style, ImVec4* colors, float windowSize[]);
    void StyleColors(ImGuiStyle& style, ImVec4* colors, ImVec2 windowSize);

    // https://github.com/ocornut/imgui/issues/4356#issuecomment-1535547717
    void PreventMoveOutOfWndBounds(const char* wndName);

    void Render();
};
