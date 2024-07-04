#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TsDecoratorCoolDown

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "AIModule_classes.hpp"


namespace SDK
{

// TypeScriptGeneratedClass TsDecoratorCoolDown.TsDecoratorCoolDown_C
// 0x0018 (0x00C0 - 0x00A8)
class UTsDecoratorCoolDown_C final : public UBTDecorator_BlueprintBase
{
public:
	struct FFloatRange                            RandomCdTime;                                      // 0x00A8(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          ReturnTrueFirstTime;                               // 0x00B8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3B97[0x3];                                     // 0x00B9(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         Id;                                                // 0x00BC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	bool PerformConditionCheckAI(class AAIController* OwnerController, class APawn* ControlledPawn);
	void InitTsVariables();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"TsDecoratorCoolDown_C">();
	}
	static class UTsDecoratorCoolDown_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTsDecoratorCoolDown_C>();
	}
};
static_assert(alignof(UTsDecoratorCoolDown_C) == 0x000008, "Wrong alignment on UTsDecoratorCoolDown_C");
static_assert(sizeof(UTsDecoratorCoolDown_C) == 0x0000C0, "Wrong size on UTsDecoratorCoolDown_C");
static_assert(offsetof(UTsDecoratorCoolDown_C, RandomCdTime) == 0x0000A8, "Member 'UTsDecoratorCoolDown_C::RandomCdTime' has a wrong offset!");
static_assert(offsetof(UTsDecoratorCoolDown_C, ReturnTrueFirstTime) == 0x0000B8, "Member 'UTsDecoratorCoolDown_C::ReturnTrueFirstTime' has a wrong offset!");
static_assert(offsetof(UTsDecoratorCoolDown_C, Id) == 0x0000BC, "Member 'UTsDecoratorCoolDown_C::Id' has a wrong offset!");

}
