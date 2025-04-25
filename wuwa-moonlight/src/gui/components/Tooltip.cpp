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
