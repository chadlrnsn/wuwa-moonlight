#include "World.h"

using namespace SDK;

namespace SDKTools::World
{
	bool IsPersistentLevelLoaded(UWorld* World)
	{
		if (!World)
			return false;

		try {
			//ULevel* PLevel = World->PersistentLevel;
			if (!World->PersistentLevel || !World->PersistentLevel->OwningWorld)
			{
				std::cerr << "No PersistentLevel found" << std::endl;
				return false;
			}
		}
		catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			return false;
		}

		TArray<ULevelStreaming*> levelStreams = World->StreamingLevels;
		if (~levelStreams.Num() > 0)
			return false;


		return true;
	}

	bool IsLoading(UWorld* world) {

		// is exists gameinstance
		if (!world->OwningGameInstance)
			return false;
		
		// is exists gameinstance
		if (~world->OwningGameInstance->LocalPlayers.Num() > 0)
			return false;

		if (!world->OwningGameInstance->LocalPlayers[0]->PlayerController)
			return false;
		
		if (!world->StreamingLevels)
			return false;


	}
}