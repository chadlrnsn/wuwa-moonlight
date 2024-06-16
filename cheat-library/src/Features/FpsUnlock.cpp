#include "FpsUnlock.h"

void FpsUnlock::Run(void** args, size_t numArgs)
{
	if (!Initalized)
		return;


	if (numArgs != 1)
	{
		//std::cout << "Too many or too little args passed to GodMode, Destryoing...\n";
		Destroy();
		return;
	}

	SDK::UGameUserSettings* Settings = (SDK::UGameUserSettings*)args[0];

	if (bEnabled)
	{
		Settings->SetFrameRateLimit(fFrameRateLimit);
		bOnce = false;
	}
	if (!bEnabled && !bOnce)
	{
		Settings->FrameRateLimit = fFrameRateLimitDefault;
		bOnce = true;
	}
}
