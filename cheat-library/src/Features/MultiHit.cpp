#include "MultiHit.h"
#include "PE_Hook/vmthook.h"

using ProcessEvent = void(__thiscall*)(UObject*, UFunction*, void*);
static ProcessEvent ProcessEventOriginal = nullptr;


void __stdcall ProcessEventHooked(UObject* object, UFunction* function, void* parms) {
    printf("ProcessEvent Function Called: %s\n", function->GetName());

    ProcessEventOriginal(object, function, parms);
}



void HitMultiplier::DrawMenuItems() {
    ImGui::Checkbox("Multi Hit", &bEnable);
    if (bEnable) {
        ImGui::BeginChild(2, ImVec2(0, 100), 1);
        ImGui::Text("Hit multiplier");
        ImGui::SliderInt("##Hit multiplier", &iCurrent, iMin, iMax);
        ImGui::EndChild();
    }
}



void HitMultiplier::Run(void** args, size_t numArgs) {
    if (!Initalized || numArgs != 1) {
        Destroy();
        return;
    }

    APawn* Pawn = (APawn*)args[0];
    UWorld* World = (UWorld*)args[1];


}
