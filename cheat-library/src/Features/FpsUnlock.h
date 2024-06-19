#pragma once
#include "Feature.h"

class FpsUnlock : Feature
{
private:
	bool Initalized = false;

public:
	bool bEnabled = false;
	float fFrameRateLimit = 144.0f;
	float fFrameRateLimitMin = 1.0f;
	float fFrameRateLimitMax = 540.0f;
	float fFrameRateLimitDefault = 60.0f;
	float fFPS;
	bool bApplyFps = false;
	// Show FPS
	bool bShowFps = true; // True by default;

private:
	bool bOnce = false;

public:
	FpsUnlock() {};

	// Handle setup, like hook creation and variable initalization
	bool Setup() override
	{
		Initalized = true;
		return Initalized;
	};

	// Handle clean up, like restoring hooked functions 
	void Destroy() override
	{
		Initalized = false;
	}

	// Handle checking for any key/hotkey presses or holds needed for features
	void HandleKeys() override {}

	// This should be run in the ImGUI draw loop, used to draw anything to the menu
	void DrawMenuItems() override;

	// Show fps
	void DrawFPS();

	// This should be run at the top of the ImGUI draw loop, used to render things like ESP, Tracers, and Debug Info
	void Render(void** args, size_t numArgs) override {}

	// This should be run in the feature loop, used to run any acutal feature code like setting a value for godmode
	void Run(void** args, size_t numArgs) override;
};
