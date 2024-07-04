#include "MultiHit.h"
#include "imgui-notify/backends/ImGuiNotify.hpp"

void HitMultiplier::DrawMenuItems()
{
	ImGui::Checkbox("Multi Hit", &bEnable);
	if (bEnable) {
		ImGui::BeginChild(2, ImVec2(0,100), 1);
			ImGui::Text("Hit multiplier");
			ImGui::SliderInt("##Hit multiplier", &iCurrent, iMin, iMax);
		ImGui::EndChild();
	}
}

typedef void(__fastcall* tProcessEvent)(UObject* Class, UFunction* Function, void* Parms);
static tProcessEvent hkProcessEvent = nullptr;

void HookedProcessEvent(UObject* Class, UFunction* Function, void* Parms)
{
	std::printf("[#] Hello From ProcessEvent\n");

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
	UWorld* World = (UWorld*)args[1];

	if (bEnable)
	{

		USkeletalMeshComponent* SkeletalMeshComponent = static_cast<USkeletalMeshComponent*>(Pawn->GetComponentByClass(USkeletalMeshComponent::StaticClass()));
		ULocalPlayer* LocalPlayer = World->OwningGameInstance->LocalPlayers[0];
		UGameViewportClient* Viewport = LocalPlayer->ViewportClient;
		UObject* func = LocalPlayer->FindObject("TsAnimNotifyReSkillEvent_C.K2_Notify");



		//UAbilitySystemComponent = Pawn->GetComponentByClass(UAbilitySystemComponent::StaticClass());
		//ULightComponent = static_cast<ULightComponent*>(Pawn->GetComponentByClass(ULightComponent::StaticClass());

	}
	else
	{

	}

}
