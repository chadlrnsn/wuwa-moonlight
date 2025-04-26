#pragma once
#include <includes.h>
#include <globals.h>

using namespace globals;

class FpsUnlock : public FeatureFactory
{
private:
	structs::MinMax FpsData = {0,1000,144};
	float fFrameRateLimitDefault = 60.0f;
	char fpsText[32];
	bool bUnlimited{ true };
	bool bShowFps{ true };

public:
	void Render();
	void Draw();
	void Run();
};