#include "WalkableFloorZ.h"

void WalkableFloorZ::Run(void** args, size_t numArgs)
{
	if (!Initalized)
		return;

	if (numArgs != 1)
	{
		Destroy();
		return;
	}

	SDK::UWorld* World = SDK::UWorld::GetWorld();
	SDK::AActor* AcknowledgedPawn = World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn;

	SDK::UPawnMovementComponent* PawnMovement = World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn->GetMovementComponent();
	SDK::UCharacterMovementComponent* Movement = static_cast<SDK::UCharacterMovementComponent*>(PawnMovement);

	if (bEnable && Movement)
	{
		Movement->WalkableFloorZ = fZ;
		bOnce = false;
	}

	if (!bEnable && Movement && !bOnce)
	{
		Movement->WalkableFloorZ = 0.574f;
		bOnce = true;
	}
}
