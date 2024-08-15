#pragma once
#include <includes.h>
#include <globals.h>
using namespace globals;

using namespace SDK;

class SpeedHack
{
public:

	bool bEnable = false;
	float fMaxSpeed = 30.0f;
	float fMinSpeed = 1.0f;
	float fSpeed = 10.0f;


	float fWorldMaxSpeed = 30.0f;
	float fWorldMinSpeed = 1.0f;
	float fWorldSpeed = 1.0f;

	// Bindings
	bool bSettingKey = false;
	KeyBindToggle kbToggle = KeyBindToggle(KeyBind::KeyCode::Z);

private:
	bool bOnce = false;

public:
	void HandleKeys() {
		if (GetAsyncKeyState(kbToggle.toInt()) & 0x1) {
			bEnable = !bEnable;
		}
	}

	// This should be run in the ImGUI draw loop, used to draw anything to the menu
	void DrawMenuItems();

	// This should be run at the top of the ImGUI draw loop, used to render things like ESP, Tracers, and Debug Info
	void Render();

	// This should be run in the feature loop, used to run any acutal feature code like setting a value for godmode
	void Run();
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

inline void SpeedHack::Run()
{

	HandleKeys();

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
	if (bEnable && World && World->PersistentLevel)
	{

		World->PersistentLevel->WorldSettings->TimeDilation = fWorldSpeed;
		bOnce = false;
	}

	if (!bEnable && World->PersistentLevel && !bOnce)
	{
		World->PersistentLevel->WorldSettings->TimeDilation = 1.0f;
		bOnce = true;
	}
}

inline SpeedHack speedhack;