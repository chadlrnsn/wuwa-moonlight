#include "Player.h"

using namespace SDK;

namespace SDKTools::Player
{
	bool IsPlayerLoaded(UWorld* World)
	{
		
		if (!World)
			return false;

		UGameInstance* GameInstance = World->OwningGameInstance;
		if (!GameInstance)
			return false;

		ULocalPlayer* LocalPlayer = GameInstance->LocalPlayers.Num() > 0 ? GameInstance->LocalPlayers[0] : nullptr;
		if (!LocalPlayer)
			return false;

		APlayerController* PlayerController = LocalPlayer->PlayerController;
		if (!PlayerController)
			return false;

		APawn* AcknowledgedPawn = PlayerController->AcknowledgedPawn;
		if (!AcknowledgedPawn)
			return false;

		return AcknowledgedPawn->IsPawnControlled();
	}
}
