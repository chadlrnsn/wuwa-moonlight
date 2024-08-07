#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_Summon_Bailian_Burst_Rogue

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "GameplayTags_structs.hpp"
#include "GameplayAbilities_structs.hpp"


namespace SDK::Params
{

// Function GA_Summon_Bailian_Burst_Rogue.GA_Summon_Bailian_Burst_Rogue_C.ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue
// 0x0488 (0x0488 - 0x0000)
struct GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate;              // 0x0004(0x0014)(ZeroConstructor, NoDestructor)
	class ATsBaseCharacter_C*                     CallFunc__________;                                // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AActor*                                 CallFunc____________;                              // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TScriptInterface<class IGameplayTagAssetInterface> CallFunc_GetOwnedGameplayTags_self_CastInput;      // 0x0028(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor)
	struct FGameplayTagContainer                  CallFunc_GetOwnedGameplayTags_TagContainer;        // 0x0038(0x0020)()
	float                                         CallFunc__________SpeedRatio;                      // 0x0058(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2B4E[0x4];                                     // 0x005C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class ATsBaseCharacter_C*                     CallFunc___________1;                              // 0x0060(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc______________;                            // 0x0068(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2B4F[0x7];                                     // 0x0069(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class ATsBaseCharacter_C*                     CallFunc___________2;                              // 0x0070(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ATsBaseCharacter_C*                     CallFunc___________3;                              // 0x0078(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_______________1;                          // 0x0080(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2B50[0x7];                                     // 0x0081(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AActor*                                 CallFunc_GetOwningActorFromActorInfo_ReturnValue;  // 0x0088(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ATsBaseCharacter_C*                     K2Node_DynamicCast_AsTs_Base_Character;            // 0x0090(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0098(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2B51[0x3];                                     // 0x0099(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_Conv_IntToFloat_ReturnValue;              // 0x009C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           CallFunc___________4;                              // 0x00A0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAbilityTask_PlayMontageAndWait*        CallFunc_CreatePlayMontageAndWaitProxy_ReturnValue; // 0x00A8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FString                                 CallFunc_GetDisplayName_ReturnValue;               // 0x00B0(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x00C0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2B52[0x7];                                     // 0x00C1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UClass*                                 CallFunc_GetObjectClass_ReturnValue;               // 0x00C8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_EqualEqual_ClassClass_ReturnValue;        // 0x00D0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2B53[0x3];                                     // 0x00D1(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate_1;            // 0x00D4(0x0014)(ZeroConstructor, NoDestructor)
	class FString                                 CallFunc_____GA______________;                     // 0x00E8(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class FString                                 CallFunc_Conv_NameToString_ReturnValue;            // 0x00F8(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate_2;            // 0x0108(0x0014)(ZeroConstructor, NoDestructor)
	uint8                                         Pad_2B54[0x4];                                     // 0x011C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UAnimMontage*                           CallFunc___________5;                              // 0x0120(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue_1;                    // 0x0128(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2B55[0x3];                                     // 0x0129(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate_3;            // 0x012C(0x0014)(ZeroConstructor, NoDestructor)
	bool                                          K2Node_Event_bWasCancelled;                        // 0x0140(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2B56[0x7];                                     // 0x0141(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class ATsBaseCharacter_C*                     CallFunc___________6;                              // 0x0148(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ATsBaseCharacter_C*                     CallFunc___________7;                              // 0x0150(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ATsBaseCharacter_C*                     CallFunc___________8;                              // 0x0158(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FString                                 CallFunc_GetSocketName_ReturnValue;                // 0x0160(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	TScriptInterface<class IGameplayTagAssetInterface> CallFunc_GetOwnedGameplayTags_self_CastInput_1;    // 0x0170(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor)
	struct FGameplayTagContainer                  CallFunc_GetOwnedGameplayTags_TagContainer_1;      // 0x0180(0x0020)()
	class AActor*                                 CallFunc_____________1;                            // 0x01A0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ATsBaseCharacter_C*                     CallFunc___________9;                              // 0x01A8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ATsBaseCharacter_C*                     CallFunc___________10;                             // 0x01B0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc___Current_______;                         // 0x01B8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2B57[0x4];                                     // 0x01BC(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 CallFunc_Conv_IntToString_ReturnValue;             // 0x01C0(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	bool                                          CallFunc_GreaterEqual_FloatFloat_ReturnValue;      // 0x01D0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2B58[0x7];                                     // 0x01D1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class ATsBaseCharacter_C*                     CallFunc___________11;                             // 0x01D8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_____ID___ID;                              // 0x01E0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2B59[0x4];                                     // 0x01E4(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 CallFunc_Conv_IntToString_ReturnValue_1;           // 0x01E8(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class ATsBaseCharacter_C*                     CallFunc___________12;                             // 0x01F8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ATsBaseCharacter_C*                     CallFunc___________13;                             // 0x0200(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_ContainsTag_ReturnValue;                  // 0x0208(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2B5A[0x7];                                     // 0x0209(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class ATsBaseCharacter_C*                     CallFunc___________14;                             // 0x0210(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FGameplayEventData                     K2Node_MakeStruct_GameplayEventData;               // 0x0218(0x00B8)()
	class FString                                 CallFunc_Conv_IntToString_ReturnValue_2;           // 0x02D0(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class ATsBaseCharacter_C*                     CallFunc___________15;                             // 0x02E0(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate_4;            // 0x02E8(0x0014)(ZeroConstructor, NoDestructor)
	uint8                                         Pad_2B5B[0x4];                                     // 0x02FC(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class ATsBaseCharacter_C*                     CallFunc___________16;                             // 0x0300(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_____ID___ID_1;                            // 0x0308(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2B5C[0x4];                                     // 0x030C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 CallFunc_Conv_IntToString_ReturnValue_3;           // 0x0310(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class ATsBaseCharacter_C*                     K2Node_DynamicCast_AsTs_Base_Character_1;          // 0x0320(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess_1;                     // 0x0328(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2B5D[0x7];                                     // 0x0329(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TScriptInterface<class IGameplayTagAssetInterface> CallFunc_GetOwnedGameplayTags_self_CastInput_2;    // 0x0330(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor)
	struct FGameplayTagContainer                  CallFunc_GetOwnedGameplayTags_TagContainer_2;      // 0x0340(0x0020)()
	class ATsBaseCharacter_C*                     CallFunc___________17;                             // 0x0360(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FString                                 CallFunc_GetDisplayName_ReturnValue_1;             // 0x0368(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class ATsBaseCharacter_C*                     CallFunc___________18;                             // 0x0378(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ATsBaseCharacter_C*                     CallFunc___________19;                             // 0x0380(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FGameplayEventData                     K2Node_MakeStruct_GameplayEventData_1;             // 0x0388(0x00B8)()
	class FString                                 CallFunc_GetSocketName_ReturnValue_1;              // 0x0440(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class ATsBaseCharacter_C*                     CallFunc___________20;                             // 0x0450(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_K2_GetActorLocation_ReturnValue;          // 0x0458(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_____EntityId__;                           // 0x0464(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash)
	struct FRotator                               CallFunc_K2_GetActorRotation_ReturnValue;          // 0x0468(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2B5E[0x4];                                     // 0x0474(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class ATsBaseCharacter_C*                     CallFunc_____ID_______;                            // 0x0478(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_____ID___________;                        // 0x0480(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_____________2;                            // 0x0481(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper)
};
static_assert(alignof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue) == 0x000008, "Wrong alignment on GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue");
static_assert(sizeof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue) == 0x000488, "Wrong size on GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, EntryPoint) == 0x000000, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::EntryPoint' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, K2Node_CreateDelegate_OutputDelegate) == 0x000004, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc__________) == 0x000018, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc__________' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc____________) == 0x000020, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc____________' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_GetOwnedGameplayTags_self_CastInput) == 0x000028, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_GetOwnedGameplayTags_self_CastInput' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_GetOwnedGameplayTags_TagContainer) == 0x000038, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_GetOwnedGameplayTags_TagContainer' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc__________SpeedRatio) == 0x000058, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc__________SpeedRatio' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________1) == 0x000060, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________1' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc______________) == 0x000068, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc______________' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________2) == 0x000070, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________2' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________3) == 0x000078, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________3' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_______________1) == 0x000080, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_______________1' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_GetOwningActorFromActorInfo_ReturnValue) == 0x000088, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_GetOwningActorFromActorInfo_ReturnValue' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, K2Node_DynamicCast_AsTs_Base_Character) == 0x000090, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::K2Node_DynamicCast_AsTs_Base_Character' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, K2Node_DynamicCast_bSuccess) == 0x000098, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_Conv_IntToFloat_ReturnValue) == 0x00009C, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_Conv_IntToFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________4) == 0x0000A0, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________4' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_CreatePlayMontageAndWaitProxy_ReturnValue) == 0x0000A8, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_CreatePlayMontageAndWaitProxy_ReturnValue' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_GetDisplayName_ReturnValue) == 0x0000B0, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_GetDisplayName_ReturnValue' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_IsValid_ReturnValue) == 0x0000C0, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_IsValid_ReturnValue' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_GetObjectClass_ReturnValue) == 0x0000C8, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_GetObjectClass_ReturnValue' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_EqualEqual_ClassClass_ReturnValue) == 0x0000D0, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_EqualEqual_ClassClass_ReturnValue' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, K2Node_CreateDelegate_OutputDelegate_1) == 0x0000D4, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::K2Node_CreateDelegate_OutputDelegate_1' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_____GA______________) == 0x0000E8, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_____GA______________' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_Conv_NameToString_ReturnValue) == 0x0000F8, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_Conv_NameToString_ReturnValue' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, K2Node_CreateDelegate_OutputDelegate_2) == 0x000108, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::K2Node_CreateDelegate_OutputDelegate_2' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________5) == 0x000120, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________5' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_IsValid_ReturnValue_1) == 0x000128, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_IsValid_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, K2Node_CreateDelegate_OutputDelegate_3) == 0x00012C, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::K2Node_CreateDelegate_OutputDelegate_3' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, K2Node_Event_bWasCancelled) == 0x000140, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::K2Node_Event_bWasCancelled' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________6) == 0x000148, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________6' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________7) == 0x000150, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________7' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________8) == 0x000158, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________8' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_GetSocketName_ReturnValue) == 0x000160, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_GetSocketName_ReturnValue' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_GetOwnedGameplayTags_self_CastInput_1) == 0x000170, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_GetOwnedGameplayTags_self_CastInput_1' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_GetOwnedGameplayTags_TagContainer_1) == 0x000180, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_GetOwnedGameplayTags_TagContainer_1' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_____________1) == 0x0001A0, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_____________1' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________9) == 0x0001A8, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________9' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________10) == 0x0001B0, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________10' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___Current_______) == 0x0001B8, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___Current_______' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_Conv_IntToString_ReturnValue) == 0x0001C0, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_Conv_IntToString_ReturnValue' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_GreaterEqual_FloatFloat_ReturnValue) == 0x0001D0, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_GreaterEqual_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________11) == 0x0001D8, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________11' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_____ID___ID) == 0x0001E0, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_____ID___ID' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_Conv_IntToString_ReturnValue_1) == 0x0001E8, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_Conv_IntToString_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________12) == 0x0001F8, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________12' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________13) == 0x000200, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________13' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_ContainsTag_ReturnValue) == 0x000208, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_ContainsTag_ReturnValue' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________14) == 0x000210, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________14' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, K2Node_MakeStruct_GameplayEventData) == 0x000218, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::K2Node_MakeStruct_GameplayEventData' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_Conv_IntToString_ReturnValue_2) == 0x0002D0, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_Conv_IntToString_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________15) == 0x0002E0, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________15' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, K2Node_CreateDelegate_OutputDelegate_4) == 0x0002E8, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::K2Node_CreateDelegate_OutputDelegate_4' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________16) == 0x000300, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________16' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_____ID___ID_1) == 0x000308, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_____ID___ID_1' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_Conv_IntToString_ReturnValue_3) == 0x000310, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_Conv_IntToString_ReturnValue_3' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, K2Node_DynamicCast_AsTs_Base_Character_1) == 0x000320, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::K2Node_DynamicCast_AsTs_Base_Character_1' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, K2Node_DynamicCast_bSuccess_1) == 0x000328, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::K2Node_DynamicCast_bSuccess_1' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_GetOwnedGameplayTags_self_CastInput_2) == 0x000330, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_GetOwnedGameplayTags_self_CastInput_2' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_GetOwnedGameplayTags_TagContainer_2) == 0x000340, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_GetOwnedGameplayTags_TagContainer_2' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________17) == 0x000360, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________17' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_GetDisplayName_ReturnValue_1) == 0x000368, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_GetDisplayName_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________18) == 0x000378, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________18' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________19) == 0x000380, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________19' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, K2Node_MakeStruct_GameplayEventData_1) == 0x000388, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::K2Node_MakeStruct_GameplayEventData_1' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_GetSocketName_ReturnValue_1) == 0x000440, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_GetSocketName_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc___________20) == 0x000450, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc___________20' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_K2_GetActorLocation_ReturnValue) == 0x000458, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_K2_GetActorLocation_ReturnValue' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_____EntityId__) == 0x000464, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_____EntityId__' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_K2_GetActorRotation_ReturnValue) == 0x000468, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_K2_GetActorRotation_ReturnValue' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_____ID_______) == 0x000478, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_____ID_______' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_____ID___________) == 0x000480, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_____ID___________' has a wrong offset!");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue, CallFunc_____________2) == 0x000481, "Member 'GA_Summon_Bailian_Burst_Rogue_C_ExecuteUbergraph_GA_Summon_Bailian_Burst_Rogue::CallFunc_____________2' has a wrong offset!");

// Function GA_Summon_Bailian_Burst_Rogue.GA_Summon_Bailian_Burst_Rogue_C.K2_OnEndAbility
// 0x0001 (0x0001 - 0x0000)
struct GA_Summon_Bailian_Burst_Rogue_C_K2_OnEndAbility final
{
public:
	bool                                          bWasCancelled;                                     // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(GA_Summon_Bailian_Burst_Rogue_C_K2_OnEndAbility) == 0x000001, "Wrong alignment on GA_Summon_Bailian_Burst_Rogue_C_K2_OnEndAbility");
static_assert(sizeof(GA_Summon_Bailian_Burst_Rogue_C_K2_OnEndAbility) == 0x000001, "Wrong size on GA_Summon_Bailian_Burst_Rogue_C_K2_OnEndAbility");
static_assert(offsetof(GA_Summon_Bailian_Burst_Rogue_C_K2_OnEndAbility, bWasCancelled) == 0x000000, "Member 'GA_Summon_Bailian_Burst_Rogue_C_K2_OnEndAbility::bWasCancelled' has a wrong offset!");

}

