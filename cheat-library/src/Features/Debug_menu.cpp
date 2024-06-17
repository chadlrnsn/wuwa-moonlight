#include "Debug_menu.h"

#include <SDK.hpp>
#include <globals.h>
#include "Features.h"
#include <SDKTools/SDKTools.hpp>

//UGameInstance* UGameInstance = World->OwningGameInstance;
//ULocalPlayer* LocalPlayer = UGameInstance->LocalPlayers[0];
//APlayerController* APlayerController = LocalPlayer->PlayerController;
//APawn* APawn = APlayerController->AcknowledgedPawn;
//DWORD speed = APawn->CustomTimeDilation;

using namespace SDK;

float fDefaultFOV = 90;
float fDefaultFOVOverride = 90;
bool bChangeFOV = false;

bool bChangeWorldTimeDilation = false;
float fWorldSpeed = 1;
float fCustomWorldSpeed = 1;

bool bFpsUnlock = false;

void DebugMenu::DebugMainPage()
{

	UEngine* Engine = UEngine::GetEngine();
	UWorld* World = UWorld::GetWorld();
	
	if (!SDKTools::Player::IsPlayerLoaded(World) || !SDKTools::World::IsWorldFullyLoaded(World))
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

	static float SpeedhackSliderVal = 5.0f;
	ImGui::SliderFloat("Speedhack", &SpeedhackSliderVal, 0.1f, 100.0f);
	AcknowledgedPawn->CustomTimeDilation = SpeedhackSliderVal;

	static bool bAlwaysSunny = false;
	ImGui::Checkbox("Always sunny not implemented", &bAlwaysSunny);
	if (bAlwaysSunny) {}

	// Change Default fov
	ImGui::Checkbox("Change FOV", &bChangeFOV);
	if (bChangeFOV)
	{
		ImGui::SliderFloat("## Change FOV", &fDefaultFOVOverride, 0.0f, 360.0f, "%.0f");
		PlayerController->PlayerCameraManager->DefaultFOV = fDefaultFOVOverride;
	}
	else
		PlayerController->PlayerCameraManager->DefaultFOV = fDefaultFOV;

	// World Speedhack
	//ImGui::Checkbox("World Speedhack", &bChangeWorldTimeDilation);
	//AWorldSettings* WorldSettings = World->PersistentLevel->WorldSettings;
	//if (bChangeWorldTimeDilation)
	//{
	//	ImGui::SliderFloat("## Change World Speed", &fCustomWorldSpeed, 0.1f, 5.0f, "%.1f");
	//	WorldSettings->TimeDilation = fCustomWorldSpeed;
	//}
	//else {
	//	fCustomWorldSpeed = fWorldSpeed;
	//	WorldSettings->TimeDilation = fCustomWorldSpeed;
	//}

	FVector pos = AcknowledgedPawn->K2_GetActorLocation();
	ImGui::InputFloat("X", &pos.X);
	ImGui::InputFloat("Y", &pos.Y);
	ImGui::InputFloat("Z", &pos.Z);

	FVector velocity = AcknowledgedPawn->GetVelocity();
	ImGui::Text("Velocity from AcknowledgedPawn");
	ImGui::BeginGroup();
	{
		ImGui::InputFloat("VX", &velocity.X);
		ImGui::InputFloat("VY", &velocity.Y);
		ImGui::InputFloat("VZ", &velocity.Z);
	}
	ImGui::EndGroup();

	
	ImGui::SeparatorText("CharacterMovement");
	UCharacterMovementComponent* CharacterMovement = PlayerController->Character->CharacterMovement;
	ImGui::BeginGroup();
	{
		ImGui::InputFloat("AirControl", &CharacterMovement->AirControl);

		FVector vel = CharacterMovement->Velocity;
		ImGui::Text("Velocity");
		ImGui::InputFloat("VX", &CharacterMovement->Velocity.X);
		ImGui::InputFloat("VY", &CharacterMovement->Velocity.Y);
		ImGui::InputFloat("VZ", &CharacterMovement->Velocity.Z);


		//CharacterMovement->AddImpulse(FVector{ 100.0f, 100.0f, 100.0f }, true);
	}
	ImGui::EndGroup();

	//UPuertsSetting* PuertsSettings;
	//PuertsSettings->

}
