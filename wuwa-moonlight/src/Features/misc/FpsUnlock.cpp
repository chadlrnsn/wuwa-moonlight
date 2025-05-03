#include "FpsUnlock.hpp"

void FpsUnlock::Draw()
{
	// Just for drawing fps checkbox. All render stuff see at "void DrawFPS()"
	ImGui::Checkbox("Show FPS", &bShowFps);
	ImGui::Checkbox("Fps Unlock", &bEnable);
	if (bEnable) {
		ImGui::Checkbox("Unlimited", &bUnlimited);
		if (!bUnlimited)
			ImGui::SliderFloat("## Custom FPS Limit", &FpsData.Current, FpsData.Min, FpsData.Max, "%.0f");
	}
}

void FpsUnlock::Render()
{
	if (!bShowFps) return;

	ImVec2 textSize = ImGui::CalcTextSize(fpsText);
	ImGui::SetNextWindowSize(ImVec2(textSize.x + 15, textSize.y + 15));
	ImGui::SetNextWindowSize(textSize + ImVec2(15,0));
	ImGui::Begin("FPS", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);
	ImGui::Text("%s", fpsText);
	ImGui::End();
}

void FpsUnlock::Run()
{
	if (engine == nullptr) return;
	SDK::UGameUserSettings* Settings = engine->GameUserSettings;
	if (Settings == nullptr) return;

	auto fFPS = ("%.1f", ImGui::GetIO().Framerate);
	snprintf(fpsText, sizeof(fpsText), "FPS: %.1f", fFPS);

	if (bEnable)
	{
		if (Settings->GetFrameRateLimit() == fFPS)
		{
			// LOG_INFO("FrameRate == fFrameRateLimit\nIt will never be setted.");
			return;
		}
		

		Settings->SetFrameRateLimit(FpsData.Current);
		Settings->ApplySettings(false);
		bOnce = false;
	}
	if (!bEnable && !bOnce)
	{
		Settings->FrameRateLimit = fFrameRateLimitDefault;
		Settings->ApplySettings(false);
		bOnce = true;
	}
}