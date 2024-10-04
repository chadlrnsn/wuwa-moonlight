#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_Mingzhongzhigui_Vision

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "SCameraModifier_Settings_structs.hpp"
#include "SCameraModifier_Condition_structs.hpp"
#include "GA_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GA_Mingzhongzhigui_Vision.GA_Mingzhongzhigui_Vision_C
// 0x0150 (0x06A8 - 0x0558)
class UGA_Mingzhongzhigui_Vision_C final : public UGA_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_GA_Mingzhongzhigui_Vision_C;        // 0x0558(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class ATsBaseCharacter_C*                     _r;                                                // 0x0560(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CreateBulletDelay;                                 // 0x0568(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_56C[0x4];                                      // 0x056C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UGameplayTask_WaitDelay*                _e_____P9;                                         // 0x0570(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         _aLevel;                                           // 0x0578(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         _aID;                                              // 0x057C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FSCameraModifier_Settings              Camera_Modify_Settings;                            // 0x0580(0x0118)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	TArray<struct FSCameraModifier_Condition>     Camera_Modifier_Contions;                          // 0x0698(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)

public:
	void ExecuteUbergraph_GA_Mingzhongzhigui_Vision(int32 EntryPoint);
	void K2_ActivateAbility();
	void OnCompleted_5D118C384AE61F1C80292E8140EF0AD9();
	void OnBlendOut_5D118C384AE61F1C80292E8140EF0AD9();
	void OnInterrupted_5D118C384AE61F1C80292E8140EF0AD9();
	void OnCancelled_5D118C384AE61F1C80292E8140EF0AD9();
	void OnTick_5D118C384AE61F1C80292E8140EF0AD9();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GA_Mingzhongzhigui_Vision_C">();
	}
	static class UGA_Mingzhongzhigui_Vision_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGA_Mingzhongzhigui_Vision_C>();
	}
};
static_assert(alignof(UGA_Mingzhongzhigui_Vision_C) == 0x000008, "Wrong alignment on UGA_Mingzhongzhigui_Vision_C");
static_assert(sizeof(UGA_Mingzhongzhigui_Vision_C) == 0x0006A8, "Wrong size on UGA_Mingzhongzhigui_Vision_C");
static_assert(offsetof(UGA_Mingzhongzhigui_Vision_C, UberGraphFrame_GA_Mingzhongzhigui_Vision_C) == 0x000558, "Member 'UGA_Mingzhongzhigui_Vision_C::UberGraphFrame_GA_Mingzhongzhigui_Vision_C' has a wrong offset!");
static_assert(offsetof(UGA_Mingzhongzhigui_Vision_C, _r) == 0x000560, "Member 'UGA_Mingzhongzhigui_Vision_C::_r' has a wrong offset!");
static_assert(offsetof(UGA_Mingzhongzhigui_Vision_C, CreateBulletDelay) == 0x000568, "Member 'UGA_Mingzhongzhigui_Vision_C::CreateBulletDelay' has a wrong offset!");
static_assert(offsetof(UGA_Mingzhongzhigui_Vision_C, _e_____P9) == 0x000570, "Member 'UGA_Mingzhongzhigui_Vision_C::_e_____P9' has a wrong offset!");
static_assert(offsetof(UGA_Mingzhongzhigui_Vision_C, _aLevel) == 0x000578, "Member 'UGA_Mingzhongzhigui_Vision_C::_aLevel' has a wrong offset!");
static_assert(offsetof(UGA_Mingzhongzhigui_Vision_C, _aID) == 0x00057C, "Member 'UGA_Mingzhongzhigui_Vision_C::_aID' has a wrong offset!");
static_assert(offsetof(UGA_Mingzhongzhigui_Vision_C, Camera_Modify_Settings) == 0x000580, "Member 'UGA_Mingzhongzhigui_Vision_C::Camera_Modify_Settings' has a wrong offset!");
static_assert(offsetof(UGA_Mingzhongzhigui_Vision_C, Camera_Modifier_Contions) == 0x000698, "Member 'UGA_Mingzhongzhigui_Vision_C::Camera_Modifier_Contions' has a wrong offset!");

}
