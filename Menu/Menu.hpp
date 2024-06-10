#pragma once
#include <string>
#include <vector>
#include <windows.h>
#include <thread>
#include "../imgui/imgui_internal.h"
#include "../imgui/imgui.h"
#include "../Features/Features.h"

template <typename T>
ImVec2 ResponsiveSize(ImVec2 size, T mulwide, T multall) {
    return ImVec2(size.x * mulwide, size.y * multall);
}


class Menu 
{
private:
    bool IsOpen = false;
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
        { "Debug", "", nullptr }
    };

public:
    bool IsOpened();
    bool SetIsOpen(bool boolean);
    void RealCursorShow();
    void SetUpColors(ImGuiStyle& style, ImVec4* colors, ImVec2 windowSize);
    void StyleColors(ImGuiStyle& style, ImVec4* colors, ImVec2 windowSize);

    // https://github.com/ocornut/imgui/issues/4356#issuecomment-1535547717
    void PreventMoveOutOfWndBounds(const char* wndName);

    void Render();
    void RenderWatermark();
    // Title, Text to show, submit text, bool open
    //void ShowCenteredPopupSubmit(const char* title, const char* text, const char* submit_text, bool* open);
};


static GodMode god;
static SpeedHack speedhack;
static ESP esp;
static Fly fly;