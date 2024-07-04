#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_Anke_Rage2

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GA_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GA_Anke_Rage2.GA_Anke_Rage2_C
// 0x0008 (0x0538 - 0x0530)
class UGA_Anke_Rage2_C final : public UGA_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_GA_Anke_Rage2_C;                    // 0x0530(0x0008)(ZeroConstructor, Transient, DuplicateTransient)

public:
	void ExecuteUbergraph_GA_Anke_Rage2(int32 EntryPoint);
	void K2_OnEndAbility(bool bWasCancelled);
	void K2_ActivateAbility();
	void OnCompleted_5D118C384AE61F1C80292E81951B8008();
	void OnBlendOut_5D118C384AE61F1C80292E81951B8008();
	void OnInterrupted_5D118C384AE61F1C80292E81951B8008();
	void OnCancelled_5D118C384AE61F1C80292E81951B8008();
	void OnTick_5D118C384AE61F1C80292E81951B8008();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GA_Anke_Rage2_C">();
	}
	static class UGA_Anke_Rage2_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGA_Anke_Rage2_C>();
	}
};
static_assert(alignof(UGA_Anke_Rage2_C) == 0x000008, "Wrong alignment on UGA_Anke_Rage2_C");
static_assert(sizeof(UGA_Anke_Rage2_C) == 0x000538, "Wrong size on UGA_Anke_Rage2_C");
static_assert(offsetof(UGA_Anke_Rage2_C, UberGraphFrame_GA_Anke_Rage2_C) == 0x000530, "Member 'UGA_Anke_Rage2_C::UberGraphFrame_GA_Anke_Rage2_C' has a wrong offset!");

}
