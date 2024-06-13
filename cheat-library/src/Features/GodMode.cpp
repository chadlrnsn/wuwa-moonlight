#include "GodMode.h"

void GodMode::Run(void** args, size_t numArgs)
{
	if (!Initalized)
		return;

	if (numArgs != 1)
	{
		//std::cout << "Too many or too little args passed to GodMode, Destryoing...\n";
		Destroy();
		return;
	}

	SDK::UWorld* World = SDK::UWorld::GetWorld();
	SDK::AActor* AcknowledgedPawn = World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn;

	if (bGodMode && AcknowledgedPawn)
	{
		AcknowledgedPawn->bCanBeDamaged = false;
		bOnce = false;
	}

	if (!bGodMode && AcknowledgedPawn && !bOnce)
	{
		AcknowledgedPawn->bCanBeDamaged = true;
		bOnce = true;
	}
}
