#pragma once
#include <includes.h>
#include <globals.h>
#include <SDK/TsAnimNotifyReSkillEvent_parameters.hpp>

using namespace globals;

using namespace SDK;
using tProcessEvent = void(__thiscall*)(UObject*, UFunction*, void*);

class SpeedHack
{
private:

	struct Speed {
		float Speed;
		float MinSpeed;
		float MaxSpeed;
		float Default = 1.0f;
		bool bEnable = false;
	};

	
	Speed rateSpeed		= { 2, -1, 100 };
	Speed animSpeed		= { 2, -1, 100 };
	Speed moveSpeed		= { 5, 1, 30 };
	Speed worldSpeed	= { 1, 0, 5 };

	bool bOnce = false;
	bool bEnable = false;

	// Bindings
	bool bSettingKey = false;
	KeyBindToggle kbToggle = KeyBindToggle(KeyBind::KeyCode::Z);


public:
	void HandleKeys() {
		if (GetAsyncKeyState(kbToggle.toInt()) & 0x1) {
			bEnable = !bEnable;
		}
	}

	// This should be run in the ImGUI draw loop, used to draw anything to the menu
	void DrawMenuItems();

	// This should be run at the top of the ImGUI draw loop, used to render things like ESP, Tracers, and Debug Info
	void Render();

	// This should be run in the feature loop, used to run any acutal feature code like setting a value for godmode
	void Run();
	void Call(UObject*, UFunction*, void*, tProcessEvent);
};



inline void SpeedHack::DrawMenuItems()
{
	ImGui::Checkbox("SpeedHack", &bEnable);
	ImGui::SameLine();
	ImGui::Hotkey("##Global SpeedHack Key", kbToggle, &bSettingKey);

	if (bEnable) {
		ImGui::Text("Speed Multiplier");
		ImGui::Checkbox("Character Dillation", &moveSpeed.bEnable);
		ImGui::SliderFloat("##SpeedMultiplier", &moveSpeed.Speed, moveSpeed.MinSpeed, moveSpeed.MaxSpeed);
		
		ImGui::Text("world Speed Multiplier");
		ImGui::Checkbox("world Dillation", &worldSpeed.bEnable);
		ImGui::SliderFloat("##worldSpeed", &worldSpeed.Speed, worldSpeed.MinSpeed, worldSpeed.MaxSpeed);

		ImGui::Text("Rate Speed (sequences)");
		ImGui::Checkbox("Rate Speed", &rateSpeed.bEnable);
		ImGui::SliderFloat("##RateSpeed", &rateSpeed.Speed, rateSpeed.MinSpeed, rateSpeed.MaxSpeed);
	}
}

inline void SpeedHack::Run()
{
	if (!pawn) return;

	HandleKeys();

	// Character dilation
	if (bEnable)
	{
		pawn->CustomTimeDilation = moveSpeed.Speed;
		bOnce = false;
	}

	if (!bEnable && pawn && !bOnce)
	{
		pawn->CustomTimeDilation = moveSpeed.Default;
		bOnce = true;
	}

	// world dilation
	if (bEnable && world && world->PersistentLevel)
	{

		world->PersistentLevel->WorldSettings->TimeDilation = worldSpeed.Speed;
		bOnce = false;
	}

	if (!bEnable && world->PersistentLevel && !bOnce)
	{
		world->PersistentLevel->WorldSettings->TimeDilation = worldSpeed.Default;
		bOnce = true;
	}
}

inline void SpeedHack::Call(UObject* Object, UFunction* Function, void* Parms, tProcessEvent oProcessEvent)
{
	if (Function == FN_TsAnimNotifyReSkillEvent_C) {
		
		Params::TsAnimNotifyReSkillEvent_C_K2_Notify* parameters = (Params::TsAnimNotifyReSkillEvent_C_K2_Notify*)Parms;
		bool IsMyMesh = parameters->MeshComp == player_controller->Character->Mesh;

		if (IsMyMesh && rateSpeed.bEnable) {
			//
			//			billet
			// 
			//if (bEnable)
				parameters->Animation->RateScale = rateSpeed.Speed;
			//else
				//parameters->Animation->RateScale = rateSpeed.Default;
#ifdef _DEBUG
				printf("rate speed changed to %.1f\n", parameters->Animation->RateScale);
#endif
		}
	}
}

inline SpeedHack speedhack;