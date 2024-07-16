#include "Debug_menu.h"

#include <SDK.hpp>
#include <globals.h>
#include "Features.h"
#include <SDKTools/SDKTools.hpp>
#include <wuwa-base/util.h>
#include <minhook/include/MinHook.h>
#include "SDK/TsAnimNotifyReSkillEvent_parameters.hpp"
#include "SDK/TsAnimNotifyReSkillEvent_functions.cpp"

using namespace SDK;

using fn = void(__thiscall*)(UObject*, UObject*);
using pevent_fn = void(__thiscall*)(UObject*, UObject*, void* params);

fn original = 0;
pevent_fn oProcessEvent = 0;

void hkPostRender(UObject* _this, UObject* canvas)
{
	original(_this, canvas);
}

void hkProcessEvent(UObject* caller, UFunction* fn, void* params) 
{
	printf("Caller: [%s] Function Called: [%s] Fullname : [%s]\n", caller->GetName().c_str(), fn->GetName().c_str(), fn->GetFullName().c_str());
	oProcessEvent(caller, fn, params);
}

BYTE* vmt_hook(void** VTable, uint32_t index, void* fn)
{
    BYTE* org = reinterpret_cast<BYTE*>(VTable[index]);

    DWORD protect = 0;

    VirtualProtect(&VTable[index], 8, PAGE_EXECUTE_READWRITE, &protect);

    std::cout << "Hooking index: " << index << std::endl;

    VTable[index] = fn;

    std::cout << "Function hooked successfully at index: " << index << std::endl;

    VirtualProtect(&VTable[index], 8, protect, 0);

    return org;
}



void DebugMenu::DebugMainPage()
{
	UEngine* Engine = UEngine::GetEngine();
	UWorld* World = UWorld::GetWorld();
	if (!Engine || !IsFullyLoaded(World))
		return;


	ULocalPlayer* LocalPlayer = World->OwningGameInstance->LocalPlayers[0];
	APlayerController* PlayerController = LocalPlayer->PlayerController;
	APawn* AcknowledgedPawn = PlayerController->AcknowledgedPawn;

	ImGui::Text("GWorld -> 0x%d", &World);
	ImGui::Text("GEngine -> 0x%d", &Engine);
	ImGui::Text("LocalPlayer -> 0x%d", &LocalPlayer);
	ImGui::Text("APlayerController -> 0x%d", &PlayerController);
	ImGui::Text("APawn -> 0x%d", &AcknowledgedPawn);

	//if (ImGui::Button("event call"))
	//{
	//	auto vp = LocalPlayer->ViewportClient;
	//	UFunction* fn = vp->FindObject<UFunction>("Function TsAnimNotifyReSkillEvent.TsAnimNotifyReSkillEvent_C.K2_Notify");

	//	Params::TsAnimNotifyReSkillEvent_C_K2_Notify* parameters = (Params::TsAnimNotifyReSkillEvent_C_K2_Notify*)params;
	//	USkeletalMeshComponent* meshComp = parameters->MeshComp;

	//	vp->ProcessEvent(fn, parameters);
	//}

	FVector pos = AcknowledgedPawn->K2_GetActorLocation();

	ImGui::SeparatorText("CharacterMovement");
	UCharacterMovementComponent* CharacterMovement = PlayerController->Character->CharacterMovement;
	ImGui::BeginChild(1, ImVec2(0,200), true);
	{
		ImGui::InputFloat("AirControl", &CharacterMovement->AirControl);

		FVector vel = CharacterMovement->Velocity;
		ImGui::Text("Velocity");
		ImGui::SliderFloat("VX", &CharacterMovement->Velocity.X, 0.1f, 100000.0f);
		ImGui::SliderFloat("VY", &CharacterMovement->Velocity.Y, 0.1f, 100000.0f);
		ImGui::SliderFloat("VZ", &CharacterMovement->Velocity.Z, 0.1f, 100000.0f);

	}
	ImGui::EndChild();



	static FVector newActorScale { 1.0f, 1.0f, 1.0f };

	static bool bActorscale = false;
	static bool bOnce = false;

	ImGui::Spacing();

	ImGui::Checkbox("Actor scale", &bActorscale);
	if (bActorscale) {
		ImGui::BeginChild(2, ImVec2(0, 200), true);

		ImGui::InputFloat("X", &newActorScale.X);
		ImGui::InputFloat("Y", &newActorScale.Y);
		ImGui::InputFloat("Z", &newActorScale.Z);

		ImGui::EndChild();
		AcknowledgedPawn->SetActorScale3D(newActorScale);
		bOnce = false;
	}
	if (!bActorscale && !bOnce)
	{
		AcknowledgedPawn->SetActorScale3D({1,1,1});
		bOnce = true;
	}

	static bool bOnce2 = false;
	static bool HookWorld = false;

	auto process_event_addr = (uintptr_t*)(GetModuleHandleA(0) + Offsets::ProcessEvent);
	ImGui::Checkbox("Hook world", &HookWorld);
	if (HookWorld && !bOnce2)
	{
		MH_Initialize();
		MH_CreateHook((LPVOID*)process_event_addr, &hkProcessEvent, reinterpret_cast<void**>(&oProcessEvent));
		MH_EnableHook((LPVOID*)process_event_addr);

		bOnce2 = true;
		std::cout << "Hook enabled" << std::endl;
	} 
	else if (!HookWorld && bOnce2)
	{
		MH_DisableHook((LPVOID*)process_event_addr);
		MH_RemoveHook((LPVOID*)process_event_addr);
		MH_Uninitialize();


		bOnce2 = false;
		std::cout << "Hook disabled" << std::endl;
	}	
}

void DebugMenu::DebugRoutine()
{

}
