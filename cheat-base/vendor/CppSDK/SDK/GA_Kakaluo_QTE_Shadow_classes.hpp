#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_Kakaluo_QTE_Shadow

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GA_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GA_Kakaluo_QTE_Shadow.GA_Kakaluo_QTE_Shadow_C
// 0x0018 (0x0570 - 0x0558)
class UGA_Kakaluo_QTE_Shadow_C final : public UGA_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_GA_Kakaluo_QTE_Shadow_C;            // 0x0558(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	bool                                          ________GA_Kakaluo_QTE_Shadow_C;                   // 0x0560(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_561[0x7];                                      // 0x0561(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class ATsBaseCharacter_C*                     AaW;                                               // 0x0568(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GA_Kakaluo_QTE_Shadow(int32 EntryPoint);
	void K2_OnEndAbility(bool bWasCancelled);
	void K2_ActivateAbility();
	void OnCompleted_5D118C384AE61F1C80292E819A7A540E();
	void OnBlendOut_5D118C384AE61F1C80292E819A7A540E();
	void OnInterrupted_5D118C384AE61F1C80292E819A7A540E();
	void OnCancelled_5D118C384AE61F1C80292E819A7A540E();
	void OnTick_5D118C384AE61F1C80292E819A7A540E();
	void EventReceived_18B59F5945020DB23C42FD88FBE7286E(const struct FGameplayEventData& Payload);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GA_Kakaluo_QTE_Shadow_C">();
	}
	static class UGA_Kakaluo_QTE_Shadow_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGA_Kakaluo_QTE_Shadow_C>();
	}
};
static_assert(alignof(UGA_Kakaluo_QTE_Shadow_C) == 0x000008, "Wrong alignment on UGA_Kakaluo_QTE_Shadow_C");
static_assert(sizeof(UGA_Kakaluo_QTE_Shadow_C) == 0x000570, "Wrong size on UGA_Kakaluo_QTE_Shadow_C");
static_assert(offsetof(UGA_Kakaluo_QTE_Shadow_C, UberGraphFrame_GA_Kakaluo_QTE_Shadow_C) == 0x000558, "Member 'UGA_Kakaluo_QTE_Shadow_C::UberGraphFrame_GA_Kakaluo_QTE_Shadow_C' has a wrong offset!");
static_assert(offsetof(UGA_Kakaluo_QTE_Shadow_C, ________GA_Kakaluo_QTE_Shadow_C) == 0x000560, "Member 'UGA_Kakaluo_QTE_Shadow_C::________GA_Kakaluo_QTE_Shadow_C' has a wrong offset!");
static_assert(offsetof(UGA_Kakaluo_QTE_Shadow_C, AaW) == 0x000568, "Member 'UGA_Kakaluo_QTE_Shadow_C::AaW' has a wrong offset!");

}

