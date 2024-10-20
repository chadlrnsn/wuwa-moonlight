#pragma once

#include <globals.h>
#include <SDK/TsAnimNotifyStateCounterAttack_parameters.hpp>

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

//	if (Function == FN_TsAnimNotifyStateCounterAttack_C) {
//
//		SDK::Params::TsAnimNotifyStateCounterAttack_C_K2_NotifyBegin* parameters = (SDK::Params::TsAnimNotifyStateCounterAttack_C_K2_NotifyBegin*)Parms;
//		SDK::USkeletalMeshComponent* meshComp = parameters->MeshComp;
//		
//
//		bool not_local_called = meshComp != PlayerController->Character->Mesh;
//
//		//if (not_local_called) {
//			parameters->ReturnValue = NULL;
//
//#ifdef _DEBUG
//			printf("GodMode: %s %s\n", parameters->Animation->GetFullName().c_str(), Function->GetFullName().c_str());
//#endif
//			return;
//		//}
//	}
}

inline GodMode godmode;