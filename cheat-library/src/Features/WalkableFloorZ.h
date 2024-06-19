#include "Feature.h"

class WalkableFloorZ : Feature
{
private:
	bool Initalized = false;

public:
	bool bEnable = false;
	float fMaxZ = 2000.0f;
	float fMinZ = -2000.0f;
	float fZ = 0.574f;

private:

public:
	WalkableFloorZ() {};

	bool Setup() override
	{
		Initalized = true;

		return Initalized;
	};

	void Destroy() override
	{
		Initalized = false;
	}

	void HandleKeys() override {}

	void DrawMenuItems() override;

	void Render(void** args, size_t numArgs) override {}

	void Run(void** args, size_t numArgs) override;
};