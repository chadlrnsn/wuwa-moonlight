#include "FpsUnlock.h"

void FpsUnlock::Run(void** args = {}, size_t numArgs = 1)
{
	if (!Initalized)
		return;


	if (numArgs != 1)
	{
		//std::cout << "Too many or too little args passed to GodMode, Destryoing...\n";
		Destroy();
		return;
	}

	SDK::UEngine* Engine = (SDK::UEngine*)args[0];
	SDK::UGameUserSettings* Settings = Engine->GameUserSettings;

	if (!Settings)
		return;

	if (bEnabled)
	{
		if (Settings->GetFrameRateLimit() == fFrameRateLimit)
			return;
		
		Settings->SetFrameRateLimit(fFrameRateLimit);

		if (bApplyFps) {
			Settings->ApplySettings(true);
			bApplyFps = false;
		}
		bOnce = false;
	}
	if (!bEnabled && !bOnce)
	{
		Settings->FrameRateLimit = fFrameRateLimitDefault;
		bOnce = true;
	}
}
