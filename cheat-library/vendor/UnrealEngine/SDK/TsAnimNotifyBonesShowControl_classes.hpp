#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TsAnimNotifyBonesShowControl

#include "Basic.hpp"

#include "KuroRenderingRuntimeBPPlugin_classes.hpp"


namespace SDK
{

// TypeScriptGeneratedClass TsAnimNotifyBonesShowControl.TsAnimNotifyBonesShowControl_C
// 0x0010 (0x0058 - 0x0048)
class UTsAnimNotifyBonesShowControl_C final : public UKuroAnimNotify
{
public:
	class FName                                   BoneName;                                          // 0x0048(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Show;                                              // 0x0054(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)

public:
	bool K2_Notify(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation);

	class FString GetNotifyName() const;

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"TsAnimNotifyBonesShowControl_C">();
	}
	static class UTsAnimNotifyBonesShowControl_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTsAnimNotifyBonesShowControl_C>();
	}
};
static_assert(alignof(UTsAnimNotifyBonesShowControl_C) == 0x000008, "Wrong alignment on UTsAnimNotifyBonesShowControl_C");
static_assert(sizeof(UTsAnimNotifyBonesShowControl_C) == 0x000058, "Wrong size on UTsAnimNotifyBonesShowControl_C");
static_assert(offsetof(UTsAnimNotifyBonesShowControl_C, BoneName) == 0x000048, "Member 'UTsAnimNotifyBonesShowControl_C::BoneName' has a wrong offset!");
static_assert(offsetof(UTsAnimNotifyBonesShowControl_C, Show) == 0x000054, "Member 'UTsAnimNotifyBonesShowControl_C::Show' has a wrong offset!");

}
