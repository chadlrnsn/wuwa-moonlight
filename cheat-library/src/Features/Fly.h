#include "Feature.h"

class Fly : Feature
{
private:
	bool Initalized = false;

public:
	bool bEnabled = false;
	float fMaxSpeed = 1000.0f;
	float fMinSpeed = 0.1f;
	float fSpeed = 10.0f;

private:
	bool bOnce = false;

public:
	Fly() {};

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
		ImGui::Checkbox("Fly", &bEnabled);
		if (bEnabled) {
			ImGui::Text("Speed");
			ImGui::SliderFloat("##Speed", &fSpeed, fMinSpeed, fMaxSpeed);
		}
	}

	// This should be run at the top of the ImGUI draw loop, used to render things like ESP, Tracers, and Debug Info
	void Render(void** args, size_t numArgs) override {}

	// This should be run in the feature loop, used to run any acutal feature code like setting a value for godmode
	void Run(void** args, size_t numArgs) override;
};