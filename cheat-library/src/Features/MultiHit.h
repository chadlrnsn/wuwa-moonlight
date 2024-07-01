#include "Feature.h"

class HitMultiplier : Feature
{
private:
	bool Initalized = false;

public:
	bool bEnable = false;
	int iMax = 100;
	int iMin = 1;
	int iCurrent = 2;

private:

public:
	HitMultiplier() {};

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