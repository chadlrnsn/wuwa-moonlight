#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_MO1QunJing2Md00001_Attack02

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "GA_Monster_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass GA_MO1QunJing2Md00001_Attack02.GA_MO1QunJing2Md00001_Attack02_C
// 0x0008 (0x0570 - 0x0568)
class UGA_MO1QunJing2Md00001_Attack02_C final : public UGA_Monster_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_GA_MO1QunJing2Md00001_Attack02_C;   // 0x0568(0x0008)(ZeroConstructor, Transient, DuplicateTransient)

public:
	void ExecuteUbergraph_GA_MO1QunJing2Md00001_Attack02(int32 EntryPoint);
	void K2_ActivateAbility();
	void OnCompleted_5D118C384AE61F1C80292E81351241D8();
	void OnBlendOut_5D118C384AE61F1C80292E81351241D8();
	void OnInterrupted_5D118C384AE61F1C80292E81351241D8();
	void OnCancelled_5D118C384AE61F1C80292E81351241D8();
	void OnTick_5D118C384AE61F1C80292E81351241D8();
	void OnFinish_26B3E5FD4B0152093F9EFD9FE416E1FE();
	void OnCompleted_5D118C384AE61F1C80292E819A89B47D();
	void OnBlendOut_5D118C384AE61F1C80292E819A89B47D();
	void OnInterrupted_5D118C384AE61F1C80292E819A89B47D();
	void OnCancelled_5D118C384AE61F1C80292E819A89B47D();
	void OnTick_5D118C384AE61F1C80292E819A89B47D();
	void Added_21071CB943CD992BF8EFD6A3E9BB52AA(const struct FGameplayTag& Tag);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"GA_MO1QunJing2Md00001_Attack02_C">();
	}
	static class UGA_MO1QunJing2Md00001_Attack02_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UGA_MO1QunJing2Md00001_Attack02_C>();
	}
};
static_assert(alignof(UGA_MO1QunJing2Md00001_Attack02_C) == 0x000008, "Wrong alignment on UGA_MO1QunJing2Md00001_Attack02_C");
static_assert(sizeof(UGA_MO1QunJing2Md00001_Attack02_C) == 0x000570, "Wrong size on UGA_MO1QunJing2Md00001_Attack02_C");
static_assert(offsetof(UGA_MO1QunJing2Md00001_Attack02_C, UberGraphFrame_GA_MO1QunJing2Md00001_Attack02_C) == 0x000568, "Member 'UGA_MO1QunJing2Md00001_Attack02_C::UberGraphFrame_GA_MO1QunJing2Md00001_Attack02_C' has a wrong offset!");

}
