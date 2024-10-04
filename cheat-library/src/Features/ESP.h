#pragma once
#include <includes.h>
#include <globals.h>
#include <Helper.h>
#include <unordered_set>

using namespace globals;


class ESP
{
private:

	struct Searchable {
		float Distance = 10000; // in units
		float MinDistance = 100;
		float MaxDistance = 100000;
	};

	Searchable search;

	bool Initalized = false;
	ULevel* m_CurrentLevel;

	// Filters
	std::vector<AActor*> m_Actors;
	std::vector<AActor*> IgnoreActors;
	std::vector<AActor*> NearbyActors;
	
	bool bEnabled = config::esp::enable;

	enum Targets {
		NPC,
		Item,
		Enemy,
		Chests,
		MAX_TARGETS
	};


	std::unordered_set<std::string> BadNames = {
		
		// UI
		"UITextureActor",
		"UIContainerActor",
		"UITextActor",
		"UISpriteActor",

		// Other
		"LTweenActor",

		// Actor
		"PlayerState",
		"PlayerCameraManager",
		"CameraActor",
		"DefaultPawn",
		"LevelSequenceActor",
		
		// Pawn caller
		"BP_Cinematics_Tick_C",
		"BP_StartupPlayerController_C",

		// Lighting
		"SpotLight",
		"SpotLight",
		
		// PuerTS
		"TsUiSceneRoleActor_C",
		"TsSkeletalObserver_C",
		"TsUiSceneRoleActor_C",
		"TsSkeletalObserver_C",
	};

	bool bOnce = false;
	
public:
	
	// Handle checking for any key/hotkey presses or holds needed for features
	void HandleKeys();

	// This should be run in the ImGUI draw loop, used to draw anything to the menu
	void DrawMenuItems() ;

	// This should be run at the top of the ImGUI draw loop, used to render things like ESP, Tracers, and Debug Info
	void Render(UCanvas*);

	// This should be run in the feature loop, used to run any acutal feature code like setting a value for godmode
	void Run();
};


inline void ESP::HandleKeys()
{
	if (GetKeyState(VK_MBUTTON) & 0x8000)
		printf("Pressed\n");
		//save_ent_to_list()

}

inline void ESP::DrawMenuItems()
{
	ImGui::Checkbox("ESP", &bEnabled);
	if (bEnabled) {
		ImGui::Text("ESP Distance");
		ImGui::SliderFloat("##Speed", &search.Distance, search.MinDistance, search.MaxDistance);
	}
}

inline void ESP::Render(UCanvas* Canvas)
{
	if (!bEnabled) return;
	if (NearbyActors.empty()) return;
	if (!PlayerController) return;
	if (!AcknowledgedPawn) return;

	for (AActor* Actor : NearbyActors)
	{
		FVector2D ScreenLocation;

		if (UGameplayStatics::ProjectWorldToScreen(PlayerController, AcknowledgedPawn->K2_GetActorLocation(), &ScreenLocation, true))
		{
			std::string str = Actor->GetName();
			std::wstring widestr = std::wstring(str.begin(), str.end());

			if (Actor) {
				Helper::UE_RenderText(Canvas, Engine->SmallFont, widestr.c_str(), ScreenLocation);
			}
		}
	}
}

inline void ESP::Run()
{
	HandleKeys();

	if (!bEnabled) return;
	if (!AcknowledgedPawn) return;

	FVector MyActorLocation = AcknowledgedPawn->K2_GetActorLocation();

	if (!NearbyActors.empty()) NearbyActors.clear();

	auto c_level = AcknowledgedPawn->GetLevel();
	if (!c_level) return;

	TArray<AActor*> ActorsInLevel = c_level->Actors;

	for (AActor* Actor : ActorsInLevel)
	{
		if (BadNames.find(Actor->GetName().c_str()) != BadNames.end()) continue;

		if (Actor && !Actor->IsChildActor() && MyActorLocation.GetDistanceTo(Actor->K2_GetActorLocation()) < search.Distance)
		{
			NearbyActors.push_back(Actor);
		}
	}
}

inline ESP esp;