#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_InteractedBox

#include "Basic.hpp"

#include "BP_InteractedBox_classes.hpp"
#include "BP_InteractedBox_parameters.hpp"


namespace SDK
{

// Function BP_InteractedBox.BP_InteractedBox_C.ExecuteUbergraph_BP_InteractedBox
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_InteractedBox_C::ExecuteUbergraph_BP_InteractedBox(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_InteractedBox_C", "ExecuteUbergraph_BP_InteractedBox");

	Params::BP_InteractedBox_C_ExecuteUbergraph_BP_InteractedBox Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_InteractedBox.BP_InteractedBox_C.ReceiveBeginPlay
// (Event, Public, Protected, BlueprintCallable, BlueprintEvent)

void ABP_InteractedBox_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_InteractedBox_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_InteractedBox.BP_InteractedBox_C.IsPhysicInteracted
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    OutInteracted                                          (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ABP_InteractedBox_C::IsPhysicInteracted(bool* OutInteracted)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_InteractedBox_C", "IsPhysicInteracted");

	Params::BP_InteractedBox_C_IsPhysicInteracted Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (OutInteracted != nullptr)
		*OutInteracted = Parms.OutInteracted;
}

}
