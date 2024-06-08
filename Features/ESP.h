#include "Feature.h"

class ESP : Feature
{
private:
	bool Initalized = false;

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

private:
	bool bOnce = false;

public:
	ESP() {};

	// Handle setup, like hook creation and variable initalization
	bool Setup() override
	{
		Initalized = true;

		return Initalized;
	};

	// Handle clean up, like restoring hooked functions 
	void Destroy() override
	{
		Initalized = false;
	}

	// Handle checking for any key/hotkey presses or holds needed for features
	void HandleKeys() override {}

	// This should be run in the ImGUI draw loop, used to draw anything to the menu
	void DrawMenuItems() override
	{
		ImGui::Checkbox("ESP", &bEnabled);
		if (bEnabled) {
			ImGui::Text("ESP Distance");
			ImGui::SliderFloat("##Speed", &fDistance, fMinDistance, fMaxDistance);
		}
	}

	// This should be run at the top of the ImGUI draw loop, used to render things like ESP, Tracers, and Debug Info
	void Render(void** args, size_t numArgs) override {}

	// This should be run in the feature loop, used to run any acutal feature code like setting a value for godmode
	void Run(void** args, size_t numArgs) override;
};