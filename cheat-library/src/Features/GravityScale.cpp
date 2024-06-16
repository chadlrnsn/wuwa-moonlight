#include "GravityScale.h"

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
	}

	if (!bEnable && Movement)
	{
		Movement->GravityScale = 1.0f; // may be 2 its defautlt not mine function btw
	}
}
