#include "World.h"

using namespace SDK;

namespace SDKTools::World
{
	bool IsWorldFullyLoaded(UWorld* World)
	{
		if (!World)
			return false;

		ULevel* Level = World->PersistentLevel;
		if (!Level || !Level->bIsVisible)
		{
			std::cerr << "No PersistentLevel found" << std::endl;
			return false;
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
}