#include "WalkableFloorZ.h"

void WalkableFloorZ::DrawMenuItems()
{
	ImGui::Checkbox("WalkableFloorZ", &bEnable);
	if (bEnable) {
		ImGui::Text("WalkableFloorZ");
		ImGui::SliderFloat("##WalkableFloorZ", &fZ, fMinZ, fMaxZ);
	}
}

void WalkableFloorZ::Run(void** args, size_t numArgs)
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
		Movement->WalkableFloorZ = fZ;
	}

	if (!bEnable && Movement)
	{
		Movement->WalkableFloorZ = 0.574f;
	}
}
