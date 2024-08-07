#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_CommonDodge_Soul

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GA_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GA_CommonDodge_Soul.GA_CommonDodge_Soul_C
// 0x0010 (0x0540 - 0x0530)
class UGA_CommonDodge_Soul_C final : public UGA_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_GA_CommonDodge_Soul_C;              // 0x0530(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class ABP_BaiLian_Soul_C*                     B_;                                                // 0x0538(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GA_CommonDodge_Soul(int32 EntryPoint);
	void K2_OnEndAbility(bool bWasCancelled);
	void K2_ActivateAbility();
	void OnCompleted_5D118C384AE61F1C80292E81F45766F9();
	void OnBlendOut_5D118C384AE61F1C80292E81F45766F9();
	void OnInterrupted_5D118C384AE61F1C80292E81F45766F9();
	void OnCancelled_5D118C384AE61F1C80292E81F45766F9();
	void OnTick_5D118C384AE61F1C80292E81F45766F9();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GA_CommonDodge_Soul_C">();
	}
	static class UGA_CommonDodge_Soul_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGA_CommonDodge_Soul_C>();
	}
};
static_assert(alignof(UGA_CommonDodge_Soul_C) == 0x000008, "Wrong alignment on UGA_CommonDodge_Soul_C");
static_assert(sizeof(UGA_CommonDodge_Soul_C) == 0x000540, "Wrong size on UGA_CommonDodge_Soul_C");
static_assert(offsetof(UGA_CommonDodge_Soul_C, UberGraphFrame_GA_CommonDodge_Soul_C) == 0x000530, "Member 'UGA_CommonDodge_Soul_C::UberGraphFrame_GA_CommonDodge_Soul_C' has a wrong offset!");
static_assert(offsetof(UGA_CommonDodge_Soul_C, B_) == 0x000538, "Member 'UGA_CommonDodge_Soul_C::B_' has a wrong offset!");

}

