#include "ESP.h"
#include <SDKTools/SDKTools.hpp>

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
		auto world = UWorld::GetWorld();

		auto levels = world->Levels.Num();

		auto localplayer = world->OwningGameInstance->LocalPlayers[0];

		for (int i = 0; i < levels; i++) {
			for (auto actor : world->Levels[i]->Actors) {

			}
		}
	}

	if (!bEnabled && AcknowledgedPawn && !bOnce)
	{
		bOnce = true;
	}
}