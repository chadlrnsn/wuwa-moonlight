#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TsTaskAiUseItem

#include "Basic.hpp"

#include "TsTaskAiUseItem_classes.hpp"
#include "TsTaskAiUseItem_parameters.hpp"


namespace SDK
{

// Function TsTaskAiUseItem.TsTaskAiUseItem_C.ExecuteUbergraph_TsTaskAiUseItem
// (Final, Native, UbergraphFunction, Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UTsTaskAiUseItem_C::ExecuteUbergraph_TsTaskAiUseItem(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsTaskAiUseItem_C", "ExecuteUbergraph_TsTaskAiUseItem");

	Params::TsTaskAiUseItem_C_ExecuteUbergraph_TsTaskAiUseItem Parms{};

	Parms.EntryPoint = EntryPoint;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function TsTaskAiUseItem.TsTaskAiUseItem_C.ReceiveExecuteAI
// (Native, Event, Public, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AAIController*                    OwnerController                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class APawn*                            ControlledPawn                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UTsTaskAiUseItem_C::ReceiveExecuteAI(class AAIController* OwnerController, class APawn* ControlledPawn)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsTaskAiUseItem_C", "ReceiveExecuteAI");

	Params::TsTaskAiUseItem_C_ReceiveExecuteAI Parms{};

	Parms.OwnerController = OwnerController;
	Parms.ControlledPawn = ControlledPawn;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function TsTaskAiUseItem.TsTaskAiUseItem_C.InitTsVariables
// (Native, Public, BlueprintCallable, BlueprintEvent)

void UTsTaskAiUseItem_C::InitTsVariables()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsTaskAiUseItem_C", "InitTsVariables");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}

}
