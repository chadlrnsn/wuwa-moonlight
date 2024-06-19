#include "Player.h"

using namespace SDK;

namespace SDKTools::Player
{


	bool IsPawnControlled(APawn* pawn)
	{
		return pawn->IsPawnControlled();
	}

	bool IsPlayerLoaded(UWorld* World)
	{
		
		if (!World)
		{
			std::cerr << "No world found" << std::endl;
			return false;
		}

		UGameInstance* GameInstance = World->OwningGameInstance;
		if (!GameInstance)
		{
			std::cerr << "No GameInstace found" << std::endl;
			return false;
		}

		ULocalPlayer* LocalPlayer = GameInstance->LocalPlayers.Num() > 0 ? GameInstance->LocalPlayers[0] : nullptr;
		if (!LocalPlayer)
		{
			std::cerr << "No LocalPlayer found" << std::endl;
			return false;
		}

		APlayerController* PlayerController = LocalPlayer->PlayerController;
		if (!PlayerController)
		{
			std::cerr << "No PlayerController found" << std::endl;
			return false;
		}

		APawn* AcknowledgedPawn = PlayerController->AcknowledgedPawn;
		if (!AcknowledgedPawn)
		{
			std::cerr << "No Pawn found" << std::endl;
			return false;
		}

		APawn* IsControled = (APawn*)AcknowledgedPawn->IsPawnControlled();
		if (!IsControled)
		{
			std::cerr << "Pawn did not controlling!" << std::endl;
			return false;
		}

		return true;
	}
}
