#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_Skill01_Soul

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GA_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GA_Skill01_Soul.GA_Skill01_Soul_C
// 0x0018 (0x0548 - 0x0530)
class UGA_Skill01_Soul_C final : public UGA_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_GA_Skill01_Soul_C;                  // 0x0530(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	bool                                          _0__;                                              // 0x0538(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3A75[0x7];                                     // 0x0539(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class ATsBaseCharacter_C*                     __;                                                // 0x0540(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GA_Skill01_Soul(int32 EntryPoint);
	void K2_OnEndAbility(bool bWasCancelled);
	void K2_ActivateAbility();
	void OnCompleted_5D118C384AE61F1C80292E81A92DCD93();
	void OnBlendOut_5D118C384AE61F1C80292E81A92DCD93();
	void OnInterrupted_5D118C384AE61F1C80292E81A92DCD93();
	void OnCancelled_5D118C384AE61F1C80292E81A92DCD93();
	void OnTick_5D118C384AE61F1C80292E81A92DCD93();
	void EventReceived_18B59F5945020DB23C42FD887969AA61(const struct FGameplayEventData& Payload);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GA_Skill01_Soul_C">();
	}
	static class UGA_Skill01_Soul_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGA_Skill01_Soul_C>();
	}
};
static_assert(alignof(UGA_Skill01_Soul_C) == 0x000008, "Wrong alignment on UGA_Skill01_Soul_C");
static_assert(sizeof(UGA_Skill01_Soul_C) == 0x000548, "Wrong size on UGA_Skill01_Soul_C");
static_assert(offsetof(UGA_Skill01_Soul_C, UberGraphFrame_GA_Skill01_Soul_C) == 0x000530, "Member 'UGA_Skill01_Soul_C::UberGraphFrame_GA_Skill01_Soul_C' has a wrong offset!");
static_assert(offsetof(UGA_Skill01_Soul_C, _0__) == 0x000538, "Member 'UGA_Skill01_Soul_C::_0__' has a wrong offset!");
static_assert(offsetof(UGA_Skill01_Soul_C, __) == 0x000540, "Member 'UGA_Skill01_Soul_C::__' has a wrong offset!");

}

