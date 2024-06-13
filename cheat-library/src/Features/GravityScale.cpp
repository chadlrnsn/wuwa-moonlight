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

	SDK::UWorld* World = SDK::UWorld::GetWorld();
	SDK::AActor* AcknowledgedPawn = World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn;

	SDK::UPawnMovementComponent* PawnMovement = World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn->GetMovementComponent();
	SDK::UCharacterMovementComponent* Movement = static_cast<SDK::UCharacterMovementComponent*>(PawnMovement);

	if (bEnable && Movement)
	{
		Movement->GravityScale = fGravity;
		bOnce = false;
	}

	if (!bEnable && Movement && !bOnce)
	{
		Movement->GravityScale = 1.0f;
		bOnce = true;
	}
}
