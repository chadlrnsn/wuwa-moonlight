#pragma once
#include "Settings.h"
#include "../imgui/imgui.h"
#include <iostream>
#include "Menu.h"
#include <thread>
#include <vector>

namespace UIWaterMark 
{
    void Watermark()
    {
        if (!Settings::Watermark)
            return;


        auto time = std::chrono::system_clock::now();
        std::time_t formatedtime = std::chrono::system_clock::to_time_t(time);


        ImGui::SetNextWindowPos(ImVec2(15,15));
        ImGui::SetNextWindowSize(ImVec2());

        ImGui::Begin("watermark", nullptr,
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoTitleBar |
            ImGuiWindowFlags_NoBackground | 
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoScrollbar |
            ImGuiWindowFlags_::ImGuiWindowFlags_NoBringToFrontOnFocus |
            ImGuiWindowFlags_::ImGuiWindowFlags_NoBackground | 
            ImGuiWindowFlags_::ImGuiWindowFlags_NoNavFocus |
            ImGuiWindowFlags_::ImGuiWindowFlags_NoNav
        );
     
        ImGui::Text("By chadlrnsn | discord: chadlrnsn | %s", std::ctime(&formatedtime));
        ImGui::End();
    }

}
