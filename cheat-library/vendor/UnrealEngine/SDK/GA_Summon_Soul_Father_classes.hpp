#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_Summon_Soul_Father

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GA_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GA_Summon_Soul_Father.GA_Summon_Soul_Father_C
// 0x0028 (0x0558 - 0x0530)
class UGA_Summon_Soul_Father_C : public UGA_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_GA_Summon_Soul_Father_C;            // 0x0530(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	int64                                         ___S_ID;                                           // 0x0538(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          _____;                                             // 0x0540(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3865[0x3];                                     // 0x0541(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         ___ID;                                             // 0x0544(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         __iID;                                             // 0x0548(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3866[0x4];                                     // 0x054C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class ATsBaseCharacter_C*                     __i;                                               // 0x0550(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GA_Summon_Soul_Father(int32 EntryPoint);
	void K2_OnEndAbility(bool bWasCancelled);
	void K2_ActivateAbility();
	void S___S(int32 _SID, class AActor* Entity);
	struct FTransform ____Mn();
	void _n__i(class ATsBaseCharacter_C* Param___i);
	void _____0(bool ____s_nMn);
	void __B_GetSoul(class ATsBaseCharacter_C** B_);
	void ___e();
	void __Mn__(struct FVector* ___);
	struct FVector Func______(int32 ___p, int32 _l__);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GA_Summon_Soul_Father_C">();
	}
	static class UGA_Summon_Soul_Father_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGA_Summon_Soul_Father_C>();
	}
};
static_assert(alignof(UGA_Summon_Soul_Father_C) == 0x000008, "Wrong alignment on UGA_Summon_Soul_Father_C");
static_assert(sizeof(UGA_Summon_Soul_Father_C) == 0x000558, "Wrong size on UGA_Summon_Soul_Father_C");
static_assert(offsetof(UGA_Summon_Soul_Father_C, UberGraphFrame_GA_Summon_Soul_Father_C) == 0x000530, "Member 'UGA_Summon_Soul_Father_C::UberGraphFrame_GA_Summon_Soul_Father_C' has a wrong offset!");
static_assert(offsetof(UGA_Summon_Soul_Father_C, ___S_ID) == 0x000538, "Member 'UGA_Summon_Soul_Father_C::___S_ID' has a wrong offset!");
static_assert(offsetof(UGA_Summon_Soul_Father_C, _____) == 0x000540, "Member 'UGA_Summon_Soul_Father_C::_____' has a wrong offset!");
static_assert(offsetof(UGA_Summon_Soul_Father_C, ___ID) == 0x000544, "Member 'UGA_Summon_Soul_Father_C::___ID' has a wrong offset!");
static_assert(offsetof(UGA_Summon_Soul_Father_C, __iID) == 0x000548, "Member 'UGA_Summon_Soul_Father_C::__iID' has a wrong offset!");
static_assert(offsetof(UGA_Summon_Soul_Father_C, __i) == 0x000550, "Member 'UGA_Summon_Soul_Father_C::__i' has a wrong offset!");

}

