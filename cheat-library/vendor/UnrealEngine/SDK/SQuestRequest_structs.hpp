#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SQuestRequest

#include "Basic.hpp"

#include "EQuestHandleType_structs.hpp"


namespace SDK
{

// UserDefinedStruct SQuestRequest.SQuestRequest
// 0x0028 (0x0028 - 0x0000)
struct FSQuestRequest final
{
public:
	class FName                                   QuestID_7_D1CE323A4B68C8775EFE688D32245A4D;        // 0x0000(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   QuestStepID_8_6F9258AF4F872CF33FF3FC9A8671E3ED;    // 0x000C(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UDataTable*                             QuestData_9_A22C6AC242EF8804245B008DF79CF68C;      // 0x0018(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EQuestHandleType                              QuesetHandleType_12_271AFB814CD10276702F1E8E793D477E; // 0x0020(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2BA0[0x3];                                     // 0x0021(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         QuestDelay_15_D63AEC39436DE8E0F6F5859D67664A84;    // 0x0024(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(FSQuestRequest) == 0x000008, "Wrong alignment on FSQuestRequest");
static_assert(sizeof(FSQuestRequest) == 0x000028, "Wrong size on FSQuestRequest");
static_assert(offsetof(FSQuestRequest, QuestID_7_D1CE323A4B68C8775EFE688D32245A4D) == 0x000000, "Member 'FSQuestRequest::QuestID_7_D1CE323A4B68C8775EFE688D32245A4D' has a wrong offset!");
static_assert(offsetof(FSQuestRequest, QuestStepID_8_6F9258AF4F872CF33FF3FC9A8671E3ED) == 0x00000C, "Member 'FSQuestRequest::QuestStepID_8_6F9258AF4F872CF33FF3FC9A8671E3ED' has a wrong offset!");
static_assert(offsetof(FSQuestRequest, QuestData_9_A22C6AC242EF8804245B008DF79CF68C) == 0x000018, "Member 'FSQuestRequest::QuestData_9_A22C6AC242EF8804245B008DF79CF68C' has a wrong offset!");
static_assert(offsetof(FSQuestRequest, QuesetHandleType_12_271AFB814CD10276702F1E8E793D477E) == 0x000020, "Member 'FSQuestRequest::QuesetHandleType_12_271AFB814CD10276702F1E8E793D477E' has a wrong offset!");
static_assert(offsetof(FSQuestRequest, QuestDelay_15_D63AEC39436DE8E0F6F5859D67664A84) == 0x000024, "Member 'FSQuestRequest::QuestDelay_15_D63AEC39436DE8E0F6F5859D67664A84' has a wrong offset!");

}
