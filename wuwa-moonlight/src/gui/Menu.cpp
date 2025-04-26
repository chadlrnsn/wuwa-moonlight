#include "Menu.hpp"
#include <gui/assets/fonts/font.h>
#include <imgui.h>
#include <chrono>
#include <iostream>
#include <imgui_internal.h>

#include <Features/Features.h>



void Menu::RealCursorShow()
{
    ImGui::GetMouseCursor();
    ImGui::SetMouseCursor(ImGuiMouseCursor_Arrow);
    ImGui::GetIO().WantCaptureMouse = bIsOpen;
    ImGui::GetIO().MouseDrawCursor = bIsOpen;
}

void Menu::Setup()
{
    if (!bOnceStyle) {
        ImGuiIO& io = ImGui::GetIO();
        (void)io;
        ImGuiStyle& style = ImGui::GetStyle();
        ImVec4* colors = style.Colors;
        ImVec2 whole_content_size = io.DisplaySize;
        whole_content_size.x = whole_content_size.x * 0.3;
        whole_content_size.y = whole_content_size.y * 0.2;

        // Theme initialization
        SetUpColors(style, colors);

        ImFontConfig font_config;
        font_config.PixelSnapH = false;
        font_config.OversampleH = 5;
        font_config.OversampleV = 5;
        font_config.RasterizerMultiply = 1.2f;

        ImFontConfig icontfont_config;
        icontfont_config.MergeMode = true;
        icontfont_config.GlyphMinAdvanceX = iconFontSize;
        icontfont_config.PixelSnapH = true;

        static const ImWchar ranges[] =
        {
            0x0020, 0x00FF, // Basic Latin + Latin Supplement
            0x0400, 0x052F, // Cyrillic + Cyrillic Supplement
            0x2DE0, 0x2DFF, // Cyrillic Extended-A
            0xA640, 0xA69F, // Cyrillic Extended-B
            0xE000, 0xE226, // icons
            0 };

        //static const ImWchar iconRanges[] =
        //{
        //    ICON_MIN_FA,
        //    ICON_MAX_16_FA, // awesome font icons
        //    0,
        //};

        io.Fonts->AddFontDefault();
        font_regular = io.Fonts->AddFontFromMemoryTTF(RobotoRegular, sizeof(RobotoRegular), 15.0f, &font_config, ranges);
        font_medium = io.Fonts->AddFontFromMemoryTTF(RobotoMedium, sizeof(RobotoMedium), 15.0f, &font_config, ranges);
        font_bold = io.Fonts->AddFontFromMemoryTTF(RobotoBold, sizeof(RobotoBold), 15.0f, &font_config, ranges);
        font_title = io.Fonts->AddFontFromMemoryTTF(RobotoBold, sizeof(RobotoBold), 25.0f, &font_config, ranges);
        //icons = io.Fonts->AddFontFromFileTTF(FONT_ICON_FILE_NAME_FAS, iconFontSize, &icontfont_config, iconRanges);

        io.FontDefault = font_regular;
        bOnceStyle = true; // is initialized = true
    }
}

void Menu::SetUpColors(ImGuiStyle& style, ImVec4* colors)
{
    ImColor hovered = { 31, 110, 171 };
    ImColor Transparented = { 0, 0, 0, 255 };
    colors[ImGuiCol_WindowBg] = ImColor(20, 23, 25);
    colors[ImGuiCol_ChildBg] = ImColor(24, 28, 30);
    colors[ImGuiCol_Text] = ImColor(255, 255, 255);

    // Header
    colors[ImGuiCol_Header] = ImColor(30, 138, 200);
    colors[ImGuiCol_HeaderHovered] = hovered;
    colors[ImGuiCol_HeaderActive] = ImColor(30, 116, 215);

    // buttons
    colors[ImGuiCol_Button] = ImColor(25, 145, 215);
    colors[ImGuiCol_ButtonHovered] = hovered;
    colors[ImGuiCol_ButtonActive] = ImColor(100, 161, 222);

    // checkboxes
    colors[ImGuiCol_CheckMark] = ImColor(0, 0, 0);
    colors[ImGuiCol_FrameBg] = ImColor(25, 158, 215, 200);
    colors[ImGuiCol_FrameBgActive] = ImColor(25, 164, 215);
    colors[ImGuiCol_FrameBgHovered] = ImColor(20, 212, 250);

    colors[ImGuiCol_Border] = Transparented;

    style.WindowRounding = 10.0f;
    style.FrameRounding = 5.0f;
    style.ScrollbarRounding = 5.0f;
    style.GrabRounding = 2.3f;
    style.TabRounding = 2.3f;

    // style.WindowMinSize = { 600,300 };
    style.ChildRounding = 5.0f;
}

void Menu::PreventMoveOutOfWndBounds(const char* wndName)
{
    ImGuiWindow* existingWindow = ImGui::FindWindowByName(wndName);
    if (existingWindow != nullptr)
    {
        bool needsClampToScreen = false;
        ImVec2 targetPos = existingWindow->Pos;
        if (existingWindow->Pos.x < 0.0f)
        {
            needsClampToScreen = true;
            targetPos.x = 0.0f;
        }
        else if (existingWindow->Size.x + existingWindow->Pos.x > ImGui::GetMainViewport()->Size.x)
        {
            needsClampToScreen = true;
            targetPos.x = ImGui::GetMainViewport()->Size.x - existingWindow->Size.x;
        }
        if (existingWindow->Pos.y < 0.0f)
        {
            needsClampToScreen = true;
            targetPos.y = 0.0f;
        }
        else if (existingWindow->Size.y + existingWindow->Pos.y > ImGui::GetMainViewport()->Size.y)
        {
            needsClampToScreen = true;
            targetPos.y = ImGui::GetMainViewport()->Size.y - existingWindow->Size.y;
        }

        if (needsClampToScreen) // Necessary to prevent window from constantly undocking itself if docked.
        {
            ImGui::SetNextWindowPos(targetPos, ImGuiCond_Always);
        }
    }
}

