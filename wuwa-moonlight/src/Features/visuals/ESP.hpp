#pragma once
#include <includes.h>
#include <map>
#include <globals.h>
#include <utils/UnrealEngineRenderer.h>
#include <gui/components/ColorConv.hpp>
#include <gui/Context.hpp>
#include <mutex>
#include <atomic>
#include <optional>

using UMapSS = std::unordered_map<std::string, std::string>;

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
	bool bShowDistance{ true };

	UMapSS Ascension_Materials = {

		// Treasures
		{"Treasure001", "Basic Supply Chest"}, 
		{"Treasure014", "Standart Supply Chest"}, 
		{"Treasure015", "Advanced Supply Chest"}, 
		{"Treasure017", "Inspect box???"}, 
		{"Treasure022", "House of Wonders Chest (Basic)"}, 
		{"Treasure023", "House of Wonders Chest (Standart)"}, 
		{"Treasure024", "House of Wonders Chest (Advanced)"}, 
		{"Treasure025", "House of Wonders Chest (Legendary)"}, 


		// Materials
		{"Collect003", "Iris"}, 
		{"Collect004", "Terraspawn Fungus"}, 
		{"Collect005", "Lanternberry"}, 
		{"Collect006", "Pecok Flower"}, 
		{"Collect007", "Belle Poppy"}, 
		{"Collect008", "Coriolus"}, 
		{"Collect009", "Wintry Bell"}, 
		{"Collect010", "Violet Coral"}, 
		
		{"Collect101", "Pearl Leaf"}, 
		{"Collect102", "Dewvetch"}, 
		{"Collect105", "Perilla"}, 
		{"Collect106", "Angelica"}, 
		{"Collect104", "Honeysuckle"}, 
		{"Collect104_1", "Honeysuckle (bush)"}, 
		{"Collect107", "Lemongrass"}, 
		{"Collect109", "Waterlamp"}, 
		{"Collect110", "Bunnywort"}, 
		{"Collect112", "Chromeshell"}, 
		{"Collect113", "Dripsnail"}, 
		{"Collect114", "Viola"}, 
		{"Collect117", "Gemberry"}, 
		{"Collect117_1", "Gemberry (bush)"}, 

		// gribi
		{"Collect118", "Edodes"}, 

		{"Collect_CX508", "Loong's Pearl"}, 
		{"Collect_CX509", "Loong's Pearl"}, 
		{"Collect_CX503", "Pavo Plum"}, 
		{"Collect_CX504", "Pavo Plum"}, 
		{"Collect_CX505", "Pavo Plum"}, 
		{"Collect_CX506", "Pavo Plum"},

		// Ore
		{"Collect501", "Scarletthorn"},
		{"Collect502", "Lampylumen"},
		{"Collect503", "Indigoite"},
		{"Collect504", "Floral Amber"},
		{"Collect505", "Flourite"},

		// Monsters
		{ "Monster012", "Exil-M" },
		{ "Monster013", "Exil-F" },
		{ "Monster024", "Exil-M" },
		{ "Monster020", "Exil-M" },
		{ "Monster021", "Exil-M" },
		{ "Monster025", "Exil-F" },
		{ "Monster027", "Exil-F" },
		{ "Monster028", "Exil-F" },
		{ "Monster029", "Exil-F" },
		{ "Monster022", "Exil-M" },
		{ "Monster055", "Exil-M boss" },
		{ "Monster056", "Exil-F boss" },
		{ "Monster069", "Fractsidus Executioner" },
		{ "Monster086", "Fractsidus Cannoneer" },
		{ "Monster087", "Fractsidus Gunmaster" },
		{ "Monster072", "Fractsidus Thruster" },

		// Guard
		{ "Monster142", "Ally NPC" },
		{ "Monster143", "Ally NPC" },
		{ "Monster144", "Ally NPC" },


		// Echos
		{ "Monster008", "Viridblaze Saurian" },
		{ "Monster014", "Cruisewing" },
		{ "Monster018", "Baby Viridblaze Saurian" },
		{ "Monster016", "Gulpuff" },
		{ "Monster033", "Fusion Prism" },
		{ "Monster034", "Glacio Prism" },
		{ "Monster042", "Viridblaze Saurian" },
		{ "Monster049", "Wolf" },
		{ "Monster053", "Small Wolf" },
		{ "Monster150", "Carapace" },

		{ "VisionItem001", "Echo to absorb" },

		// Gameplay event
		{ "Gameplay021", "Sonance Casket" },
		{ "Gameplay111", "Mutterfly" },
		{ "Gameplay112", "Mutterfly (home)" },
		{ "Gameplay200", "Tacktical hologram: Overdash" },
		{ "Gameplay381", "Magnetic cube (cube)" },
		{ "Gameplay382", "Magnetic cube" },

		// World items
		{ "Weapon001", "Weapon" },
		{ "Weapon002", "Weapon" },
		{ "Weapon003", "Weapon" },
		{ "Weapon004", "Weapon" },
		{ "Weapon005", "Weapon" },

		// Peaceful creatures
		{ "Animal013", "Goat" },
		{ "Animal012", "Rabbit" },
		{ "Animal014", "Cow" },
		{ "Animal015", "Cow" },
		{ "Animal016", "Butterfly" },
		{ "Animal017", "Butterfly" },
		{ "Animal018", "Butterfly" },


		{ "Animal027", "Azure lizard" },
		{ "Animal027", "Silver-Banded lizard" },
		{ "Animal028", "Green Pit lizard" },
		{ "Animal029", "Black Stripped frog" },
		{ "Animal030", "Goldenback frog" },
		{ "Animal031", "Bird" },
			// Fish
		{ "Animal021", "Fish" },
		{ "Animal022", "Fish" },
		{ "Animal023", "Fish" },
		{ "Animal024", "Fish" },
			// Cat
		{ "Animal007", "Cat" },
		{ "Animal008", "Cat" },


		// Beakon
		{ "Teleport001", "Resonanse beacon" },
		{ "Teleport002", "Resonanse beacon" },
		{ "Teleport003", "Resonanse beacon" },
		{ "Teleport004", "Resonanse beacon" },
		{ "Teleport005", "Resonanse beacon" },
		{ "Teleport006", "Resonanse beacon" },
		{ "Teleport007", "Resonanse beacon" },
	};

	// UMapSS Ore = {
	// 	{"Collect501", "Scarletthorn"},
	// 	{"Collect502", "Lampylumen"},
	// 	{"Collect503", "Indigoite"},
	// 	{"Collect504", "Floral Amber"},
	// 	{"Collect505", "Flourite"}
	// };

	// UMapSS Monsters = {
	// 	{ "Monster012", "Exil-M" },
	// 	{ "Monster013", "Exil-F" }
	// };

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

public:

	enum class EEntityType {
		Ore,
		Monster,
		NPC,
		Material,
		Animal,
		MAX
	};


	struct EntityInfo {
    	std::string name;
    	EEntityType type;
	};


private:
	std::string getRealName(UMapSS umap, std::string& key);
};
