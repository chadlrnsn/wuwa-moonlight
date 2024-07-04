#include "ESP.h"

void ESP::DrawMenuItems()
{
	ImGui::Checkbox("ESP", &bEnabled);
	if (bEnabled) {
		ImGui::Text("ESP Distance");
		ImGui::SliderFloat("##Speed", &fDistance, fMinDistance, fMaxDistance);
	}
}

void ESP::Run(void** args, size_t numArgs)
{
	if (!Initalized)
		return;

	if (numArgs != 1)
	{
		//std::cout << "Too many or too little args passed to GodMode, Destryoing...\n";
		Destroy();
		return;
	}

	AActor* AcknowledgedPawn = (AActor*)args[0];

	if (bEnabled && AcknowledgedPawn)
	{
		AcknowledgedPawn->bCanBeDamaged = false;
		AcknowledgedPawn->bAllowReceiveTickEventOnDedicatedServer = false;
		bOnce = false;
	}

	if (!bEnabled && AcknowledgedPawn && !bOnce)
	{
		AcknowledgedPawn->bCanBeDamaged = true;
		bOnce = true;
	}
}
