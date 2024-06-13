#include "Feature.h"

class WalkableFloorAngle : Feature
{
private:
	bool Initalized = false;

public:
	bool bEnable = false;
	float fMaxAngle = 360.0f;
	float fMinAngle = -360.0f;
	float fAngle = 55.0f;

private:
	bool bOnce = false;

public:
	WalkableFloorAngle() {};

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

	void DrawMenuItems() override
	{
		ImGui::Checkbox("WalkableFloorAngle", &bEnable);
		if (bEnable) {
			ImGui::Text("WalkableFloorAngle");
			ImGui::SliderFloat("##WalkableFloorAngle", &fAngle, fMinAngle, fMaxAngle);
		}
	}

	void Render(void** args, size_t numArgs) override {}

	void Run(void** args, size_t numArgs) override;
};