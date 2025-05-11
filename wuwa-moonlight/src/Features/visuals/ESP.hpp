#pragma once
#include <includes.h>
#include <map>
#include <globals.h>
#include <utils/UnrealEngineRenderer.h>
#include <gui/components/ColorConv.hpp>
#include <gui/Context.hpp>
#include <mutex>
#include <atomic>

class ESP : public FeatureFactory
{
private:
	// Boxes
	float fColor[4] = {1,1,1,1};
	float fOccludedColor[4] = {0.5, 0.5, 0.5, 1};
	float fThickness{ 0.5 };

	// Tracers
	float fTracerColor[4] = {0, 1, 1, 0.2};
	float fTracerColorOccluded[4] = {1, 1, 1, 0.2};
	structs::MinMax <float>TracerThickness = { 0.1, 4, 1.5 };
	bool bOccludedTracers{ true };

	FVector cameraLocation;
	structs::MinMax <float>espDistance = { 0.0f, 5000.0f, 500.0f };
	bool m_bDebugWindow = false;
	bool bTracers{ false };

	// ESP Stuff
	bool bOccluded{ true };
	bool bDefaultFilters{ true };
	bool bSearchByActorClass{ false };
	bool bSearchByTag{ false };
	bool bSearchParentActor{ false };
	bool bSearchParentComponent{ false };
	bool bShowFullClassName{ false };
	bool bShowName{ true };

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

	SDK::TArray<SDK::AActor*> scene_actors;
	SDK::FName name_to_find;
	std::string searchClassName;

	struct RenderData
	{
		SDK::AActor* Actor;
		std::string DisplayText;
		std::string DisplayClassName;
		SDK::FVector2D ScreenLocation;
		bool bIsVisible;
	};

    std::vector<RenderData> renderData;
    std::vector<RenderData> tempRenderData;
    std::mutex renderMutex;

public:
	ESP() : FeatureFactory("ESP") {}
	
	void Draw();
	void Render();
	void Run();
	void RenderDebug();
	
	// Переопределение методов сериализации/десериализации
	nlohmann::json Serialize() const;
	
	void Deserialize(const nlohmann::json& json);
};
