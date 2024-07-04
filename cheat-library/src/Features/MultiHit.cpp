#include "MultiHit.h"
#include "imgui-notify/backends/ImGuiNotify.hpp"

void HitMultiplier::DrawMenuItems()
{
	ImGui::Checkbox("Multi Hit", &bEnable);
	if (bEnable) {
		ImGui::BeginChild(1, ImVec2(0,100), 1);
			ImGui::Text("Hit multiplier");
			ImGui::SliderInt("##Hit multiplier", &iCurrent, iMin, iMax);
			if (bHooked) {
				if (ImGui::Button("activate PEH")) {
					
				}

			}
		ImGui::EndChild();
	}
}

typedef void(__fastcall* tProcessEvent)(UObject* Class, UFunction* Function, void* Parms);
static tProcessEvent hkProcessEvent = nullptr;

void HookedProcessEvent(UObject* Class, UFunction* Function, void* Parms)
{
	std::printf("[#] Hello From ProcessEvent");

	return hkProcessEvent(Class, Function, Parms);
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

	APawn* Pawn = (APawn*)args[0];

	if (bEnable)
	{
		UObject* func = UObject::FindObject("Function TsAnimNotifyReSkillEvent.TsAnimNotifyReSkillEvent_C.K2_Notify");

		USkeletalMeshComponent* SkeletalMeshComponent = static_cast<USkeletalMeshComponent*>(Pawn->GetComponentByClass(USkeletalMeshComponent::StaticClass()));
	}
	else
	{

	}

}
