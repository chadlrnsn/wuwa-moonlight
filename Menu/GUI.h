#pragma once
#include "Menu.hpp"
#include "../Features/Features.h"
#include "Watermark.h"

namespace CS
{
    bool godmode = false;
}

void Menu::Render() {
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
            ImGui::Checkbox("GodMode", &CS::godmode);
            //ImGui::Checkbox("RapidFire", &Settings::Player::Rapidfire::enabled);
            //ImGui::Checkbox("SpeedHack", &Settings::Player::Speed::enabled);

            // Speedhack
            //if (Settings::Player::Speed::enabled) {

            //    ImGui::SliderFloat("TimeDilation",
            //        &Settings::Player::Speed::speed,
            //        Settings::Player::Speed::min,
            //        Settings::Player::Speed::max,
            //        "%.3f");
            //}

            break;

        case 1: // Esp
            ImGui::Text("in dev.");
            break;

        case 2: // Misc
            ImGui::Text("in dev.");
            break;

        case 3: // Config 
            ImGui::Text("in dev.");
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