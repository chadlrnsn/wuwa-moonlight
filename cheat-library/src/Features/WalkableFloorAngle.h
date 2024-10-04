#pragma once
#include <includes.h>
#include <globals.h>
using namespace globals;

class WalkableFloorAngle
{
public:
	bool bEnable = false;
	float fMaxAngle = 360.0f;
	float fMinAngle = -360.0f;
	float fAngle = 55.0f;
	bool bOnce = false;

public:
	void HandleKeys();

	void DrawMenuItems()
	{
		ImGui::Checkbox("WalkableFloorAngle", &bEnable);
		if (bEnable) {
			ImGui::Text("WalkableFloorAngle");
			ImGui::SliderFloat("##WalkableFloorAngle", &fAngle, fMinAngle, fMaxAngle);
		}
	}

	void Render();

	void Run();
};

inline void WalkableFloorAngle::Run()
{
	if (!AcknowledgedPawn) return;

	SDK::UCharacterMovementComponent* Movement = PlayerController->Character->CharacterMovement;

	if (bEnable && Movement)
	{
		Movement->WalkableFloorAngle = fAngle;
		bOnce = false;
	}

	if (!bEnable && Movement && !bOnce)
	{
		Movement->WalkableFloorZ = 0.574f;
		bOnce = true;
	}
}
inline WalkableFloorAngle walkFloorAngle;