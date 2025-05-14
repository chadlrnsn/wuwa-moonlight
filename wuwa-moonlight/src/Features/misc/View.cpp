#include "View.hpp"

void CView::Run()
{
    if (!bEnable) return;

    if (!globals::player_controller) return;
    
    if (bFOV) {
        globals::player_controller->FOV(FOV.Current);
    }

    // if (bAspectRatio) {
    //     auto pActor = reinterpret_cast<uintptr_t*>(globals::player_controller->PlayerCameraManager->AnimCameraActor);
    //     if (pActor != nullptr)
    //     {
    //         globals::player_controller->PlayerCameraManager->AnimCameraActor->AspectRatio = AspectRatio.Current;
    //     }
    // }
}

void CView::Draw()
{
    ImGui::Checkbox("View changer", &bEnable);
    ImGui::BeginDisabled(!bEnable); 
    {
        ImGui::Checkbox("FOV Changer", &bFOV);
        ImGui::SliderFloat("## Fov changer", &FOV.Current, FOV.Min, FOV.Max);

        // ImGui::Checkbox("Aspect ratio Changer", &bAspectRatio);
        // ImGui::SliderFloat("## Aspect ratio", &AspectRatio.Current, AspectRatio.Min, AspectRatio.Max);
    }
    ImGui::EndDisabled();
}
