#include "Menu.h"

void Menu::RealCursorShow() {
    ImGui::GetMouseCursor();
    ImGui::SetMouseCursor(ImGuiMouseCursor_Arrow);
    ImGui::GetIO().WantCaptureMouse = Menu::IsOpened;
    ImGui::GetIO().MouseDrawCursor = Menu::IsOpened;
}

void Menu::SetUpColors(ImGuiStyle& style, ImVec4* colors, float windowSize[]) {
    style.WindowMinSize = ImVec2(600, 350);

    colors[ImGuiCol_WindowBg] = ImColor(25, 20, 20);
    colors[ImGuiCol_ChildBg] = ImColor(30, 24, 24);
    colors[ImGuiCol_Text] = ImColor(255, 255, 255);
    //Header
    colors[ImGuiCol_Header] = ImColor(30, 138, 200);
    colors[ImGuiCol_HeaderHovered] = ImColor(40, 215, 192);
    colors[ImGuiCol_HeaderActive] = ImColor(30, 116, 215);
    //buttons
    colors[ImGuiCol_Button] = ImColor(25, 145, 215);
    colors[ImGuiCol_ButtonHovered] = ImColor(25, 104, 215);
    colors[ImGuiCol_ButtonActive] = ImColor(100, 161, 222);
    //checkboxes
    colors[ImGuiCol_CheckMark] = ImColor(0, 0, 0);
    colors[ImGuiCol_FrameBg] = ImColor(25, 174, 215, 200);
    colors[ImGuiCol_FrameBgActive] = ImColor(25, 215, 212);
    colors[ImGuiCol_FrameBgHovered] = ImColor(20, 250, 200);

    style.WindowRounding = 5.3f;
    style.FrameRounding = 2.3f;
    style.ScrollbarRounding = 0;
    style.GrabRounding = 2.3f;
    style.TabRounding = 2.3f;

    style.WindowMinSize = ImVec2(windowSize[0], windowSize[1]);
    style.ChildRounding = 5.0f;
}

void Menu::StyleColorsOrangeDark(ImGuiStyle& style, ImVec4* colors, float windowSize[1]) {
    // Colors
    colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.14f, 0.14f, 0.14f, 0.95f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.14f, 0.14f, 0.14f, 0.85f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_Border] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.27f, 0.27f, 0.27f, 1.00f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.22f, 0.22f, 0.22f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.45f, 0.45f, 0.45f, 1.00f);
    colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 0.65f, 0.00f, 1.00f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
    colors[ImGuiCol_Button] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.45f, 0.45f, 0.45f, 1.00f);
    colors[ImGuiCol_Header] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.45f, 0.45f, 0.45f, 1.00f);
    colors[ImGuiCol_Separator] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.45f, 0.45f, 0.45f, 1.00f);
    colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 0.65f, 0.00f, 0.25f);
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 0.65f, 0.00f, 0.67f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 0.65f, 0.00f, 0.95f);
    colors[ImGuiCol_Tab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
    colors[ImGuiCol_TabActive] = ImVec4(0.45f, 0.45f, 0.45f, 1.00f);
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.45f, 0.45f, 0.45f, 1.00f);
    //colors[ImGuiCol_DockingPreview] = ImVec4(1.00f, 0.65f, 0.00f, 0.70f);
    //colors[ImGuiCol_DockingEmptyBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.65f, 0.00f, 1.00f);
    colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.65f, 0.00f, 1.00f);
    colors[ImGuiCol_TableHeaderBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
    colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.23f, 1.00f);
    colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 0.65f, 0.00f, 0.06f);
    colors[ImGuiCol_TextSelectedBg] = ImVec4(1.00f, 0.65f, 0.00f, 0.35f);
    colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 0.65f, 0.00f, 0.95f);
    colors[ImGuiCol_NavHighlight] = ImVec4(1.00f, 0.65f, 0.00f, 1.00f);
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 0.65f, 0.00f, 1.00f);
    colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.14f, 0.14f, 0.14f, 0.35f);

    // Style
    style.WindowRounding = 5.3f;
    style.FrameRounding = 2.3f;
    style.ScrollbarRounding = 0;
    style.GrabRounding = 2.3f;
    style.TabRounding = 2.3f;

    style.WindowMinSize = ImVec2(windowSize[0], windowSize[1]);
    style.ChildRounding = 5.0f;
}


void Menu::PreventMoveOutOfWndBounds(const char* wndName) {
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


void Menu::Init() {
    if (ImGui::Begin(" ", 0, ImGuiWindowFlags_NoTitleBar /*  | ImGuiWindowFlags_NoResize */)) {
        ImGui::PushStyleColor(ImGuiCol_Border, ImColor(0, 0, 0, 255).Value);
        if (ImGui::BeginChild("##LeftSide", ImVec2(120, ImGui::GetContentRegionAvail().y), 1))
        {

            for (unsigned int i = 0; i < Buttons.size(); ++i) {

                bool selected = (page == i);
                auto windowvars = ImGuiStyleVar_SelectableTextAlign;

                ImGui::PushStyleVar(windowvars, ImVec2(0.5f, 0.5f));

                if (ImGui::Selectable(Buttons[i].btnLable, &selected, 0, ImVec2(ImGui::GetContentRegionAvail().x, 20)))
                    page = i;

                ImGui::PopStyleVar();

                if (selected)
                    ImGui::SetItemDefaultFocus();

            }
        }

        ImGui::EndChild();

        ImGui::SameLine(0);
        ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);
        ImGui::SameLine(0);

        ImGui::BeginChild("##RightSide", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y), true);

        switch (page) {

        case 0: // Player
            ImGui::Checkbox("GodMode", &Settings::Player::god);
            ImGui::Checkbox("RapidFire", &Settings::Player::Rapidfire::enabled);
            ImGui::Checkbox("SpeedHack", &Settings::Player::Speed::enabled);

            // Speedhack
            if (Settings::Player::Speed::enabled) {

                ImGui::SliderFloat("TimeDilation",
                    &Settings::Player::Speed::speed,
                    Settings::Player::Speed::min,
                    Settings::Player::Speed::max,
                    "%.3f");
            }

            break;

        case 1: // Esp
            ImGui::Text("in dev.");
            break;

        case 2: // Misc
            ImGui::Text("in dev.");
            break;

        case 3: // Config 
            ImGui::Text("in dev.");

            // Fix closing window after unloading dll

            /*
            if (ImGui::Button("Unload dll", ResponsiveSize(windowSize, 0.2, 0.1))) {
                unload_dll("wuwa-moonlight.dll");
            }
            */
            break;

        case 4: // Debug
            ImGui::Text("in dev.");
            break;

        } // Switch

        ImGui::EndChild();
        ImGui::PopStyleColor();

    } // Begin
    ImGui::End(); // Render end
}