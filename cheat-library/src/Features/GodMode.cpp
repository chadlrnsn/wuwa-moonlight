#include "GodMode.h"

void GodMode::DrawMenuItems()
{
	ImGui::Checkbox("God Mode", &bGodMode);
	
	if (bGodMode) {
		ImGui::BeginChild(1, ImVec2(0, 100), true);
		ImGui::SliderInt("## DMG", &iDmgTest, -10000, 10000);
		ImGui::EndChild();
	}
}

void GodMode::Run(void** args, size_t numArgs)
{
	if (!Initalized)
		return;

	if (numArgs != 1)
	{
		//std::cout << "Too many or too little args passed to GodMode, Destryoing...\n";
		Destroy();
		return;
	}

	SDK::APawn* AcknowledgedPawn = (SDK::APawn*)args[0];

	// Make player invulnerable
	if (bGodMode && AcknowledgedPawn)
	{
		AcknowledgedPawn->ReceiveAnyDamage(iDmgTest, nullptr, nullptr, nullptr);
		bOnce = false;
	}

	if (!bGodMode && AcknowledgedPawn && !bOnce)
	{
		AcknowledgedPawn->ReceiveAnyDamage(0, nullptr, nullptr, nullptr);
		bOnce = true;
	}
}
