#pragma once
#include <includes.h>

namespace globals {

	inline const char* BuildInfo;
	inline const char* ProjectName = "Moonlight";

	inline ProcessEvent oProcessEvent;
	inline PostRender oPostRender;

	inline UEngine* Engine;
	inline UWorld* World;
	inline UGameInstance* GameInstance;
	inline ULocalPlayer* LocalPlayer;
	inline APlayerController* PlayerController;
	inline APawn* AcknowledgedPawn;
	inline TArray<ULevel*> Levels;

	namespace tfuncs {
		inline UObject* ReSkillEvent_C;
	}

	inline bool g_ShouldDrawImGui = false;
	inline bool g_CanDrawPostRender = false;
}
