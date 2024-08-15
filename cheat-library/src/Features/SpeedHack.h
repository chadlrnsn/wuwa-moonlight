#include "Feature.h"

class SpeedHack : Feature
{
private:
	bool Initalized = false;

public:
	// Actor speedhack
	bool bEnable = false;
	float fMaxSpeed = 30.0f;
	float fMinSpeed = 1.0f;
	float fSpeed = 10.0f;

	// World speedhack
	float fWorldMaxSpeed = 30.0f;
	float fWorldMinSpeed = 1.0f;
	float fWorldSpeed = 1.0f;

	// Bindings
	bool bSettingKey = false;
	KeyBindToggle kbToggle = KeyBindToggle(KeyBind::KeyCode::Z);

private:
	bool bOnce = false;

public:
	SpeedHack() {};

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
	void HandleKeys() override {
		if (GetAsyncKeyState(kbToggle.toInt()) & 0x1) {
			bEnable = !bEnable;
		}
	}

	// This should be run in the ImGUI draw loop, used to draw anything to the menu
	void DrawMenuItems() override;

	// This should be run at the top of the ImGUI draw loop, used to render things like ESP, Tracers, and Debug Info
	void Render(void** args, size_t numArgs) override {}

	// This should be run in the feature loop, used to run any acutal feature code like setting a value for godmode
	void Run(void** args, size_t numArgs) override;
};



inline void SpeedHack::DrawMenuItems()
{
	ImGui::Checkbox("SpeedHack", &bEnable);
	ImGui::SameLine();
	ImGui::Hotkey("##SpeedHack Key", kbToggle, &bSettingKey);

	if (bEnable) {
		ImGui::Text("Speed Multiplier");
		ImGui::SliderFloat("##Speed Multiplier", &fSpeed, fMinSpeed, fMaxSpeed);
		ImGui::Text("World Speed Multiplier");
		ImGui::SliderFloat("##World Speed Multiplier", &fWorldSpeed, fWorldMinSpeed, fWorldMaxSpeed);
	}
}

inline void SpeedHack::Run(void** args, size_t numArgs)
{
	if (!Initalized)
		return;

	if (numArgs != 1)
	{
		//std::cout << "Too many or too little args passed to GodMode, Destryoing...\n";
		Destroy();
		return;
	}

	HandleKeys();


	SDK::APawn* AcknowledgedPawn = (SDK::APawn*)args[0];
	SDK::UWorld* World = (SDK::UWorld*)args[1];
	SDK::ULevel* PersistentLevel = World->PersistentLevel;

	// Character speedhack
	if (bEnable && AcknowledgedPawn)
	{
		AcknowledgedPawn->CustomTimeDilation = fSpeed;
		bOnce = false;
	}

	if (!bEnable && AcknowledgedPawn && !bOnce)
	{
		AcknowledgedPawn->CustomTimeDilation = 1.0f;
		bOnce = true;
	}

	// World speedhack
	if (bEnable && World && PersistentLevel)
	{

		PersistentLevel->WorldSettings->TimeDilation = fWorldSpeed;
		bOnce = false;
	}

	if (!bEnable && PersistentLevel && !bOnce)
	{
		PersistentLevel->WorldSettings->TimeDilation = 1.0f;
		bOnce = true;
	}
}

inline SpeedHack speedhack;