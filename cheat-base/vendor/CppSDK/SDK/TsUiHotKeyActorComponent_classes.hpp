#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TsUiHotKeyActorComponent

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "LGUI_classes.hpp"


namespace SDK
{

// TypeScriptGeneratedClass TsUiHotKeyActorComponent.TsUiHotKeyActorComponent_C
// 0x0020 (0x0120 - 0x0100)
class UTsUiHotKeyActorComponent_C final : public ULGUIBehaviour
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0100(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class FString                                 Mode;                                              // 0x0108(0x0010)(Edit, BlueprintVisible, ZeroConstructor, UObjectWrapper, HasGetValueTypeHash)
	int32                                         Index_0;                                           // 0x0118(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_TsUiHotKeyActorComponent(int32 EntryPoint);
	void OnDisableBP();
	void OnEnableBP();
	void AwakeBP();
	void StartBP();
	void OnDestroyBP();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"TsUiHotKeyActorComponent_C">();
	}
	static class UTsUiHotKeyActorComponent_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTsUiHotKeyActorComponent_C>();
	}
};
static_assert(alignof(UTsUiHotKeyActorComponent_C) == 0x000008, "Wrong alignment on UTsUiHotKeyActorComponent_C");
static_assert(sizeof(UTsUiHotKeyActorComponent_C) == 0x000120, "Wrong size on UTsUiHotKeyActorComponent_C");
static_assert(offsetof(UTsUiHotKeyActorComponent_C, UberGraphFrame) == 0x000100, "Member 'UTsUiHotKeyActorComponent_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UTsUiHotKeyActorComponent_C, Mode) == 0x000108, "Member 'UTsUiHotKeyActorComponent_C::Mode' has a wrong offset!");
static_assert(offsetof(UTsUiHotKeyActorComponent_C, Index_0) == 0x000118, "Member 'UTsUiHotKeyActorComponent_C::Index_0' has a wrong offset!");

}
