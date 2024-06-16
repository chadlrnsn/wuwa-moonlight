#include "Debug_menu.h"

#include <SDK.hpp>
#include <globals.h>
#include "Features.h"



//SDK::UGameInstance* UGameInstance = World->OwningGameInstance;
//SDK::ULocalPlayer* LocalPlayer = UGameInstance->LocalPlayers[0];
//SDK::APlayerController* APlayerController = LocalPlayer->PlayerController;
//SDK::APawn* APawn = APlayerController->AcknowledgedPawn;
//DWORD speed = APawn->CustomTimeDilation;


void DebugMenu::DebugMainPage()
{

	SDK::UWorld* World = SDK::UWorld::GetWorld();
	SDK::UEngine* Engine = SDK::UEngine::GetEngine();


	//SDK::APlayerController* MyController = World->OwningGameInstance->LocalPlayers[0]->PlayerController;

	//SDK::UGameInstance* OwningGameInstance = World->OwningGameInstance;
	//if (OwningGameInstance != nullptr)
	//	ImGui::Text("Instance 0x%d", &OwningGameInstance);

	//SDK::ULocalPlayer* LocalPlayer = World->OwningGameInstance->LocalPlayers[0];

	ImGui::Text("Build %s", &BuildInfo);
	if (World != nullptr && World->OwningGameInstance != nullptr) 
	{
		//SDK::AActor Actor = SDK::AActor::IsA(SDK::ULocalPlayer::StaticClass())

		ImGui::Text("GWorld -> 0x%d", &World);
		ImGui::Text("GEngine -> 0x%d", &Engine);
		ImGui::Text("LocalPlayer -> 0x%d", &World->OwningGameInstance->LocalPlayers[0]);
		ImGui::Text("APlayerController -> 0x%d", &World->OwningGameInstance->LocalPlayers[0]->PlayerController);
		ImGui::Text("APawn -> 0x%d", &World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn);
		ImGui::SliderFloat("Speedhack current character", &World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn->CustomTimeDilation, 0.1f, 100.0f);
		//ImGui::Checkbox("Stamina", &)
		//SDK::ACharacter* Character = &World->OwningGameInstance->LocalPlayers[0]->PlayerController->Character;
		
	}
}
