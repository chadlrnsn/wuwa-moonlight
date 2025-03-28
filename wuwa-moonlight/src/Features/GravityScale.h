#pragma once
#include "..\includes.h"
#include "SDK.hpp"
#include "..\globals.h"
using namespace globals;

class GravityScale
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

	void HandleKeys();

	void DrawMenuItems();

	void Render();

	void Run();
};


inline void GravityScale::DrawMenuItems()
{
	ImGui::Checkbox("Gravity Scale", &bEnable);
	if (bEnable) {
		ImGui::Text("Gravity Multiplier");
		ImGui::SliderFloat("##Gravity Multiplier", &fGravity, fMinGravity, fMaxGravity);
	}
}

inline void GravityScale::Run()
{
	if (!pawn) return;
	if (!player_controller || !player_controller->Character) return;
	SDK::UCharacterMovementComponent* Movement = player_controller->Character->CharacterMovement;

	if (bEnable && Movement)
	{
		Movement->GravityScale = fGravity;
		bOnce = false;
	}

	if (!bEnable && Movement && !bOnce)
	{
		Movement->GravityScale = 1.0f; // may be 2 its defautlt not mine function btw
		bOnce = true;
	}
}
inline GravityScale gravityScale;