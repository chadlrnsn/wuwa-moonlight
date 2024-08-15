#include "Feature.h"
#include <SDK.hpp>
#include <SDKTools/Player.h>
#include "Bindings.h"

class Fly : Feature
{
private:
	bool Initalized = false;
	bool bFlySwitch = false;
	bool bSettingKey = false;
	bool bUpKey = false;
	bool bDownKey = false;

public:
	bool bEnabled = false;
	float fMaxSpeed = 100.0f;
	float fMinSpeed = 1.0f;
	float fSpeed = 10.0f;
	bool bNoClip = false;
	float fZSpeed = 500.0f;
	float fZSpeedMin = 10.0f;
	float fZSpeedMax = 2000.0f;
	bool bPreventAnimVelecity = false;

	KeyBindToggle kbToggle = KeyBindToggle(KeyBind::KeyCode::V);

private:
	float fOldSpeed = 0.0f;

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
	void HandleKeys() override 
	{
		if (GetAsyncKeyState(kbToggle.toInt()) & 0x1)
			bEnabled = !bEnabled;

		//if (GetAsyncKeyState(kbUp.toInt()) & 0x1)
		//	bEnabled = !bEnabled;

		//if (GetAsyncKeyState(kbDown.toInt()) & 0x1)
		//	bEnabled = !bEnabled;
	}

	// This should be run in the ImGUI draw loop, used to draw anything to the menu
	void DrawMenuItems() override;

	// This should be run at the top of the ImGUI draw loop, used to render things like ESP, Tracers, and Debug Info
	void Render(void** args, size_t numArgs) override {}

	// This should be run in the feature loop, used to run any acutal feature code like setting a value for godmode
	void Run(void** args, size_t numArgs) override;
};



inline void Fly::DrawMenuItems()
{
	ImGui::Checkbox("FlyHack", &bEnabled);
	ImGui::SameLine();
	ImGui::Hotkey("##FlyHack Key", kbToggle, &bSettingKey);

	if (bEnabled)
	{
		ImGui::BeginChild(1, ImVec2(0, 150), 1);

		ImGui::Checkbox("NoClip", &bNoClip);
		ImGui::Text("Flight Speed Multiplier");
		ImGui::SliderFloat("## Flight Speed Multiplier", &fSpeed, fMinSpeed, fMaxSpeed);

		ImGui::Text("Flight Z axis speed");
		ImGui::SliderFloat("## Flight Z axis speed", &fZSpeed, fZSpeedMin, fZSpeedMax);
		ImGui::Checkbox("Prevent Anim Velecity", &bPreventAnimVelecity);


		ImGui::EndChild();

		// TODO: Move Up and Down keys
		//ImGui::Text("Move Up");
		//ImGui::SameLine();
		//ImGui::Hotkey("##Move UP", kbUp, &bUpKey);
		//ImGui::Text("Move Down");
		//ImGui::SameLine();
		//ImGui::Hotkey("##Move Down", kbDown, &bDownKey);
	}
}

inline void Fly::Run(void** args, size_t numArgs)
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
	SDK::UCharacterMovementComponent* CharacterMovement = (SDK::UCharacterMovementComponent*)args[1];


	if (bEnabled)
	{
		CharacterMovement->MovementMode = SDK::EMovementMode::MOVE_Flying;
		fOldSpeed = CharacterMovement->MaxFlySpeed;
		CharacterMovement->MaxFlySpeed = fOldSpeed * fSpeed;

		if (bNoClip && AcknowledgedPawn->GetActorEnableCollision())
			AcknowledgedPawn->SetActorEnableCollision(false);

		// TODO Bindings
		if (GetAsyncKeyState(VK_SPACE))
			CharacterMovement->Velocity.Z = CharacterMovement->LastUpdateVelocity.Z + fZSpeed;

		if (GetAsyncKeyState(VK_LCONTROL))
			CharacterMovement->Velocity.Z = CharacterMovement->LastUpdateVelocity.Z - fZSpeed;


		// Stop player anim when flying
		if (bPreventAnimVelecity)
			CharacterMovement->AnimRootMotionVelocity = FVector(0, 0, 0);


		bFlySwitch = true;
	}
	else
	{
		if (bFlySwitch)
		{
			CharacterMovement->MovementMode = SDK::EMovementMode::MOVE_Walking;
			CharacterMovement->MaxFlySpeed = fOldSpeed;

			if (!AcknowledgedPawn->GetActorEnableCollision())
				AcknowledgedPawn->SetActorEnableCollision(true);

			bFlySwitch = false;
		}
	}
}
inline Fly fly;