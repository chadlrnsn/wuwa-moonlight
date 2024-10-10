#pragma once
#include <includes.h>

namespace globals {

	inline const char* BuildInfo;
	inline const char* ProjectName = "Moonlight";
	inline std::atomic_bool g_break = false;

	inline ProcessEvent oProcessEvent;
	inline PostRender oPostRender;

	inline UEngine* engine;
	inline UWorld* world;
	inline UGameInstance* game_instance;
	inline TArray<SDK::ULocalPlayer*> local_players;
	inline ULocalPlayer* local_player;
	inline APlayerController* player_controller;
	inline APawn* pawn;


	inline UObject* FN_TsAnimNotifyReSkillEvent_C; // Function TsAnimNotifyReSkillEvent.TsAnimNotifyReSkillEvent_C.K2_Notify
	inline UObject* FN_TsAnimNotifyStateCounterAttack_C; // Function TsAnimNotifyStateCounterAttack.TsAnimNotifyStateCounterAttack_C.K2_NotifyBegin

	inline bool g_ShouldDrawImGui = false;
	inline bool g_CanDrawPostRender = false;
}
