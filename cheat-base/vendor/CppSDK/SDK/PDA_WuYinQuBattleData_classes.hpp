#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PDA_WuYinQuBattleData

#include "Basic.hpp"

#include "EWuYinQuState_structs.hpp"
#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PDA_WuYinQuBattleData.PDA_WuYinQuBattleData_C
// 0x0078 (0x00B0 - 0x0038)
class UPDA_WuYinQuBattleData_C final : public UPrimaryDataAsset
{
public:
	float                                         IdleToFightingTransitionTime;                      // 0x0038(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FightingTransitionTime;                            // 0x003C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FightingToIdleTransitionTime;                      // 0x0040(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_44[0x4];                                       // 0x0044(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UCurveFloat*                            IdleToFightingCurve;                               // 0x0048(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCurveFloat*                            FightingTransitionCurve;                           // 0x0050(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCurveFloat*                            FightingToIdleCurve;                               // 0x0058(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UPDA_WuYinQuBattleIdleData_C*           WuYinQuIdleData;                                   // 0x0060(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UPDA_WuYinQuBattleFightingData_C*       WuYinQuFightingData1;                              // 0x0068(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UPDA_WuYinQuBattleFightingData_C*       WuYinQuFightingData2;                              // 0x0070(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UPDA_WuYinQuBattleFightingData_C*       WuYinQuFightingData3;                              // 0x0078(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EWuYinQuState                                 Test;                                              // 0x0080(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_81[0x7];                                       // 0x0081(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UMaterialParameterCollection*           GlobalMPC;                                         // 0x0088(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCurveFloat*                            LandscapeShowingRadiusCurve;                       // 0x0090(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCurveFloat*                            LandscapeFadingRadiusCurve;                        // 0x0098(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UPDA_InteractionGlobalConfigParameters_C* GlobalInteractionParameterOverride;                // 0x00A0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         TriggerOuterSize;                                  // 0x00A8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         TriggerInnerSize;                                  // 0x00AC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PDA_WuYinQuBattleData_C">();
	}
	static class UPDA_WuYinQuBattleData_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPDA_WuYinQuBattleData_C>();
	}
};
static_assert(alignof(UPDA_WuYinQuBattleData_C) == 0x000008, "Wrong alignment on UPDA_WuYinQuBattleData_C");
static_assert(sizeof(UPDA_WuYinQuBattleData_C) == 0x0000B0, "Wrong size on UPDA_WuYinQuBattleData_C");
static_assert(offsetof(UPDA_WuYinQuBattleData_C, IdleToFightingTransitionTime) == 0x000038, "Member 'UPDA_WuYinQuBattleData_C::IdleToFightingTransitionTime' has a wrong offset!");
static_assert(offsetof(UPDA_WuYinQuBattleData_C, FightingTransitionTime) == 0x00003C, "Member 'UPDA_WuYinQuBattleData_C::FightingTransitionTime' has a wrong offset!");
static_assert(offsetof(UPDA_WuYinQuBattleData_C, FightingToIdleTransitionTime) == 0x000040, "Member 'UPDA_WuYinQuBattleData_C::FightingToIdleTransitionTime' has a wrong offset!");
static_assert(offsetof(UPDA_WuYinQuBattleData_C, IdleToFightingCurve) == 0x000048, "Member 'UPDA_WuYinQuBattleData_C::IdleToFightingCurve' has a wrong offset!");
static_assert(offsetof(UPDA_WuYinQuBattleData_C, FightingTransitionCurve) == 0x000050, "Member 'UPDA_WuYinQuBattleData_C::FightingTransitionCurve' has a wrong offset!");
static_assert(offsetof(UPDA_WuYinQuBattleData_C, FightingToIdleCurve) == 0x000058, "Member 'UPDA_WuYinQuBattleData_C::FightingToIdleCurve' has a wrong offset!");
static_assert(offsetof(UPDA_WuYinQuBattleData_C, WuYinQuIdleData) == 0x000060, "Member 'UPDA_WuYinQuBattleData_C::WuYinQuIdleData' has a wrong offset!");
static_assert(offsetof(UPDA_WuYinQuBattleData_C, WuYinQuFightingData1) == 0x000068, "Member 'UPDA_WuYinQuBattleData_C::WuYinQuFightingData1' has a wrong offset!");
static_assert(offsetof(UPDA_WuYinQuBattleData_C, WuYinQuFightingData2) == 0x000070, "Member 'UPDA_WuYinQuBattleData_C::WuYinQuFightingData2' has a wrong offset!");
static_assert(offsetof(UPDA_WuYinQuBattleData_C, WuYinQuFightingData3) == 0x000078, "Member 'UPDA_WuYinQuBattleData_C::WuYinQuFightingData3' has a wrong offset!");
static_assert(offsetof(UPDA_WuYinQuBattleData_C, Test) == 0x000080, "Member 'UPDA_WuYinQuBattleData_C::Test' has a wrong offset!");
static_assert(offsetof(UPDA_WuYinQuBattleData_C, GlobalMPC) == 0x000088, "Member 'UPDA_WuYinQuBattleData_C::GlobalMPC' has a wrong offset!");
static_assert(offsetof(UPDA_WuYinQuBattleData_C, LandscapeShowingRadiusCurve) == 0x000090, "Member 'UPDA_WuYinQuBattleData_C::LandscapeShowingRadiusCurve' has a wrong offset!");
static_assert(offsetof(UPDA_WuYinQuBattleData_C, LandscapeFadingRadiusCurve) == 0x000098, "Member 'UPDA_WuYinQuBattleData_C::LandscapeFadingRadiusCurve' has a wrong offset!");
static_assert(offsetof(UPDA_WuYinQuBattleData_C, GlobalInteractionParameterOverride) == 0x0000A0, "Member 'UPDA_WuYinQuBattleData_C::GlobalInteractionParameterOverride' has a wrong offset!");
static_assert(offsetof(UPDA_WuYinQuBattleData_C, TriggerOuterSize) == 0x0000A8, "Member 'UPDA_WuYinQuBattleData_C::TriggerOuterSize' has a wrong offset!");
static_assert(offsetof(UPDA_WuYinQuBattleData_C, TriggerInnerSize) == 0x0000AC, "Member 'UPDA_WuYinQuBattleData_C::TriggerInnerSize' has a wrong offset!");

}
