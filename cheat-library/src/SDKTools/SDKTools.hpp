#pragma once
#include "Player.h"
#include "World.h"
#include <wuwa-base/util.h>

using namespace util;

inline bool IsFullyLoaded()
{
	try
	{
		UWorld* World = UWorld::GetWorld();
		if (!IsValidPointer(World))
		{
			std::cerr << "No world found" << std::endl;
			return false;
		}

		UGameInstance* GameInstance = World->OwningGameInstance;
		if (!IsValidPointer(GameInstance))
		{
			std::cerr << "No GameInstace found" << std::endl;
			return false;
		}

		ULocalPlayer* LocalPlayer = GameInstance->LocalPlayers.Num() > 0 ? GameInstance->LocalPlayers[0] : nullptr;
		if (!IsValidPointer(LocalPlayer))
		{
			std::cerr << "No LocalPlayer found" << std::endl;
			return false;
		}

		APlayerController* PlayerController = LocalPlayer->PlayerController;
		if (!IsValidPointer(PlayerController))
		{
			std::cerr << "No PlayerController found" << std::endl;
			return false;
		}

		APawn* AcknowledgedPawn = PlayerController->AcknowledgedPawn;
		if (!IsValidPointer(AcknowledgedPawn))
		{
			std::cerr << "No Pawn found" << std::endl;
			return false;
		}

		APawn* IsPawnControled = (APawn*)AcknowledgedPawn->IsPawnControlled();
		if (!IsPawnControled)
		{
			std::cerr << "Pawn did not controlling!" << std::endl;
			return false;
		}

		APawn* IsControlled = (APawn*)AcknowledgedPawn->IsControlled();
		if (!IsControlled)
		{
			std::cerr << "Pawn not controlling!" << std::endl;
			return false;
		}

		APawn* IsPlayerControled = (APawn*)AcknowledgedPawn->IsPlayerControlled();
		if (!IsPlayerControled)
		{
			std::cerr << "Player not controlling!" << std::endl;
			return false;
		}

		APawn* IsLocallyControlled = (APawn*)AcknowledgedPawn->IsLocallyControlled();
		if (!IsLocallyControlled)
		{
			std::cerr << "Localy not controlling!" << std::endl;
			return false;
		}


	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return false;
	}
	catch (...)
	{
		std::cerr << "Unhandeled exception" << std::endl;
		return false;
	}

	return true;
}



/*inline bool()
{
	PCURSORINFO CursorInfo;
	GetCursorInfo(CursorInfo);
	if (CursorInfo)
		CursorInfo->flags |= CURSOR_SHOWING;

	return UEngine::GetEngine() && ;
}*/