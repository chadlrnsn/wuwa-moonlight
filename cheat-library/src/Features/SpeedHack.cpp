#include "SpeedHack.h"

void SpeedHack::Run(void** args, size_t numArgs)
{
	if (!Initalized)
		return;

	if (numArgs != 1)
	{
		//std::cout << "Too many or too little args passed to GodMode, Destryoing...\n";
		Destroy();
		return;
	}


	SDK::APawn* AcknowledgedPawn = (SDK::APawn*)args[0];

	if (bEnable && AcknowledgedPawn)
	{
		AcknowledgedPawn->CustomTimeDilation = fSpeed;
		bOnce = false;
	}

	if (!bEnable && AcknowledgedPawn && !bOnce)
	{
		AcknowledgedPawn->CustomTimeDilation = 1.0f;
		bOnce = true;
	}
}
