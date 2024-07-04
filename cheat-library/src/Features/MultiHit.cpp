#include "MultiHit.h"
#include "imgui-notify/backends/ImGuiNotify.hpp"

using namespace SDK;

void HitMultiplier::DrawMenuItems()
{
	ImGui::Checkbox("Multi Hit", &bEnable);
	if (bEnable) {
		ImGui::BeginChild(1, ImVec2(0,100), 1);
			ImGui::Text("Hit multiplier");
			ImGui::SliderInt("##Hit multiplier", &iCurrent, iMin, iMax);
		ImGui::EndChild();
	}
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

	// Get pawn
	APawn* Pawn = (APawn*)args[0];

	// Get UTsAnimNotifyReSkillEvent_C instance


	// Hooking for the original player hit function 
	if (bEnable)
	{
	}
	else
	{

	}

}
