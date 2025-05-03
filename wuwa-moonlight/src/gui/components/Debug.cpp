#include "Debug.hpp"

void CheatDebugComponent::Draw()
{
    ImGui::Spacing();
    ImGui::NewLine();
    ImGui::Spacing();

    if (ImGui::Button("Reset cursor")) {
        SDK::UKuroStaticLibrary::SetCursorVisibility(true);
        SDK::UKuroStaticLibrary::ShowSoftwareCursor(false);
        LOG_INFO("Cursor should be reset");
    }
}
