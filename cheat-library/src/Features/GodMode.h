#pragma once
#include <includes.h>
#include <globals.h>
#include <SDK/TsAnimNotifyReSkillEvent_parameters.hpp>
using namespace globals;

using tProcessEvent = void(__thiscall*)(UObject*, UFunction*, void*);

class GodMode
{
public:
	void HandleKeys();
	void Draw();
	void Call(UObject* Object, UFunction* Function, void* Parms, tProcessEvent oProcessEvent);
};



inline void GodMode::Draw() {
	ImGui::Checkbox("God Mode", &config::godmode::enabled);
}

inline void GodMode::Call(UObject* Object, UFunction* Function, void* Parms, tProcessEvent oProcessEvent) {

	APawn* MyPawn = globals::AcknowledgedPawn;

	if (Function == globals::tfuncs::ReSkillEvent_C) {
		//printf("Object [%s] MyPawn [%s] Function [%s]\n", Object->GetName().c_str(), MyPawn->GetName().c_str(), Function->GetName().c_str());

		SDK::Params::TsAnimNotifyReSkillEvent_C_K2_Notify* parameters = (SDK::Params::TsAnimNotifyReSkillEvent_C_K2_Notify*)Parms;
		SDK::USkeletalMeshComponent* meshComp = parameters->MeshComp;

		if (meshComp && meshComp->GetOwner() != MyPawn) {
			printf("Prevented damage to anyone else\n");
			return;
		}
	}
}

// i declarate here cause im too lazy do that in another place 
inline GodMode godmode;