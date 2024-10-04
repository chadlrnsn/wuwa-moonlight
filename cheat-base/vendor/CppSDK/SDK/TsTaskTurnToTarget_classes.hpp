#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TsTaskTurnToTarget

#include "Basic.hpp"

#include "TsTaskAbortImmediatelyBase_classes.hpp"
#include "Engine_structs.hpp"


namespace SDK
{

// TypeScriptGeneratedClass TsTaskTurnToTarget.TsTaskTurnToTarget_C
// 0x0020 (0x00D8 - 0x00B8)
class UTsTaskTurnToTarget_C final : public UTsTaskAbortImmediatelyBase_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_TsTaskTurnToTarget_C;               // 0x00B8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class FString                                 BlackboardKeyActor;                                // 0x00C0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, HasGetValueTypeHash)
	float                                         TurnSpeed;                                         // 0x00D0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_TsTaskTurnToTarget(int32 EntryPoint);
	void ReceiveTickAI(class AAIController* OwnerController, class APawn* ControlledPawn, float DeltaSeconds);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"TsTaskTurnToTarget_C">();
	}
	static class UTsTaskTurnToTarget_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTsTaskTurnToTarget_C>();
	}
};
static_assert(alignof(UTsTaskTurnToTarget_C) == 0x000008, "Wrong alignment on UTsTaskTurnToTarget_C");
static_assert(sizeof(UTsTaskTurnToTarget_C) == 0x0000D8, "Wrong size on UTsTaskTurnToTarget_C");
static_assert(offsetof(UTsTaskTurnToTarget_C, UberGraphFrame_TsTaskTurnToTarget_C) == 0x0000B8, "Member 'UTsTaskTurnToTarget_C::UberGraphFrame_TsTaskTurnToTarget_C' has a wrong offset!");
static_assert(offsetof(UTsTaskTurnToTarget_C, BlackboardKeyActor) == 0x0000C0, "Member 'UTsTaskTurnToTarget_C::BlackboardKeyActor' has a wrong offset!");
static_assert(offsetof(UTsTaskTurnToTarget_C, TurnSpeed) == 0x0000D0, "Member 'UTsTaskTurnToTarget_C::TurnSpeed' has a wrong offset!");

}
