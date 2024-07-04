#include "SpeedHack.h"

void SpeedHack::DrawMenuItems()
{
	ImGui::Checkbox("SpeedHack", &bEnable);
	ImGui::SameLine();
	ImGui::Hotkey("##SpeedHack Key", kbToggle, &bSettingKey);

	if (bEnable) {
		ImGui::Text("Speed Multiplier");
		ImGui::SliderFloat("##Speed Multiplier", &fSpeed, fMinSpeed, fMaxSpeed);
		ImGui::Text("World Speed Multiplier");
		ImGui::SliderFloat("##World Speed Multiplier", &fWorldSpeed, fWorldMinSpeed, fWorldMaxSpeed);
	}
}

void SpeedHack::Run(void** args, size_t numArgs)
{
	if (!Initalized)
		return;

	if (numArgs != 1)
	{
		//std::cout << "Too many or too little args passed to GodMode, Destryoing...\n";
		Destroy();
		return;
	}
	
	HandleKeys();


	SDK::APawn* AcknowledgedPawn = (SDK::APawn*)args[0];
	SDK::UWorld* World = (SDK::UWorld*)args[1];
	SDK::ULevel* PersistentLevel = World->PersistentLevel;

	// Character speedhack
	if (bEnable && AcknowledgedPawn)
	{
		AcknowledgedPawn->CustomTimeDilation = fSpeed;
		bOnce = false;
	}

	if (!bEnable && AcknowledgedPawn && !bOnce)
	{
		AcknowledgedPawn->CustomTimeDilation = 1.0f;
		bOnce = true;
	}

	// World speedhack
	if (bEnable && World && PersistentLevel)
	{
		
		PersistentLevel->WorldSettings->TimeDilation = fWorldSpeed;
		bOnce = false;
	}

	if (!bEnable && PersistentLevel && !bOnce)
	{
		PersistentLevel->WorldSettings->TimeDilation = 1.0f;
		bOnce = true;
	}
}
