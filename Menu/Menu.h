#pragma once
#include <string>
#include <vector>
#include "../imgui/imgui_internal.h"
#include "../imgui/imgui.h"
#include <windows.h>
#include "../kiero/kiero.h"
#include "Settings.h"


void GetWindowClientSize(HWND hwnd, int& width, int& height)
{
    RECT rect;
    GetClientRect(hwnd, &rect);
    width = rect.right - rect.left;
    height = rect.bottom - rect.top;
}

namespace Menu 
{
    bool IsOpened = true;

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

    void SetUpColors()
    {
        ImGuiStyle& style = ImGui::GetStyle();
        style.WindowMinSize = ImVec2(600, 350);

        style.Colors[ImGuiCol_WindowBg] = ImColor(25, 20, 20);
        style.Colors[ImGuiCol_ChildBg] = ImColor(30, 24, 24);
        style.Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
        //Header
        style.Colors[ImGuiCol_Header] = ImColor(30, 200, 100);
        style.Colors[ImGuiCol_HeaderHovered] = ImColor(40, 215, 96);
        style.Colors[ImGuiCol_HeaderActive] = ImColor(30, 215, 96);
        //buttons
        style.Colors[ImGuiCol_Button] = ImColor(25, 215, 96);
        style.Colors[ImGuiCol_ButtonHovered] = ImColor(40, 215, 96);
        style.Colors[ImGuiCol_ButtonActive] = ImColor(30, 190, 96);
        //checkboxes
        style.Colors[ImGuiCol_CheckMark] = ImColor(0, 0, 0);
        style.Colors[ImGuiCol_FrameBg] = ImColor(25, 215, 96, 240);
        style.Colors[ImGuiCol_FrameBgActive] = ImColor(25, 215, 96);
        style.Colors[ImGuiCol_FrameBgHovered] = ImColor(20, 250, 90);
    }

    void StyleColorsOrangeDark(ImGuiStyle& style, ImVec4* colors, float windowSize[1]) {
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

    void Init()
    {

        static int page = 0;

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
            
            //Button data = Buttons[page];

            switch (page) {

                case 0:
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

                    //ImGui::Checkbox("camerachack", &Legit::camerachack);
                    //if (Legit::camerachack) {
                    //    ImGui::Spacing();
                    //    ImGui::SameLine();
                    //    ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);
                    //    ImGui::SameLine();
                    //    ImGui::Spacing();

                    //    ImGui::Text("Camera distance");
                    //    ImGui::SliderFloat(" ", &Hacks::Legit::camerachack_float, Hacks::Legit::camerachack_floatMin, Hacks::Legit::camerachack_floatMax);

                    //    ImGui::Spacing();
                    //    ImGui::SameLine();
                    //    ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);
                    //    ImGui::SameLine();
                    //    ImGui::Spacing();
                    //}
                    break;

                case 1: 
                    ImGui::Text("in dev.");
                    //ImGui::Checkbox("SpeedHack", &Hacks::semirage::speedhack_cb);
                    //if (Hacks::semirage::speedhack_cb) {
                    //    ImGui::Spacing();
                    //    ImGui::SameLine();
                    //    ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);
                    //    ImGui::SameLine();
                    //    ImGui::Spacing();
                    //    ImGui::LabelText("more then 20\ncause ban", "Speedhack");
                    //    ImGui::SliderInt(" ",
                    //        &Hacks::semirage::speedhack,
                    //        Hacks::semirage::speedhackMin,
                    //        Hacks::semirage::speedhackMax);
                    //    ImGui::Spacing();
                    //    ImGui::SameLine();
                    //    ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);
                    //    ImGui::SameLine();
                    //    ImGui::Spacing();
                    //}
                    break;

                case 2: 
                    ImGui::Text("in dev.");

                    //ImGui::Checkbox("Rapid", &Hacks::rage::rapidbool);
                    //if (Hacks::rage::rapidbool) {
                    //    ImGui::LabelText(" ", "Rapid hits per animation");
                    //    ImGui::SliderInt(" ",
                    //        &Hacks::rage::rapidhits,
                    //        Hacks::rage::rapidhitsmin,
                    //        Hacks::rage::rapidhitsmax);
                    //}
                    //ImGui::Text("Teleport hack");
                    //ImGui::Checkbox("Teleport hack", &Hacks::rage::teleport);

                    //if (Hacks::rage::teleport) {
                    //    // ImGui::InputFloat("X Coord", &Hacks::rage::tpPos::x);
                    //    // ImGui::InputFloat("Y Coord", &Hacks::rage::tpPos::y);
                    //    // ImGui::InputFloat("Z Coord", &Hacks::rage::tpPos::z);

                    //    ImGui::BeginChild("##LeftSide", ImVec2(300, ImGui::GetContentRegionAvail().x));
                    //    ImGui::Text("Player X:");
                    //    ImGui::Text("Player Y:");
                    //    ImGui::Text("Player Z:");
                    //    ImGui::EndChild();
                    //}
                    break;

                case 3:
                    ImGui::Text("in dev.");
                    break;


            } // switch

            ImGui::EndChild();
            ImGui::PopStyleColor();

        } // Begin
        ImGui::End();
    }
};
