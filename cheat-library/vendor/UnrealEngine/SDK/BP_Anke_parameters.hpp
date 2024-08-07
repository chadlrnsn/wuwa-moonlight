#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_Anke

#include "Basic.hpp"


namespace SDK::Params
{

// Function BP_Anke.BP_Anke_C.ExecuteUbergraph_BP_Anke
// 0x0004 (0x0004 - 0x0000)
struct BP_Anke_C_ExecuteUbergraph_BP_Anke final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(BP_Anke_C_ExecuteUbergraph_BP_Anke) == 0x000004, "Wrong alignment on BP_Anke_C_ExecuteUbergraph_BP_Anke");
static_assert(sizeof(BP_Anke_C_ExecuteUbergraph_BP_Anke) == 0x000004, "Wrong size on BP_Anke_C_ExecuteUbergraph_BP_Anke");
static_assert(offsetof(BP_Anke_C_ExecuteUbergraph_BP_Anke, EntryPoint) == 0x000000, "Member 'BP_Anke_C_ExecuteUbergraph_BP_Anke::EntryPoint' has a wrong offset!");

// Function BP_Anke.BP_Anke_C.FightCommand
// 0x0028 (0x0028 - 0x0000)
struct BP_Anke_C_FightCommand final
{
public:
	bool                                          IsInAir;                                           // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3637[0x7];                                     // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AActor*                                 CallFunc_GetSkillTarget_ReturnValue;               // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AActor*                                 CallFunc_GetSkillTarget_ReturnValue_1;             // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AActor*                                 CallFunc_GetSkillTarget_ReturnValue_2;             // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_BeginSkill_ReturnValue;                   // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BeginSkill_ReturnValue_1;                 // 0x0021(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BeginSkill_ReturnValue_2;                 // 0x0022(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_ContainsTag_ReturnValue;                  // 0x0023(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_ContainsTag_ReturnValue_1;                // 0x0024(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(BP_Anke_C_FightCommand) == 0x000008, "Wrong alignment on BP_Anke_C_FightCommand");
static_assert(sizeof(BP_Anke_C_FightCommand) == 0x000028, "Wrong size on BP_Anke_C_FightCommand");
static_assert(offsetof(BP_Anke_C_FightCommand, IsInAir) == 0x000000, "Member 'BP_Anke_C_FightCommand::IsInAir' has a wrong offset!");
static_assert(offsetof(BP_Anke_C_FightCommand, CallFunc_GetSkillTarget_ReturnValue) == 0x000008, "Member 'BP_Anke_C_FightCommand::CallFunc_GetSkillTarget_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_Anke_C_FightCommand, CallFunc_GetSkillTarget_ReturnValue_1) == 0x000010, "Member 'BP_Anke_C_FightCommand::CallFunc_GetSkillTarget_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(BP_Anke_C_FightCommand, CallFunc_GetSkillTarget_ReturnValue_2) == 0x000018, "Member 'BP_Anke_C_FightCommand::CallFunc_GetSkillTarget_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(BP_Anke_C_FightCommand, CallFunc_BeginSkill_ReturnValue) == 0x000020, "Member 'BP_Anke_C_FightCommand::CallFunc_BeginSkill_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_Anke_C_FightCommand, CallFunc_BeginSkill_ReturnValue_1) == 0x000021, "Member 'BP_Anke_C_FightCommand::CallFunc_BeginSkill_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(BP_Anke_C_FightCommand, CallFunc_BeginSkill_ReturnValue_2) == 0x000022, "Member 'BP_Anke_C_FightCommand::CallFunc_BeginSkill_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(BP_Anke_C_FightCommand, CallFunc_ContainsTag_ReturnValue) == 0x000023, "Member 'BP_Anke_C_FightCommand::CallFunc_ContainsTag_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_Anke_C_FightCommand, CallFunc_ContainsTag_ReturnValue_1) == 0x000024, "Member 'BP_Anke_C_FightCommand::CallFunc_ContainsTag_ReturnValue_1' has a wrong offset!");

}

