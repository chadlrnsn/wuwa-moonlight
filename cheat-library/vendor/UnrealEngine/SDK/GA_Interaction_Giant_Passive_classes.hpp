#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_Interaction_Giant_Passive

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GA_Passive_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GA_Interaction_Giant_Passive.GA_Interaction_Giant_Passive_C
// 0x0008 (0x0540 - 0x0538)
class UGA_Interaction_Giant_Passive_C final : public UGa_Passive_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_GA_Interaction_Giant_Passive_C;     // 0x0538(0x0008)(ZeroConstructor, Transient, DuplicateTransient)

public:
	void ExecuteUbergraph_GA_Interaction_Giant_Passive(int32 EntryPoint);
	void K2_OnEndAbility(bool bWasCancelled);
	void K2_ActivateAbility();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GA_Interaction_Giant_Passive_C">();
	}
	static class UGA_Interaction_Giant_Passive_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGA_Interaction_Giant_Passive_C>();
	}
};
static_assert(alignof(UGA_Interaction_Giant_Passive_C) == 0x000008, "Wrong alignment on UGA_Interaction_Giant_Passive_C");
static_assert(sizeof(UGA_Interaction_Giant_Passive_C) == 0x000540, "Wrong size on UGA_Interaction_Giant_Passive_C");
static_assert(offsetof(UGA_Interaction_Giant_Passive_C, UberGraphFrame_GA_Interaction_Giant_Passive_C) == 0x000538, "Member 'UGA_Interaction_Giant_Passive_C::UberGraphFrame_GA_Interaction_Giant_Passive_C' has a wrong offset!");

}

