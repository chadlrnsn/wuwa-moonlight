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

	SDK::UWorld* World = SDK::UWorld::GetWorld();

	SDK::UPawnMovementComponent* PawnMovement = World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn->GetMovementComponent();
	SDK::UCharacterMovementComponent* Movement = static_cast<SDK::UCharacterMovementComponent*>(PawnMovement);

	if (bEnable && Movement)
	{
		Movement->WalkableFloorAngle = fAngle;
		bOnce = false;
	}

	if (!bEnable && Movement && !bOnce)
	{
		Movement->WalkableFloorZ = 0.574f;
		bOnce = true;
	}
}
