#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AIC_ME1SiXiaoMd00601

#include "Basic.hpp"


namespace SDK::Params
{

// Function AIC_ME1SiXiaoMd00601.AIC_ME1SiXiaoMd00601_C.ExecuteUbergraph_AIC_ME1SiXiaoMd00601
// 0x0020 (0x0020 - 0x0000)
struct AIC_ME1SiXiaoMd00601_C_ExecuteUbergraph_AIC_ME1SiXiaoMd00601 final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class APawn*                                  CallFunc_K2_GetPawn_ReturnValue;                   // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ATsBaseCharacter_C*                     K2Node_DynamicCast_AsTs_Base_Character;            // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(AIC_ME1SiXiaoMd00601_C_ExecuteUbergraph_AIC_ME1SiXiaoMd00601) == 0x000008, "Wrong alignment on AIC_ME1SiXiaoMd00601_C_ExecuteUbergraph_AIC_ME1SiXiaoMd00601");
static_assert(sizeof(AIC_ME1SiXiaoMd00601_C_ExecuteUbergraph_AIC_ME1SiXiaoMd00601) == 0x000020, "Wrong size on AIC_ME1SiXiaoMd00601_C_ExecuteUbergraph_AIC_ME1SiXiaoMd00601");
static_assert(offsetof(AIC_ME1SiXiaoMd00601_C_ExecuteUbergraph_AIC_ME1SiXiaoMd00601, EntryPoint) == 0x000000, "Member 'AIC_ME1SiXiaoMd00601_C_ExecuteUbergraph_AIC_ME1SiXiaoMd00601::EntryPoint' has a wrong offset!");
static_assert(offsetof(AIC_ME1SiXiaoMd00601_C_ExecuteUbergraph_AIC_ME1SiXiaoMd00601, CallFunc_K2_GetPawn_ReturnValue) == 0x000008, "Member 'AIC_ME1SiXiaoMd00601_C_ExecuteUbergraph_AIC_ME1SiXiaoMd00601::CallFunc_K2_GetPawn_ReturnValue' has a wrong offset!");
static_assert(offsetof(AIC_ME1SiXiaoMd00601_C_ExecuteUbergraph_AIC_ME1SiXiaoMd00601, K2Node_DynamicCast_AsTs_Base_Character) == 0x000010, "Member 'AIC_ME1SiXiaoMd00601_C_ExecuteUbergraph_AIC_ME1SiXiaoMd00601::K2Node_DynamicCast_AsTs_Base_Character' has a wrong offset!");
static_assert(offsetof(AIC_ME1SiXiaoMd00601_C_ExecuteUbergraph_AIC_ME1SiXiaoMd00601, K2Node_DynamicCast_bSuccess) == 0x000018, "Member 'AIC_ME1SiXiaoMd00601_C_ExecuteUbergraph_AIC_ME1SiXiaoMd00601::K2Node_DynamicCast_bSuccess' has a wrong offset!");

}
