#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CommonEffectMoveSpline2

#include "Basic.hpp"

#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass CommonEffectMoveSpline2.CommonEffectMoveSpline2_C
// 0x0008 (0x02B0 - 0x02A8)
class ACommonEffectMoveSpline2_C final : public AActor
{
public:
	class UKuroMoveSplineComponent*               KuroMoveSpline;                                    // 0x02A8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"CommonEffectMoveSpline2_C">();
	}
	static class ACommonEffectMoveSpline2_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ACommonEffectMoveSpline2_C>();
	}
};
static_assert(alignof(ACommonEffectMoveSpline2_C) == 0x000008, "Wrong alignment on ACommonEffectMoveSpline2_C");
static_assert(sizeof(ACommonEffectMoveSpline2_C) == 0x0002B0, "Wrong size on ACommonEffectMoveSpline2_C");
static_assert(offsetof(ACommonEffectMoveSpline2_C, KuroMoveSpline) == 0x0002A8, "Member 'ACommonEffectMoveSpline2_C::KuroMoveSpline' has a wrong offset!");

}
