#include "Debug_menu.h"

#include <SDK.hpp>
#include <globals.h>
#include "Features.h"
#include <SDKTools/SDKTools.hpp>
#include <wuwa-base/util.h>

using namespace SDK;

typedef void(__thiscall* processEventFn)(SDK::UObject*, SDK::UObject*, void*);
using fn = void(__thiscall*)(UObject*, UObject*);
using pevent_fn = void(__thiscall*)(UObject*, UObject*, void* params);

fn original = 0;
pevent_fn oProcessEvent = 0;
int post_render_index = 0x46;
int post_event_index = 0x49;


void PostRenderHook(UObject* _this, UObject* canvas)
{
	original(_this, canvas);
}

void hkProcessEvent(UObject* caller, UFunction* fn, void* params) {
	oProcessEvent(caller, fn, params);
}

BYTE* vmt_hook(void** VTable, int32 index, void* fn)
{
	BYTE* org = reinterpret_cast<BYTE*>(VTable[index]);

	DWORD protect = 0;

	VirtualProtect(&VTable[index], 8, PAGE_EXECUTE_READWRITE, &protect);

	VTable[index] = fn;

	VirtualProtect(&VTable[index], 8, protect, 0);
	return org;
}

float fDefaultFOV = 90;
float fDefaultFOVOverride = 90;
bool bChangeFOV = false;

bool bChangeWorldTimeDilation = false;
float fWorldSpeed = 1;
float fCustomWorldSpeed = 1;

bool bFpsUnlock = false;

void DebugMenu::DebugMainPage()
{

	static DWORD protect = 0;

	UEngine* Engine = UEngine::GetEngine();
	UWorld* World = UWorld::GetWorld();
	
	if (!IsFullyLoaded())
		return;

	ULocalPlayer* LocalPlayer = World->OwningGameInstance->LocalPlayers[0];
	APlayerController* PlayerController = LocalPlayer->PlayerController;
	APawn* AcknowledgedPawn = PlayerController->AcknowledgedPawn;


	ImGui::Text("Build %s", &BuildInfo);
	ImGui::Text("GWorld -> 0x%d", &World);
	ImGui::Text("GEngine -> 0x%d", &Engine);
	ImGui::Text("LocalPlayer -> 0x%d", &LocalPlayer);
	ImGui::Text("APlayerController -> 0x%d", &PlayerController);
	ImGui::Text("APawn -> 0x%d", &AcknowledgedPawn);

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



	static FVector newActorScale{};

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

	static bool bMapTeleport = false;
	ImGui::Checkbox("Map teleport", &bMapTeleport);
	ImGui::SameLine();
	ImGui::Text("Double click on map");

	if (bMapTeleport) {
		ImGui::Text("in dev");
	}

	static bool bHits = false;
	static bool bOnce2 = false;
	static void** VFTable = &(LocalPlayer->ViewportClient->VTable);


	ImGui::Checkbox("Abilities", &bHits);

	//if (bHits && !bOnce2) {
	//	
	//	ImGui::Begin("Abilities", 0);

	//	// Get ability system component from pawn

	//	AActor* OwnerActor = AcknowledgedPawn;
	//	UAbilitySystemComponent* AbilitySystemComponent = static_cast<UAbilitySystemComponent*>(AcknowledgedPawn->GetComponentByClass(UAbilitySystemComponent::StaticClass()));

	//	// Show all abilities
	//	static float fDuration = 0.0f;

	//	ImGui::InputFloat("Duration", &fDuration);
	//	if (AbilitySystemComponent->IncomingDuration != fDuration) {
	//		AbilitySystemComponent->IncomingDuration = fDuration;
	//	}
	//
	//	// Print All Abilities
	//	ImGui::Spacing();

	//	static int i = 0;

	//	ImGui::Text("Abilities:");

	//	for (i = 0; i < AbilitySystemComponent->ActivatableAbilities.Owner->ActivatableAbilities.Items.Num(); i++)
	//	{
	//		if (!IsValidPointer(AbilitySystemComponent)) continue;

	//		if (AbilitySystemComponent->ActivatableAbilities.Owner->OwnerActor->GetOwner())
	//		{
	//			UGameplayAbility* OwnedAbility = AbilitySystemComponent->ActivatableAbilities.Owner->ActivatableAbilities.Items[i].Ability;

	//			
	//			ImGui::Text("Ability: [%s] Dur: [%.0f]", OwnedAbility->Name.ToString().c_str(), OwnedAbility->GetCooldownTimeRemaining());
	//			if (ImGui::Button("Activate tasks")) {
	//				OwnedAbility->ActiveTasks;
	//			} 
	//			ImGui::SameLine();

	//			if (ImGui::Button("Activate")) {
	//				OwnedAbility->ActivationRequiredTags.GameplayTags.Clear();
	//				OwnedAbility->ActivationRequiredTags.ParentTags.Clear();
	//			}

	//			ImGui::SameLine();

	//			static bool bActivateTags = false;
	//			ImGui::Checkbox("tags", &bActivateTags);
	//			if (bActivateTags) {
	//				for (static int j = 0; j < OwnedAbility->ActivationRequiredTags.GameplayTags.Num(); j++) {
	//					ImGui::Text(OwnedAbility->ActivationRequiredTags.GameplayTags[j].TagName.ToString().c_str());
	//				}
	//			}

	//			ImGui::Checkbox("bRetriggerInstancedAbility", &OwnedAbility->bRetriggerInstancedAbility);

	//			//ImGui::Text("%x", OwnedAbility->ProcessEvent());

	//		}
	//	}

	//	ImGui::End();
	//}
}
