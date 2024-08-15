#pragma once
#include <includes.h>
#include <SDK.hpp>
#include <globals.h>
#include <SDK/TsAnimNotifyReSkillEvent_parameters.hpp>

using tProcessEvent = void(__thiscall*)(UObject*, UFunction*, void*);

class HitMultiplier
{
public:
	void HandleKeys();
	void Draw();
	void Call(UObject* Object, UFunction* Function, void* Parms, tProcessEvent oProcessEvent);
};



inline void HitMultiplier::Draw() {
	ImGui::Checkbox("Multi Hit", &config::multihit::enabled);
	if (config::multihit::enabled) {
		ImGui::BeginChild(2, ImVec2(0, 100), 1);
		ImGui::Text("Hit multiplier");
		ImGui::SliderInt("##Hit multiplier", &config::multihit::hits, config::multihit::min_hits, config::multihit::max_hits);
		ImGui::EndChild();
	}
}

inline void HitMultiplier::Call(UObject* Object, UFunction* Function, void* Parms, tProcessEvent oProcessEvent) {

	APawn* MyPawn = globals::AcknowledgedPawn;

	if (Function == globals::tfuncs::ReSkillEvent_C) {
		printf("Object [%s] MyPawn [%s] Function [%s]\n", Object->GetName().c_str(), MyPawn->GetName().c_str(), Function->GetName().c_str());

		SDK::Params::TsAnimNotifyReSkillEvent_C_K2_Notify* parameters = (SDK::Params::TsAnimNotifyReSkillEvent_C_K2_Notify*)Parms;
		SDK::USkeletalMeshComponent* meshComp = parameters->MeshComp;

		if (meshComp && meshComp->GetOwner() == MyPawn) {
			for (auto i = 0; i < config::multihit::hits; i++) {
				oProcessEvent(Object, Function, Parms);
			}
		}
		return;
	}
}

// i declarate here cause im too lazy do that in another place 
inline HitMultiplier multihit;