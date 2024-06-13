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

	SDK::AActor* AcknowledgedPawn = (SDK::AActor*)args[0];
	printf("AcknowledgePawn[GOD] -> %p", AcknowledgedPawn);

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
