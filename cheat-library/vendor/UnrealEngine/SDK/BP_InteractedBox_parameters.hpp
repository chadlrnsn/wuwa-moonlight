#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_InteractedBox

#include "Basic.hpp"


namespace SDK::Params
{

// Function BP_InteractedBox.BP_InteractedBox_C.ExecuteUbergraph_BP_InteractedBox
// 0x0008 (0x0008 - 0x0000)
struct BP_InteractedBox_C_ExecuteUbergraph_BP_InteractedBox final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_SetRootComponent_ReturnValue;             // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(BP_InteractedBox_C_ExecuteUbergraph_BP_InteractedBox) == 0x000004, "Wrong alignment on BP_InteractedBox_C_ExecuteUbergraph_BP_InteractedBox");
static_assert(sizeof(BP_InteractedBox_C_ExecuteUbergraph_BP_InteractedBox) == 0x000008, "Wrong size on BP_InteractedBox_C_ExecuteUbergraph_BP_InteractedBox");
static_assert(offsetof(BP_InteractedBox_C_ExecuteUbergraph_BP_InteractedBox, EntryPoint) == 0x000000, "Member 'BP_InteractedBox_C_ExecuteUbergraph_BP_InteractedBox::EntryPoint' has a wrong offset!");
static_assert(offsetof(BP_InteractedBox_C_ExecuteUbergraph_BP_InteractedBox, CallFunc_SetRootComponent_ReturnValue) == 0x000004, "Member 'BP_InteractedBox_C_ExecuteUbergraph_BP_InteractedBox::CallFunc_SetRootComponent_ReturnValue' has a wrong offset!");

// Function BP_InteractedBox.BP_InteractedBox_C.IsPhysicInteracted
// 0x0001 (0x0001 - 0x0000)
struct BP_InteractedBox_C_IsPhysicInteracted final
{
public:
	bool                                          OutInteracted;                                     // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(BP_InteractedBox_C_IsPhysicInteracted) == 0x000001, "Wrong alignment on BP_InteractedBox_C_IsPhysicInteracted");
static_assert(sizeof(BP_InteractedBox_C_IsPhysicInteracted) == 0x000001, "Wrong size on BP_InteractedBox_C_IsPhysicInteracted");
static_assert(offsetof(BP_InteractedBox_C_IsPhysicInteracted, OutInteracted) == 0x000000, "Member 'BP_InteractedBox_C_IsPhysicInteracted::OutInteracted' has a wrong offset!");

}
