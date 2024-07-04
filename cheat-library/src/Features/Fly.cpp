#include "Fly.h"

void Fly::DrawMenuItems()
{
	ImGui::Checkbox("FlyHack", &bEnabled);
	ImGui::SameLine();
	ImGui::Hotkey("##FlyHack Key", kbToggle, &bSettingKey);

	if (bEnabled)
	{
		ImGui::BeginChild(1, ImVec2(0, 150), 1);

		ImGui::Checkbox("NoClip", &bNoClip);
		ImGui::Text("Flight Speed Multiplier");
		ImGui::SliderFloat("## Flight Speed Multiplier", &fSpeed, fMinSpeed, fMaxSpeed );

		ImGui::Text("Flight Z axis speed");
		ImGui::SliderFloat("## Flight Z axis speed", &fZSpeed, fZSpeedMin, fZSpeedMax );

		ImGui::EndChild();
		//ImGui::Text("Move Up");
		//ImGui::SameLine();
		//ImGui::Hotkey("##Move UP", kbUp, &bUpKey);
		//ImGui::Text("Move Down");
		//ImGui::SameLine();
		//ImGui::Hotkey("##Move Down", kbDown, &bDownKey);
	}
}

void Fly::Run(void** args, size_t numArgs)
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
