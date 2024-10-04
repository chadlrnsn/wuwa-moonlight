#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_Skill_Destroy_Zhaohuan_Vision

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GA_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GA_Skill_Destroy_Zhaohuan_Vision.GA_Skill_Destroy_Zhaohuan_Vision_C
// 0x0040 (0x0598 - 0x0558)
class UGA_Skill_Destroy_Zhaohuan_Vision_C final : public UGA_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_GA_Skill_Destroy_Zhaohuan_Vision_C; // 0x0558(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	int32                                         ___ID;                                             // 0x0560(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_564[0x4];                                      // 0x0564(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class ATsBaseCharacter_C*                     ___;                                               // 0x0568(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         P_Handle;                                          // 0x0570(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_574[0x4];                                      // 0x0574(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UPD_CharacterControllerData_C*          P_Mn;                                              // 0x0578(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          _____GA_Skill_Destroy_Zhaohuan_Vision_C;           // 0x0580(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_581[0x7];                                      // 0x0581(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UObject*                                ____P_;                                            // 0x0588(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ATsBaseCharacter_C*                     ___a;                                              // 0x0590(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_GA_Skill_Destroy_Zhaohuan_Vision(int32 EntryPoint);
	void K2_OnEndAbility(bool bWasCancelled);
	void K2_ActivateAbility();
	void EventReceived_18B59F5945020DB23C42FD88C3741FC0(const struct FGameplayEventData& Payload);
	void EventReceived_18B59F5945020DB23C42FD88ADE7C2AB(const struct FGameplayEventData& Payload);
	void Added_21071CB943CD992BF8EFD6A38F97C8BA(const struct FGameplayTag& Tag);
	void OnCompleted_5D118C384AE61F1C80292E81A3FE8FC3();
	void OnBlendOut_5D118C384AE61F1C80292E81A3FE8FC3();
	void OnInterrupted_5D118C384AE61F1C80292E81A3FE8FC3();
	void OnCancelled_5D118C384AE61F1C80292E81A3FE8FC3();
	void OnTick_5D118C384AE61F1C80292E81A3FE8FC3();
	void Added_21071CB943CD992BF8EFD6A313C14AE3(const struct FGameplayTag& Tag);
	void ____p();
	void ___apn(class ATsBaseCharacter_C* Entity, bool* __0, struct FSVisionData* __L);
	void _______3();
	void __4_i();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GA_Skill_Destroy_Zhaohuan_Vision_C">();
	}
	static class UGA_Skill_Destroy_Zhaohuan_Vision_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGA_Skill_Destroy_Zhaohuan_Vision_C>();
	}
};
static_assert(alignof(UGA_Skill_Destroy_Zhaohuan_Vision_C) == 0x000008, "Wrong alignment on UGA_Skill_Destroy_Zhaohuan_Vision_C");
static_assert(sizeof(UGA_Skill_Destroy_Zhaohuan_Vision_C) == 0x000598, "Wrong size on UGA_Skill_Destroy_Zhaohuan_Vision_C");
static_assert(offsetof(UGA_Skill_Destroy_Zhaohuan_Vision_C, UberGraphFrame_GA_Skill_Destroy_Zhaohuan_Vision_C) == 0x000558, "Member 'UGA_Skill_Destroy_Zhaohuan_Vision_C::UberGraphFrame_GA_Skill_Destroy_Zhaohuan_Vision_C' has a wrong offset!");
static_assert(offsetof(UGA_Skill_Destroy_Zhaohuan_Vision_C, ___ID) == 0x000560, "Member 'UGA_Skill_Destroy_Zhaohuan_Vision_C::___ID' has a wrong offset!");
static_assert(offsetof(UGA_Skill_Destroy_Zhaohuan_Vision_C, ___) == 0x000568, "Member 'UGA_Skill_Destroy_Zhaohuan_Vision_C::___' has a wrong offset!");
static_assert(offsetof(UGA_Skill_Destroy_Zhaohuan_Vision_C, P_Handle) == 0x000570, "Member 'UGA_Skill_Destroy_Zhaohuan_Vision_C::P_Handle' has a wrong offset!");
static_assert(offsetof(UGA_Skill_Destroy_Zhaohuan_Vision_C, P_Mn) == 0x000578, "Member 'UGA_Skill_Destroy_Zhaohuan_Vision_C::P_Mn' has a wrong offset!");
static_assert(offsetof(UGA_Skill_Destroy_Zhaohuan_Vision_C, _____GA_Skill_Destroy_Zhaohuan_Vision_C) == 0x000580, "Member 'UGA_Skill_Destroy_Zhaohuan_Vision_C::_____GA_Skill_Destroy_Zhaohuan_Vision_C' has a wrong offset!");
static_assert(offsetof(UGA_Skill_Destroy_Zhaohuan_Vision_C, ____P_) == 0x000588, "Member 'UGA_Skill_Destroy_Zhaohuan_Vision_C::____P_' has a wrong offset!");
static_assert(offsetof(UGA_Skill_Destroy_Zhaohuan_Vision_C, ___a) == 0x000590, "Member 'UGA_Skill_Destroy_Zhaohuan_Vision_C::___a' has a wrong offset!");

}
