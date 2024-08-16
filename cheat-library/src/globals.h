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

	inline UObject* FN_TsAnimNotifyReSkillEvent_C; // Function TsAnimNotifyReSkillEvent.TsAnimNotifyReSkillEvent_C.K2_Notify
	inline UObject* FN_TsGameplayBlueprintFunctionLibrary_C; // Function TsGameplayBlueprintFunctionLibrary.TsGameplayBlueprintFunctionLibrary_C.OnHit

	inline bool g_ShouldDrawImGui = false;
	inline bool g_CanDrawPostRender = false;
}
