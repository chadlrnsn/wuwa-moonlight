#pragma once
#include <string>
#include <vector>
#include <windows.h>
#include <thread>
#include <Singleton.hpp>

#ifndef IMGUI_DEFINE_MATH_OPERATORS
#define IMGUI_DEFINE_MATH_OPERATORS
#endif // !IMGUI_DEFINE_MATH_OPERATORS

#include <gui/Context.hpp>
#include "imgui_internal.h"
#include "imgui.h"

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
ImVec2 ResponsiveSize(ImVec2 size, T mulwide, T multall)
{
    return ImVec2(size.x * mulwide, size.y * multall);
}

class IMenu {
public:
    virtual void RealCursorShow() = 0;
    virtual void Setup() = 0;
    virtual void SetUpColors(ImGuiStyle& style, ImVec4* colors) = 0;
    virtual bool IsOpen() const = 0;
    virtual void SetIsOpen(bool IsOpen) = 0;
    virtual void Toggle() = 0;
    
    // https://github.com/ocornut/imgui/issues/4356#issuecomment-1535547717
    virtual void PreventMoveOutOfWndBounds(const char* wndName) = 0;
    virtual void RenderMenu() = 0;
    virtual void RenderWatermark() = 0;
    virtual void RenderNotify() = 0;
};

class MenuBase : public IMenu
{
protected:
    bool bWatermark = true;
    bool bIsOpen = false;
    bool bShowBuild = true;
};

class Menu : public MenuBase
{
private:

    enum Headers
    {
        PLAYER,
        ESP,
        MISC,
        CONFIG,
        //DEBUG
        HEADERS_COUNT
    };

    float baseFontSize = 14.0f;
    float iconFontSize = baseFontSize * 2.0f / 3.0f;
    bool bOnceStyle = false;
    bool bOnceScaledMenu = false;
    bool bGameCursorShow{false};
    bool bGameCursorShowOnce{false};

    using StateChangeCallback = std::function<void(bool newState)>;
    std::vector<StateChangeCallback> stateChangeCallbacks;

public:
    void RealCursorShow();
    void Setup();
    void SetUpColors(ImGuiStyle& style, ImVec4* colors);
    void PreventMoveOutOfWndBounds(const char* wndName);
    void RenderMenu();
    void RenderWatermark();
    bool IsOpen() const;
    void SetIsOpen(bool isOpen);
    void Toggle();
    void RenderNotify() override {};

    void HandleKey();
    void AddStateChangeCallback(StateChangeCallback callback);
    bool ShowCursor(bool bToggle);
};

inline ImFont* font_regular;
inline ImFont* font_medium;
inline ImFont* font_bold;
inline ImFont* font_title;
inline ImFont* font_icons;

inline std::shared_ptr<Menu> g_menu = std::make_shared<Menu>();
