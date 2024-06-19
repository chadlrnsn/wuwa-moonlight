#include "Feature.h"

class GravityScale : Feature
{
private:
	bool Initalized = false;

public:
	bool bEnable = false;
	float fMaxGravity = 2.0f;
	float fMinGravity = -2.0f;
	float fGravity = 1.0f;

private:
	bool bOnce = false;

public:
	GravityScale() {};

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