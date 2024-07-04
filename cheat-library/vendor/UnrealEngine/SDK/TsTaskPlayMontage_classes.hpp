#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TsTaskPlayMontage

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "TsTaskAbortImmediatelyBase_classes.hpp"


namespace SDK
{

// TypeScriptGeneratedClass TsTaskPlayMontage.TsTaskPlayMontage_C
// 0x0040 (0x00F8 - 0x00B8)
class UTsTaskPlayMontage_C final : public UTsTaskAbortImmediatelyBase_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_TsTaskPlayMontage_C;                // 0x00B8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	TSoftObjectPtr<class UAnimMontage>            Montage;                                           // 0x00C0(0x0030)(Edit, BlueprintVisible, HasGetValueTypeHash)
	bool                                          MaskInteract;                                      // 0x00F0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)

public:
	void ExecuteUbergraph_TsTaskPlayMontage(int32 EntryPoint);
	void ReceiveExecuteAI(class AAIController* OwnerController, class APawn* ControlledPawn);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"TsTaskPlayMontage_C">();
	}
	static class UTsTaskPlayMontage_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTsTaskPlayMontage_C>();
	}
};
static_assert(alignof(UTsTaskPlayMontage_C) == 0x000008, "Wrong alignment on UTsTaskPlayMontage_C");
static_assert(sizeof(UTsTaskPlayMontage_C) == 0x0000F8, "Wrong size on UTsTaskPlayMontage_C");
static_assert(offsetof(UTsTaskPlayMontage_C, UberGraphFrame_TsTaskPlayMontage_C) == 0x0000B8, "Member 'UTsTaskPlayMontage_C::UberGraphFrame_TsTaskPlayMontage_C' has a wrong offset!");
static_assert(offsetof(UTsTaskPlayMontage_C, Montage) == 0x0000C0, "Member 'UTsTaskPlayMontage_C::Montage' has a wrong offset!");
static_assert(offsetof(UTsTaskPlayMontage_C, MaskInteract) == 0x0000F0, "Member 'UTsTaskPlayMontage_C::MaskInteract' has a wrong offset!");

}
