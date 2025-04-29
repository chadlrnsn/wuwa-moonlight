#include "Tooltip.hpp"

bool ImGui::Tooltip(const char* desc)
{
    ImGui::TextDisabled("[?]");
    if (ImGui::BeginItemTooltip())
    {
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
        return true;
    }

	return false;
}

bool ImGui::WarningTooltip(const char* desc)
{
    ImVec4 orangeColor = ImVec4(1.0f, 0.5f, 0.0f, 1.0f);
    ImGui::PushStyleColor(ImGuiCol_Text, orangeColor);
    ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[1]); // Using wide font
    ImGui::Text("[!]");
    ImGui::PopFont();
    ImGui::PopStyleColor();
    
    if (ImGui::BeginItemTooltip())
    {
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::PushStyleColor(ImGuiCol_Text, orangeColor);
        ImGui::TextUnformatted(desc);
        ImGui::PopStyleColor();
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
        return true;
    }

    return false;
}
