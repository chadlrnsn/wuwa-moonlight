#include "Feature.h"

class GodMode : Feature
{
private:
	bool Initalized = false;

public:
	bool bGodMode = false;
	int iDmgTest = 1;

private:
	bool bOnce = false;

public:
	GodMode() {};

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
	void DrawMenuItems() override;

	// This should be run at the top of the ImGUI draw loop, used to render things like ESP, Tracers, and Debug Info
	void Render(void** args, size_t numArgs) override {}

	// This should be run in the feature loop, used to run any acutal feature code like setting a value for godmode
	void Run(void** args, size_t numArgs) override;
};


inline void GodMode::DrawMenuItems()
{
	ImGui::Checkbox("God Mode", &bGodMode);
}

inline void GodMode::Run(void** args, size_t numArgs)
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

inline GodMode god;