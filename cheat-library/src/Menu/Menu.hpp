#pragma once
#include <string>
#include <vector>
#include <windows.h>
#include <thread>
#include <imgui_internal.h>
#include <imgui.h>
#include <Features/Features.h>
#include <globals.h>

template <typename T>
ImVec2 ResponsiveSize(ImVec2 size, T mulwide, T multall) {
    return ImVec2(size.x * mulwide, size.y * multall);
}


class Menu
{
private:
    int page = 0;
    bool bWatermark = true;

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
        { "Debug", "", nullptr },
    };
public:
    bool bShowBuild = true;
    bool IsOpen = false;


public:
    void RealCursorShow();
    void Setup();
    void SetUpColors(ImGuiStyle& style, ImVec4* colors, ImVec2 windowSize);
    void StyleColors(ImGuiStyle& style, ImVec4* colors, ImVec2 windowSize);

    // https://github.com/ocornut/imgui/issues/4356#issuecomment-1535547717
    void PreventMoveOutOfWndBounds(const char* wndName);

    void Render();
    void RenderWatermark();
    // Title, Text to show, submit text, bool open
    //void ShowCenteredPopupSubmit(const char* title, const char* text, const char* submit_text, bool* open);
};


