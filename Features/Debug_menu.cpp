#include "Debug_menu.h"

#include "../SDK.hpp"



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

	if (World != nullptr && World->OwningGameInstance != nullptr) {

		ImGui::Text("GWorld -> 0x%d", &World);
		ImGui::Text("GEngine -> 0x%d", &Engine);
		ImGui::Text("LocalPlayer -> 0x%d", &World->OwningGameInstance->LocalPlayers[0]);
		ImGui::Text("APlayerController -> 0x%d", &World->OwningGameInstance->LocalPlayers[0]->PlayerController);
		ImGui::Text("APawn -> 0x%d", &World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn);
		ImGui::SliderFloat("Speedhack", &World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn->CustomTimeDilation, 0.1f, 100.0f);

	}
}
