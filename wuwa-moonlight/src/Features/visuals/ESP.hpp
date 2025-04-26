#pragma once
#include <includes.h>
#include <map>
#include <globals.h>
#include <utils/UnrealEngineRenderer.h>
#include <gui/components/ColorConv.hpp>
#include <gui/Context.hpp>

class ESP : public FeatureFactory
{
protected:
	float fColor[4] = {1,1,1,1};
	float fOccludedColor[4] = {0.5, 0.5, 0.5, 1};

private:
	structs::Distance espDistance;
	bool m_bDebugWindow = false;
	FVector cameraLocation;

private:
	// ESP Stuff

	std::map<std::string, std::string> Ascension_Materials = {
		{"Collect003", "Iris"}, 
		{"Collect004", "Terraspawn Fungus"}, 
		{"Collect005", "Lanternberry"}, 
		{"Collect006", "Pecok Flower"}, 
		{"Collect007", "Belle Poppy"}, 
		{"Collect008", "Coriolus"}, 
		{"Collect009", "Wintry Bell"}, 
		{"Collect010", "Violet Coral"}, 
		{"Collect_CX508", "Loong's Pearl"}, 
		{"Collect_CX509", "Loong's Pearl"}, 
		{"Collect_CX503", "Pavo Plum"}, 
		{"Collect_CX504", "Pavo Plum"}, 
		{"Collect_CX505", "Pavo Plum"}, 
		{"Collect_CX506", "Pavo Plum"}
	};

	std::map<std::string, std::string> Ore = {
		{"Collect501", "Scarletthorn"},
		{"Collect502", "Lampylumen"},
		{"Collect503", "Indigoite"},
		{"Collect504", "Floral Amber"},
		{"Collect505", "Flourite"}
	};

	std::map<std::string, std::string> Monsters = {
		{ "Monster012", "Exil-M" },
		{ "Monster013", "Exil-F" }
	};

	SDK::TArray<SDK::AActor> any_actor_of_scene;
	SDK::FName name_to_find;
	std::string searchClassName;

	struct RenderData
	{
		SDK::AActor* Actor;
		std::string DisplayText;
		SDK::FVector2D ScreenLocation;
		bool bIsVisible;
	};

	struct RenderDataA
	{
		SDK::AActor* Actor;
		SDK::FString DisplayText;
		SDK::FVector2D ScreenLocation;
		bool bIsVisible;
	};

	std::vector<RenderData> renderActors;
	//std::vector<RenderDataA> renderActors;

public:
	void Draw();
	void Render();
	void Run();
	void RenderDebug();
};
