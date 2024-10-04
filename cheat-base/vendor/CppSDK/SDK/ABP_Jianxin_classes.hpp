#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ABP_Jianxin

#include "Basic.hpp"

#include "ABP_BaseRole_classes.hpp"
#include "Engine_structs.hpp"


namespace SDK
{

// AnimBlueprintGeneratedClass ABP_Jianxin.ABP_Jianxin_C
// 0x0000 (0x1FC50 - 0x1FC50)
class UABP_Jianxin_C final : public UABP_BaseRole_C
{
public:
	uint8                                         Pad_1FC44[0x4];                                    // 0x1FC44(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame_ABP_Jianxin_C;                      // 0x1FC48(0x0008)(ZeroConstructor, Transient, DuplicateTransient)

public:
	void ExecuteUbergraph_ABP_Jianxin(int32 EntryPoint);
	void BlueprintUpdateAnimation(float DeltaTimeX);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ABP_Jianxin_C">();
	}
	static class UABP_Jianxin_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UABP_Jianxin_C>();
	}
};
static_assert(alignof(UABP_Jianxin_C) == 0x000010, "Wrong alignment on UABP_Jianxin_C");
static_assert(sizeof(UABP_Jianxin_C) == 0x01FC50, "Wrong size on UABP_Jianxin_C");
static_assert(offsetof(UABP_Jianxin_C, UberGraphFrame_ABP_Jianxin_C) == 0x01FC48, "Member 'UABP_Jianxin_C::UberGraphFrame_ABP_Jianxin_C' has a wrong offset!");

}
