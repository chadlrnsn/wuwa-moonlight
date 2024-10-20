#pragma once
#include <config.h>
#include <SDK.hpp>

using namespace SDK;

using ProcessEvent = void(__thiscall*)(UObject*, UFunction*, void*);
inline ProcessEvent oProcessEvent;

using PostRender = void(__thiscall*)(UGameViewportClient*, UCanvas*);
inline PostRender oPostRender;

namespace globals {

	inline const char* BuildInfo;
	inline const char* ProjectName = "Moonlight";
    inline std::atomic_bool(g_break) = false;

    inline UEngine* engine;
    inline UWorld* world;
    inline UGameInstance* game_instance;
    inline TArray<ULocalPlayer*> local_players;
    inline ULocalPlayer* local_player;
    inline APlayerController* player_controller;

    inline ACharacter* character;
    inline APawn* pawn;

	inline UObject* FN_TsAnimNotifyReSkillEvent_C; // Function TsAnimNotifyReSkillEvent.TsAnimNotifyReSkillEvent_C.K2_Notify
	inline UObject* FN_TsAnimNotifyStateCounterAttack_C; // Function TsAnimNotifyStateCounterAttack.TsAnimNotifyStateCounterAttack_C.K2_NotifyBegin

	inline bool g_ShouldDrawImGui = false;
	inline bool g_CanDrawPostRender = false;
}
