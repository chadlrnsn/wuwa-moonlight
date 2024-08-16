#pragma once
#include <includes.h>
#include <globals.h>

using namespace globals;

class ESP
{
private:
	bool Initalized = false;
	TArray<ULevel*> Levels;
	TArray<AActor*> Actors;
	TArray<FVector> ActorsLocations;

public:
	bool bEnabled = false;
	float fMaxDistance = 100000.0f;
	float fMinDistance = 0.1f;
	float fDistance = 10000.0f;

	enum Targets {
		NPC,
		Item,
		Enemy,
		Chests,
	};

	//std::vector<Targets> TargetsNames = {
	//	Targets::NPC = {},
	//};

private:
	bool bOnce = false;

public:
	
	// Handle checking for any key/hotkey presses or holds needed for features
	void HandleKeys();

	// This should be run in the ImGUI draw loop, used to draw anything to the menu
	void DrawMenuItems() ;

	// This should be run at the top of the ImGUI draw loop, used to render things like ESP, Tracers, and Debug Info
	void Render(UCanvas* Canvas);

	// This should be run in the feature loop, used to run any acutal feature code like setting a value for godmode
	void Run();
};

inline void ESP::DrawMenuItems()
{
	ImGui::Checkbox("ESP", &bEnabled);
	if (bEnabled) {
		ImGui::Text("ESP Distance");
		ImGui::SliderFloat("##Speed", &fDistance, fMinDistance, fMaxDistance);
	}
}

inline void ESP::Render(UCanvas* Canvas)
{
	if (!Canvas) return;

}

inline void ESP::Run()
{

	if (bEnabled && AcknowledgedPawn)
	{
		auto world = UWorld::GetWorld();
		
		if (!world) return;
		
		auto levels = world->Levels.Num();
		
		if (!levels) return;

		Levels = world->Levels;

		auto localplayer = world->OwningGameInstance->LocalPlayers[0];

		if (!localplayer) return;

		for (auto level : Levels) {
			for (auto actor : Levels) {

			}
		}
	}

	if (!bEnabled && AcknowledgedPawn && !bOnce)
	{
		bOnce = true;
	}
}