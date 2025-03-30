#pragma once
#include "..\includes.h"
#include "SDK.hpp"
#include "..\globals.h"
#include "TsAnimNotifyReSkillEvent_parameters.hpp"
#include "TsAnimNotifyReSkillEvent_classes.hpp"

using tProcessEvent = void(__thiscall*)(UObject*, UFunction*, void*);

class HitMultiplier
{
public:
    void HandleKeys();
    void Draw();
    void Call(UObject* Object, UFunction* Function, void* Parms, tProcessEvent oProcessEvent);
};

inline HitMultiplier multihit;

inline void HitMultiplier::Draw() {
    ImGui::Checkbox("Multi Hit", &config::multihit::enabled);
    if (config::multihit::enabled) {
        ImGui::BeginChild(2, ImVec2(0, 100), true);
        ImGui::Text("Hit multiplier");
        ImGui::SliderInt("##Hit multiplier", &config::multihit::hits, config::multihit::min_hits, config::multihit::max_hits);
        ImGui::EndChild();
    }
}

inline void HitMultiplier::Call(UObject* Object, UFunction* Function, void* Parms, tProcessEvent oProcessEvent) {
    if (Function && std::string(Function->GetName()) == "K2_Notify") {
        printf("Object [%s] MyPawn [%s] Function [%s]\n",
            Object->GetName().c_str(),
            pawn ? pawn->GetName().c_str() : "NULL",
            Function->GetName().c_str()
        );
        // was called improperly
        SDK::Params::TsAnimNotifyReSkillEvent_C_K2_Notify* parameters =
            reinterpret_cast<SDK::Params::TsAnimNotifyReSkillEvent_C_K2_Notify*>(Parms);

        if (!parameters || !parameters->MeshComp) {
            oProcessEvent(Object, Function, Parms);
            return;
        }
        if (player_controller && player_controller->Character &&
            parameters->MeshComp == player_controller->Character->Mesh) {

            for (int i = 0; i < config::multihit::hits; i++) {
                oProcessEvent(Object, Function, Parms);
            }
        }
    }
    else {
        oProcessEvent(Object, Function, Parms);
    }
}
