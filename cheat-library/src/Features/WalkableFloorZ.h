#pragma once
#include <includes.h>
#include <globals.h>
using namespace globals;

class WalkableFloorZ 
{
public:
	bool bEnable = false;
	float fMaxZ = 2000.0f;
	float fMinZ = -2000.0f;
	float fZ = 0.574f;
	bool bOnce = true;

public:

	void HandleKeys();

	void DrawMenuItems();

	void Render();

	void Run(APlayerController*);
};


inline void WalkableFloorZ::DrawMenuItems()
{
	ImGui::Checkbox("WalkableFloorZ", &bEnable);
	if (bEnable) {
		ImGui::Text("WalkableFloorZ");
		ImGui::SliderFloat("##WalkableFloorZ", &fZ, fMinZ, fMaxZ);
	}
}

inline void WalkableFloorZ::Run(APlayerController* playerController)
{
	if (!playerController) return;

	SDK::UCharacterMovementComponent* Movement = playerController->Character->CharacterMovement;

	if (bEnable && Movement)
	{
		Movement->WalkableFloorZ = fZ;
		bOnce = true;
	}

	if (!bEnable && Movement && bOnce)
	{
		Movement->WalkableFloorZ = 0.574f;
		bOnce = false;
	}
}

inline WalkableFloorZ walkFloorZ;