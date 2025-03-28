#pragma once
#include "includes.h"
#include "Bindings.h"
#include "globals.h"
using namespace globals;

class Fly
{
private:

	struct Speed {
		float Speed;
		float MinSpeed;
		float MaxSpeed;
	};

	struct AltSpeed {
		float CharMaxSpeed;
		float Acceleration;
		float oCharMaxSpeed;
		float oAcceleration;
	};

	struct FlyData {
		bool bFlySwitch = false;
		bool bNoClip = false;
	};

	struct KeyDataToggleData {
		KeyBindToggle kb = KeyBindToggle(KeyBind::KeyCode::V);
		bool bSettingKey = false;
		bool bUpKey = false;
		bool bDownKey = false;
	};

	AltSpeed altSpeed = {
		1000.0f,
		9999.0f
	};

	Speed speed = { 1, 0.1, 10 }; // Dilation
	Speed speedVectical = { 700, 0.1, 1000 };
	FlyData FlyData;
	KeyDataToggleData KeyDataToggleData;
	float oldaccel;

	bool Initalized = false;
	bool bEnabled = false;

public:


	// Handle checking for any key/hotkey presses or holds needed for features
	void HandleKeys()
	{
		if (GetAsyncKeyState(KeyDataToggleData.kb.toInt()) & 0x1)
			bEnabled = !bEnabled;
	}

	void DrawMenuItems();

	// This should be run at the top of the ImGUI draw loop, used to render things like ESP, Tracers, and Debug Info
	void Render();

	// This should be run in the feature loop, used to run any acutal feature code like setting a value for godmode
	void Run();

	// This should be run in ProcessEvent hook
	void Call();
};



inline void Fly::DrawMenuItems()
{
	ImGui::Checkbox("FlyHack", &bEnabled);
	ImGui::SameLine();
	ImGui::Hotkey("##FlyHack Key", KeyDataToggleData.kb, &KeyDataToggleData.bSettingKey);

	if (bEnabled)
	{
		ImGui::Checkbox("NoClip", &FlyData.bNoClip);

		ImGui::Spacing();

		ImGui::Text("Flight Speed Multiplier");
		ImGui::SliderFloat("## Flight Speed Multiplier", &speed.Speed, speed.MinSpeed, speed.MaxSpeed);

		ImGui::Spacing();

		ImGui::Text("Flight Z axis speed");
		ImGui::SliderFloat("## Flight Z axis speed", &speedVectical.Speed, speedVectical.MinSpeed, speedVectical.MaxSpeed);

		ImGui::Spacing();

		// TODO: Move Up and Down keys
		//ImGui::Text("Move Up");
		//ImGui::SameLine();
		//ImGui::Hotkey("##Move UP", kbUp, &bUpKey);
		//ImGui::Text("Move Down");
		//ImGui::SameLine();
		//ImGui::Hotkey("##Move Down", kbDown, &bDownKey);
	}
}

inline void Fly::Run()
{
	HandleKeys();

	if (!player_controller) return;

	auto character = player_controller->Character;
	if (!character) return;

SDK:UCharacterMovementComponent* Movement = character->CharacterMovement;
	//SDK::UMeshComponent* MeshComponent = character->Mesh;

	if (!Movement) return;

	if (bEnabled && !FlyData.bFlySwitch)
	{
		Movement->MovementMode = SDK::EMovementMode::MOVE_Flying;

		if (!oldaccel)
			oldaccel = Movement->MaxAcceleration;

		Movement->MaxAcceleration = 9999;

		if (FlyData.bNoClip && pawn && pawn->GetActorEnableCollision())
			pawn->SetActorEnableCollision(false);

		if (GetAsyncKeyState(VK_SPACE))
			Movement->Velocity.Z = speed.Speed;

		if (GetAsyncKeyState(VK_LCONTROL))
			Movement->Velocity.Z = -speed.Speed;


		FlyData.bFlySwitch = true;
	}

	if (bEnabled && FlyData.bFlySwitch)
	{
		Movement->MovementMode = SDK::EMovementMode::MOVE_Walking;
		Movement->MaxAcceleration = oldaccel;

		if (pawn && !pawn->GetActorEnableCollision())
			pawn->SetActorEnableCollision(true);

		FlyData.bFlySwitch = false;
	}
}
inline Fly fly;