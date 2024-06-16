#include "Fly.h"

void Fly::DrawMenuItems()
{
	ImGui::Checkbox("FlyHack", &bEnabled);
	ImGui::SameLine();
	ImGui::Hotkey("##FlyHack Key", kbToggle, &bSettingKey);
	ImGui::Checkbox("NoClip", &bNoClip);

	if (bEnabled)
	{
		ImGui::Text("Flight Speed Multiplier");
		ImGui::SliderFloat("## Flight Speed Multiplier", &fSpeed, fMinSpeed, fMaxSpeed );
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
	
	SDK::UCharacterMovementComponent* CharacterMovement = (SDK::UCharacterMovementComponent*)args[0];
	SDK::APawn* AcknowledgedPawn = (SDK::APawn*)args[1];

	if (bEnabled)
	{
			CharacterMovement->MovementMode = SDK::EMovementMode::MOVE_Flying;
			fOldSpeed = CharacterMovement->MaxFlySpeed;
			CharacterMovement->MaxFlySpeed = fOldSpeed * fSpeed;

			if (bNoClip && AcknowledgedPawn->GetActorEnableCollision())
				AcknowledgedPawn->SetActorEnableCollision(false);

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