void Menu::RenderMenu()
{
    if (!IsOpen()) return;

    static Headers tab = PLAYER;
    const char* tab_names[] = { "PLAYER", "ESP", "MISC", "CONFIG", /*"DEBUG"*/ };

    ImVec2 wndSize = ImGui::GetIO().DisplaySize;
    ImVec2 minSize(600, 300);
    ImVec2 maxSize(wndSize);

    // Fix the next window size
    ImGui::SetNextWindowSizeConstraints(minSize, maxSize);
    if (ImGui::Begin("Moonlight", nullptr, /*ImGuiWindowFlags_NoDecoration |*/ ImGuiWindowFlags_NoTitleBar))
    {
        ImVec2 pos = ImGui::GetWindowPos();
        ImVec2 size = ImGui::GetWindowSize();

        ImVec2 wndSize = ImGui::GetWindowSize();

        ImGuiStyle style = ImGui::GetStyle();
        ImDrawList* draw = ImGui::GetWindowDrawList();

        float minWidth = 120;

        ImVec2 mainLeftSize = ImVec2(ImGui::GetContentRegionAvail().x * 0.16f, ImGui::GetContentRegionAvail().y);
        mainLeftSize.x = ImClamp(mainLeftSize.x, minWidth, wndSize.x);

        ImGui::BeginChild("MainLeft", mainLeftSize, 0);
        {

            ImVec2 leftTopChildSize = ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y * 0.16f);
            ImGui::BeginChild("LeftSide1", leftTopChildSize, false);

            ImGui::PushFont(font_title);

            ImVec2 textSize = ImGui::CalcTextSize("Moonlight");

            float posX = (leftTopChildSize.x - textSize.x) * 0.5f;
            float posY = (leftTopChildSize.y - textSize.y) * 0.5f;

            ImGui::SetCursorPos(ImVec2(posX, posY));

            ImGui::TextColored(ImColor(84, 160, 227), "Moonlight");

            ImGui::PopFont();
            ImGui::EndChild();

            if (ImGui::BeginChild("LeftSide2", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y), 0))
            {
                for (unsigned int i = 0; i < HEADERS_COUNT; ++i)
                {
                    bool selected = (tab == static_cast<Headers>(i));
                    auto windowvars = ImGuiStyleVar_SelectableTextAlign;

                    ImGui::PushStyleVar(windowvars, ImVec2(0.5f, 0.5f));

                    if (ImGui::Selectable(tab_names[i], &selected, 0, ImVec2(ImGui::GetContentRegionAvail().x, 24)))
                        tab = static_cast<Headers>(i);

                    ImGui::PopStyleVar();

                    if (selected)
                        ImGui::SetItemDefaultFocus();
                }
            }
            ImGui::EndChild();
        }
        ImGui::EndChild();
    }

    ImGui::SameLine(0);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(20, 20));

    ImGui::BeginChild("RightSide", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y), 0);

    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Indent(10.0f);

    switch (tab)
    {
    case PLAYER:
        //speedhack.DrawMenuItems();
        //fly.DrawMenuItems();
        //gravityScale.DrawMenuItems();
        //walkFloorZ.DrawMenuItems();
        //walkFloorAngle.DrawMenuItems();
        multihit.Draw();
        // godmode.Draw();

        break;

    case ESP:
        // esp.DrawMenuItems();
        esp.get()->Draw();
        break;

    case MISC:
        fpsUnlock.get()->Draw();
        if (ImGui::Button("Force exit"))
            ExitProcess(0);

        break;

    case CONFIG:
        ImGui::Text("in dev.");
        break;
    } // Switch

    ImGui::Unindent();
    ImGui::Spacing();
    ImGui::Spacing();

    ImGui::EndChild();
    ImGui::PopStyleVar();

    ImGui::End(); // Render end
}

void Menu::RenderWatermark()
{
    if (!bWatermark)
        return;

    auto time = std::chrono::system_clock::now();
    std::time_t formatedtime = std::chrono::system_clock::to_time_t(time);

    ImGui::SetNextWindowPos(ImVec2(15, 15));
    ImGui::SetNextWindowSize({});

    ImGui::Begin("watermark", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoNav);
    ImGui::Text("Moonlight | github.com/chadlrnsn/wuwa-moonlight");
    ImGui::End();
}

bool Menu::IsOpen()
{
    return this->bIsOpen;
}

void Menu::SetIsOpen(bool isOpen)
{
    this->bIsOpen = isOpen;
}

void Menu::Toggle()
{
    this->bIsOpen = !this->bIsOpen;
}

// void Menu::RenderNotify()
// {
//     // Setup style like main window

//     ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 5.f);
//     ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f); // Disable borders

//     // Notifications color setup
//     //ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.10f, 0.10f, 0.10f, 1.00f)); // Background color

//     // Main rendering function
//     ImGui::RenderNotifications();

//     //������������������������������� WARNING �������������������������������
//     // Argument MUST match the amount of ImGui::PushStyleVar() calls
//     ImGui::PopStyleVar(2);
//     // Argument MUST match the amount of ImGui::PushStyleColor() calls
//     //ImGui::PopStyleColor(1);
// }
