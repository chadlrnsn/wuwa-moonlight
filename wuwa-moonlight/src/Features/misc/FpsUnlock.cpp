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
	if (!bShowFps || !ImGui::GetCurrentContext()) return;

	int fps = static_cast<int>(ImGui::GetIO().Framerate);
	char fpsText[32];
	snprintf(fpsText, sizeof(fpsText), "FPS: %d", fps);

	ImVec2 textSize = ImGui::CalcTextSize(fpsText);
	ImVec2 windowPadding(15, 15);
	ImGui::SetNextWindowSize(textSize + windowPadding);
	ImGui::Begin("FPS", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);
	ImGui::Text("%s", fpsText);
	ImGui::End();
}

void FpsUnlock::Run()
{
	if (engine == nullptr) return;
	SDK::UGameUserSettings* Settings = engine->GameUserSettings;
	if (Settings == nullptr) return;

	int fps = static_cast<int>(ImGui::GetIO().Framerate);

	if (bEnable)
	{
		if (Settings->GetFrameRateLimit() == fps)
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