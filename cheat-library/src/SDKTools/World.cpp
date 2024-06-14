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
			return false;

		// Optionally, check if streaming levels are fully loaded
		const TArray<ULevelStreaming*>& StreamingLevels = World->StreamingLevels;
		for (ULevelStreaming* StreamingLevel : StreamingLevels)
		{
			if (StreamingLevel && !StreamingLevel->IsLevelLoaded())
			{
				return false;
			}
		}

		return true;
	}
}