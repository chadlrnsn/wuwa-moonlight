#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_Relax_Vision

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GA_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GA_Relax_Vision.GA_Relax_Vision_C
// 0x0010 (0x0568 - 0x0558)
class UGA_Relax_Vision_C final : public UGA_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_GA_Relax_Vision_C;                  // 0x0558(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class ATsBaseCharacter_C*                     ___;                                               // 0x0560(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GA_Relax_Vision(int32 EntryPoint);
	void K2_OnEndAbility(bool bWasCancelled);
	void K2_ActivateAbility();
	void OnCompleted_5D118C384AE61F1C80292E817D55CBB2();
	void OnBlendOut_5D118C384AE61F1C80292E817D55CBB2();
	void OnInterrupted_5D118C384AE61F1C80292E817D55CBB2();
	void OnCancelled_5D118C384AE61F1C80292E817D55CBB2();
	void OnTick_5D118C384AE61F1C80292E817D55CBB2();
	void ___apn(class ATsBaseCharacter_C* Entity, bool* __0, struct FSVisionData* __L);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GA_Relax_Vision_C">();
	}
	static class UGA_Relax_Vision_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGA_Relax_Vision_C>();
	}
};
static_assert(alignof(UGA_Relax_Vision_C) == 0x000008, "Wrong alignment on UGA_Relax_Vision_C");
static_assert(sizeof(UGA_Relax_Vision_C) == 0x000568, "Wrong size on UGA_Relax_Vision_C");
static_assert(offsetof(UGA_Relax_Vision_C, UberGraphFrame_GA_Relax_Vision_C) == 0x000558, "Member 'UGA_Relax_Vision_C::UberGraphFrame_GA_Relax_Vision_C' has a wrong offset!");
static_assert(offsetof(UGA_Relax_Vision_C, ___) == 0x000560, "Member 'UGA_Relax_Vision_C::___' has a wrong offset!");

}
