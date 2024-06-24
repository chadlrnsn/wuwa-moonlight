#include "World.h"

using namespace SDK;

namespace SDKTools::World
{
	bool IsPersistentLevelLoaded(UWorld* World)
	{
		if (!World)
			return false;

		ULevel* PLevel = World->PersistentLevel;
		if (!PLevel || !PLevel->bIsVisible)
		{
			std::cerr << "No PersistentLevel found" << std::endl;
			return false;
		}

		TArray<ULevelStreaming*> levelStreams = World->StreamingLevels;
		if (~levelStreams.Num() > 0)
			return false;

		for (ULevelStreaming* StreamingLevel : levelStreams)
		{
			if (!StreamingLevel)
				continue;

			FName StreamingLevelName = StreamingLevel->GetWorldAssetPackageFName();
			if (sizeof(StreamingLevelName.ToString()) > 0)
			{	
				std::cout << StreamingLevelName.ToString() << std::endl;
				return true;
			}
		}


		// this is was critical bug
		// Optionally, check if streaming levels are fully loaded
		//const TArray<ULevelStreaming*>& StreamingLevels = World->StreamingLevels;
		//for (ULevelStreaming* StreamingLevel : StreamingLevels)
		//{
		//	if (StreamingLevel && !StreamingLevel->IsLevelLoaded())
		//	{
		//		std::cerr << "No Level loaded" << std::endl;
		//		return false;
		//	}
		//}

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