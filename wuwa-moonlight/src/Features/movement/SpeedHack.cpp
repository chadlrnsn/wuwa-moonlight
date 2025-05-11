#include "SpeedHack.h"

void SpeedHack::ResetSpeed()
{
	accelSpeed.Current 	= 1.0f;
	worldSpeed.Current 	= 1.0f;
	animSpeed.Current 	= 1.0f;
}

void SpeedHack::Draw()
{
	ImGui::Checkbox("Speedhack", &bEnable);
	ImGui::SameLine();
	ImGui::Hotkey("##Global SpeedHack Key", kbToggle, &bSettingKey);

	ImGui::BeginDisabled(!bEnable);
	{
		ImGui::Checkbox("Character speed", &bCharacterAcceleratedSpeed);
		ImGui::SameLine();
		ImGui::Tooltip("Its increeses character walk speed");
		ImGui::SliderFloat("##Player walk speedhack", &accelSpeed.Current, accelSpeed.Min, accelSpeed.Max);

		ImGui::Checkbox("Character fly speed", &bCharacterAcceleratedFlySpeed);
		ImGui::SliderFloat("##Fly speedhack", &flySpeed.Current, flySpeed.Min, flySpeed.Max);

		ImGui::Checkbox("World Dillation", &bWorldDilation);
		ImGui::SameLine();
		ImGui::WarningTooltip("You want to get banned = set the speed higher than 5");
		ImGui::SliderFloat("##worldSpeed", &worldSpeed.Current, worldSpeed.Min, worldSpeed.Max);

		ImGui::Text("Rate Speed (sequences)");
		ImGui::Checkbox("Rate Speed", &bCharacterAnimationSpeed);
		ImGui::SameLine();
		ImGui::Tooltip("Its increeses your character animation speed (does not affect echoes or vehicles)");
		ImGui::SliderFloat("##RateSpeed", &animSpeed.Current, animSpeed.Min, animSpeed.Max);
	}
	ImGui::EndDisabled();

	if (ImGui::Button("Reset speed")) ResetSpeed();
	ImGui::SameLine();
	ImGui::Tooltip("Reset all your setted speed to 1 (or special defaulted speed)");
	ImGui::SameLine();
	ImGui::WarningTooltip("If you disable some features then effect will not be applied to them!");

	ImGui::Checkbox("Disable enemy attack animation", &bDisableEnemyAttackAnim);
	ImGui::SameLine();
	ImGui::Tooltip("Set enemy anim speed to 0 but after fisrt hit");
}

void SpeedHack::Run()
{
	HandleKeys();

	if (!bEnable) return;

	// Character speed
	if (bCharacterAcceleratedSpeed && player_controller) {
		auto pcharacter = player_controller->Character;
		if (pcharacter) {
			auto comp = pcharacter->CharacterMovement;
			if (comp) {
				comp->MaxAcceleration = 9999.0f;
				comp->MaxWalkSpeed = accelSpeed.Current;
				comp->MaxFlySpeed = flySpeed.Current;
			}
		}
	}

	// World dilation
	if (bWorldDilation && world) {
		auto pPL = world->PersistentLevel;
		if (pPL) {
			auto pWS = pPL->WorldSettings;
			if (pWS) {
				pWS->TimeDilation = worldSpeed.Current;
			}
		}
	}
}

void SpeedHack::Call(UObject* Object, UFunction* Function, void* Parms)
{
	if (Function->Index != globals::FN_TsAnimNotifyReSkillEvent_C) 
		return;

	if (!bCharacterAnimationSpeed && !bDisableEnemyAttackAnim)
		return;

	auto parameters = static_cast<SDK::Params::TsAnimNotifyReSkillEvent_C_K2_Notify*>(Parms);
	if (!parameters) return;

    USkeletalMeshComponent* meshComp = parameters->MeshComp;
    if (!meshComp) return;
    

	bool IsMe = meshComp->GetOwner() == globals::pawn;

	if (bCharacterAnimationSpeed && IsMe) {
		parameters->Animation->RateScale = animSpeed.Current;
	}

	if (bDisableEnemyAttackAnim && !IsMe) {
		parameters->Animation->RateScale = 0;
	}

	return globals::oProcessEvent(Object, Function, parameters);
}
