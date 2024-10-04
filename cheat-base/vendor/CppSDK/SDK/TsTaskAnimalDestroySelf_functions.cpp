#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TsTaskAnimalDestroySelf

#include "Basic.hpp"

#include "TsTaskAnimalDestroySelf_classes.hpp"
#include "TsTaskAnimalDestroySelf_parameters.hpp"


namespace SDK
{

// Function TsTaskAnimalDestroySelf.TsTaskAnimalDestroySelf_C.ExecuteUbergraph_TsTaskAnimalDestroySelf
// (Final, Native, UbergraphFunction, Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UTsTaskAnimalDestroySelf_C::ExecuteUbergraph_TsTaskAnimalDestroySelf(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsTaskAnimalDestroySelf_C", "ExecuteUbergraph_TsTaskAnimalDestroySelf");

	Params::TsTaskAnimalDestroySelf_C_ExecuteUbergraph_TsTaskAnimalDestroySelf Parms{};

	Parms.EntryPoint = EntryPoint;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function TsTaskAnimalDestroySelf.TsTaskAnimalDestroySelf_C.ReceiveExecuteAI
// (Native, Event, Public, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AAIController*                    OwnerController                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class APawn*                            ControlledPawn                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UTsTaskAnimalDestroySelf_C::ReceiveExecuteAI(class AAIController* OwnerController, class APawn* ControlledPawn)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsTaskAnimalDestroySelf_C", "ReceiveExecuteAI");

	Params::TsTaskAnimalDestroySelf_C_ReceiveExecuteAI Parms{};

	Parms.OwnerController = OwnerController;
	Parms.ControlledPawn = ControlledPawn;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}

}
