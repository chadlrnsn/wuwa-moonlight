#include "WalkableFloorAngle.h"

void WalkableFloorAngle::Run(void** args, size_t numArgs)
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
		Movement->WalkableFloorAngle = fAngle;

	if (!bEnable && Movement)
		Movement->WalkableFloorZ = 0.574f;
}
