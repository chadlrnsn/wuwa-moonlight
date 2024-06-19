#include "GravityScale.h"

void GravityScale::DrawMenuItems()
{
	ImGui::Checkbox("Gravity Scale", &bEnable);
	if (bEnable) {
		ImGui::Text("Gravity Multiplier");
		ImGui::SliderFloat("##Gravity Multiplier", &fGravity, fMinGravity, fMaxGravity);
	}
}

void GravityScale::Run(void** args, size_t numArgs)
{
	if (!Initalized)
		return;

	if (numArgs != 1)
	{
		Destroy();
		return;
	}

	SDK::APawn* AcknowledgedPawn = (SDK::APawn*)args[0];
	SDK::UPawnMovementComponent* PawnMovement = AcknowledgedPawn->GetMovementComponent();
	SDK::UCharacterMovementComponent* Movement = static_cast<SDK::UCharacterMovementComponent*>(PawnMovement);

	if (bEnable && Movement)
	{
		Movement->GravityScale = fGravity;
		bOnce = false;
	}

	if (!bEnable && Movement && !bOnce)
	{
		Movement->GravityScale = 1.0f; // may be 2 its defautlt not mine function btw
		bOnce = true;
	}
}
