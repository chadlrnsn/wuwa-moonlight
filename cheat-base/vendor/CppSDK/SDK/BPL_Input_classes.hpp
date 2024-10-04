#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BPL_Input

#include "Basic.hpp"

#include "Engine_classes.hpp"
#include "EInputAction_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass BPL_Input.BPL_Input_C
// 0x0000 (0x0030 - 0x0030)
class UBPL_Input_C final : public UBlueprintFunctionLibrary
{
public:
	static bool IsKeyDown(EInputAction NewParam, class UObject* __WorldContext);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BPL_Input_C">();
	}
	static class UBPL_Input_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBPL_Input_C>();
	}
};
static_assert(alignof(UBPL_Input_C) == 0x000008, "Wrong alignment on UBPL_Input_C");
static_assert(sizeof(UBPL_Input_C) == 0x000030, "Wrong size on UBPL_Input_C");

}
