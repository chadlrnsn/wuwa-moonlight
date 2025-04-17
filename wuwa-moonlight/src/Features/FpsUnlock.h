#pragma once
#include <includes.h>
#include <SDK.hpp>
#include <globals.h>
using namespace globals;

class FpsUnlock
{
public:
	bool bEnabled = false;
	float fFrameRateLimit = 144.0f;
	float fFrameRateLimitMin = 24.0f;
	float fFrameRateLimitMax = 540.0f;
	float fFrameRateLimitDefault = 60.0f;
	float fFPS = 144;
	bool bUnlimited = true;
	bool bApplyFps = false;
	// Show FPS
	bool bShowFps = true; // True by default;

private:
	bool bOnce = false;

public:
	void DrawMenuItems();

	// Show fps
	void DrawFPS();
	void Run();
};



inline void FpsUnlock::DrawMenuItems()
{
	// Just for drawing fps checkbox. All render stuff see at "void DrawFPS()"
	ImGui::Checkbox("Show FPS", &bShowFps);
	ImGui::Checkbox("Fps Unlock", &bEnabled);
	if (bEnabled) {
		ImGui::Checkbox("Unlimited", &bUnlimited);
		if (bUnlimited) {
			fFrameRateLimit = 0.0f;
		}
		if (!bUnlimited) {
			ImGui::SliderFloat("## Custom FPS Limit", &fFrameRateLimit, fFrameRateLimitMin, fFrameRateLimitMax, "%.0f");
		}
	}

}

inline void FpsUnlock::DrawFPS()
{
	if (bShowFps)
	{
		SDK::UWorld* World = SDK::UWorld::GetWorld();
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

inline void FpsUnlock::Run()
{
	if (engine == nullptr) return;
	SDK::UGameUserSettings* Settings = engine->GameUserSettings;

	if (Settings == nullptr) return;

	if (bEnabled)
	{
		if (Settings->GetFrameRateLimit() == fFrameRateLimit)
		{
			// LOG_INFO("FrameRate == fFrameRateLimit\nIt will never be setted.");
			return;
		}

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

inline FpsUnlock fpsUnlock;