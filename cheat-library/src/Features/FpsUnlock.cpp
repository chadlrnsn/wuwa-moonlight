#include "FpsUnlock.h"

void FpsUnlock::DrawMenuItems()
{
	// Just for drawing fps checkbox. All render stuff see at "void DrawFPS()"
	ImGui::Checkbox("Show FPS", &bShowFps);
	ImGui::Checkbox("Fps Unlock", &bEnabled);
	if (bEnabled)
		ImGui::SliderFloat("## Custom FPS Limit", &fFrameRateLimit, fFrameRateLimitMin, fFrameRateLimitMax, "%.0f");
}

void FpsUnlock::DrawFPS()
{
	if (bShowFps)
	{
		fFPS = ("%.1f", ImGui::GetIO().Framerate);

		char fpsText[32];
		snprintf(fpsText, sizeof(fpsText), "FPS: %.1f", fFPS);

		ImVec2 textSize = ImGui::CalcTextSize(fpsText);
		ImGui::SetNextWindowSize(ImVec2(textSize.x + 15, textSize.y + 15));

		ImGui::Begin("FPS", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);
		ImGui::Text("%s", fpsText);
		ImGui::End();
	}
}

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
		Settings->ApplySettings(false);
		bOnce = false;
	}
	if (!bEnabled && !bOnce)
	{
		Settings->FrameRateLimit = fFrameRateLimitDefault;
		Settings->ApplySettings(false);
		bOnce = true;
	}
}
