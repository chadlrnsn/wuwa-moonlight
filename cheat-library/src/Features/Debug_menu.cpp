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


using ProcessEvent = void(__thiscall*)(UObject*, UFunction*, void*);
ProcessEvent oProcessEvent = 0;

void __stdcall hkProcessEvent(UObject* caller, UFunction* fn, void* params)
{
	printf("Caller: [%s] Function: [%s] Fullname : [%s]\n", caller->GetName().c_str(), fn->GetName().c_str(), fn->GetFullName().c_str());
	return oProcessEvent(caller, fn, params);
}

BYTE* vmt_hook(void** VTable, uint32_t index, void* fn)
{
    BYTE* org = reinterpret_cast<BYTE*>(VTable[index]);

	printf("Try intercept. Original Addr: %p, New Addr: %p\n", org, fn);

    DWORD protect = 0;

    if (VirtualProtect(&VTable[index], 8, PAGE_EXECUTE_READWRITE, &protect))
    {
        VTable[index] = fn;
        VirtualProtect(&VTable[index], 8, protect, 0);
		printf("Successfully intercepted!\n");
    }
    else
    {
        std::cerr << "Failed to change memory protection!" << std::endl;
    }

    return org;
}




void DebugMenu::DebugMainPage()
{
	UEngine* Engine = UEngine::GetEngine();
	if (!Engine)
		return;


	UWorld* World = UWorld::GetWorld();
	if (!World || !IsFullyLoaded(World))
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

	if (ImGui::Button("hook this shit")) {
		UGameViewportClient* vpc = World->OwningGameInstance->LocalPlayers[0]->ViewportClient;

		if (!vpc)
			return;

		void** VFTable = reinterpret_cast<void**>(vpc->VTable);

		if (VFTable)
		{
			oProcessEvent = reinterpret_cast<decltype(oProcessEvent)>(vmt_hook(VFTable, Offsets::ProcessEventIdx, &hkProcessEvent));

			// После вызова vmt_hook
			void* new_func = VFTable[Offsets::ProcessEventIdx];
			if (new_func == &hkProcessEvent)
			{
				printf("Successfully intercepted rout!\n");
				for (int i = 0; i < 74; i++) {
					printf("[%d - [%p]]\n", i, VFTable[i]);
				}
			}
			else
			{
				printf("Successfully intercepted. Current addr: %p\n", new_func);
			}

			if (oProcessEvent)
			{
				printf("Original ProcessEvent function address: [%p] [%p]\n", (void*)oProcessEvent, &oProcessEvent);
				//hooked = true;
			}
			else
			{
				std::cerr << "Failed to get original ProcessEvent function address!" << std::endl;
			}
		}
		else {
			std::cerr << "VTable is null!" << std::endl;
		}
	}
}

static UGameViewportClient* getViewport(UWorld* world) noexcept {
	return world->OwningGameInstance->LocalPlayers[0]->ViewportClient;
}

void DebugMenu::DebugRoutine() noexcept
{
	bool hooked = false;

	//while (!hooked)
	//{

	//	UWorld* World = UWorld::GetWorld();
	//	if (!World)
	//		continue;
	//	
	//	if (!IsFullyLoaded(World))
	//		continue;

	//	if (!World->OwningGameInstance->LocalPlayers[0]->PlayerController->K2_GetPawn()->IsPawnControlled())
	//		continue;

	//	UGameViewportClient* vpc = World->OwningGameInstance->LocalPlayers[0]->ViewportClient;
	//	if (!vpc)
	//		continue;

	//	void** VFTable = reinterpret_cast<void**>(vpc->VTable);

	//	if (VFTable)
	//	{
	//		oProcessEvent = reinterpret_cast<decltype(oProcessEvent)>(vmt_hook(VFTable, Offsets::ProcessEventIdx, &hkProcessEvent));

	//		// После вызова vmt_hook
	//		void* new_func = VFTable[Offsets::ProcessEventIdx];
	//		if (new_func == &hkProcessEvent)
	//		{
	//			printf("Successfully intercepted rout!\n");
	//			for (int i = 0; i < 74; i++) {
	//				printf("[%d - [%p]]\n", i, VFTable[i]);
	//			}
	//		}
	//		else
	//		{
	//			printf("Successfully intercepted. Current addr: %p\n", new_func);
	//		}

	//		if (oProcessEvent)
	//		{
	//			printf("Original ProcessEvent function address: [%p] [%p]\n", (void*)oProcessEvent, &oProcessEvent);
	//			hooked = true;
	//		}
	//		else
	//		{
	//			std::cerr << "Failed to get original ProcessEvent function address!" << std::endl;
	//		}
	//	}
	//	else {
	//		std::cerr << "VTable is null!" << std::endl;
	//	}

	//	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	//}
}
