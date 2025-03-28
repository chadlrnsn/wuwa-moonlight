#pragma once
#include "includes.h"
//SDK error
namespace globals
{

	inline const char* BuildInfo;
	inline const char* ProjectName = "LetItHappen";

	inline ProcessEvent oProcessEvent;
	inline PostRender oPostRender;

	inline SDK::UEngine* engine = nullptr;
	inline SDK::UWorld* world = nullptr;
	inline SDK::UGameInstance* game_instance = nullptr;
	inline SDK::TArray<SDK::ULocalPlayer*> local_players;
	inline SDK::ULocalPlayer* local_player = nullptr;
	inline SDK::UGameViewportClient* viewport = nullptr;
	inline SDK::APlayerController* player_controller = nullptr;
	inline SDK::APawn* pawn = nullptr;
	inline SDK::ACharacter* character = nullptr;

	inline UObject* FN_TsAnimNotifyReSkillEvent_C;		 // Function TsAnimNotifyReSkillEvent.TsAnimNotifyReSkillEvent_C.K2_Notify
	inline UObject* FN_TsAnimNotifyStateCounterAttack_C; // Function TsAnimNotifyStateCounterAttack.TsAnimNotifyStateCounterAttack_C.K2_NotifyBegin

	inline bool g_ShouldDrawImGui = false;
	inline bool g_CanDrawPostRender = false;
}
