#include "MultiHit.h"

void HitMultiplier::DrawMenuItems()
{
	ImGui::Checkbox("Hit multiplier", &bEnable);
	ImGui::BeginGroup();
	if (bEnable) {
		ImGui::Text("Hit multiplier");
		ImGui::SliderInt("##Hit multiplier", &iCurrent, iMin, iMax);
	}
	ImGui::EndGroup();
}

void HitMultiplier::Run(void** args, size_t numArgs)
{
	if (!Initalized)
		return;

	if (numArgs != 1)
	{
		Destroy();
		return;
	}

	SDK::APawn* AcknowledgedPawn = (SDK::APawn*)args[0];

	//if (bEnable && OnHit)
	//{
	//	Movement->WalkableFloorZ = fZ;
	//}

	//if (!bEnable && Movement)
	//{
	//	Movement->WalkableFloorZ = 0.574f;
	//}
}
