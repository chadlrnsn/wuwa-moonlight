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

	if (Function == FN_TsAnimNotifyReSkillEvent_C) {

		SDK::Params::TsAnimNotifyReSkillEvent_C_K2_Notify* parameters = (SDK::Params::TsAnimNotifyReSkillEvent_C_K2_Notify*)Parms;
		SDK::USkeletalMeshComponent* meshComp = parameters->MeshComp;

		bool not_local_called = meshComp != PlayerController->Character->Mesh;

		if (not_local_called) {
			parameters->Animation->RateScale = 0;
			parameters->ReturnValue = false;

#ifdef _DEBUG
			printf("Not local called and attack %s\n", parameters->Animation->GetFullName().c_str());
#endif
			return oProcessEvent(Object, Function, parameters);
		}
	}
}

inline GodMode godmode;