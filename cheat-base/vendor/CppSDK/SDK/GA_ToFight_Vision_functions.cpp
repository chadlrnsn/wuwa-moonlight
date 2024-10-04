#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_ToFight_Vision

#include "Basic.hpp"

#include "GA_ToFight_Vision_classes.hpp"
#include "GA_ToFight_Vision_parameters.hpp"


namespace SDK
{

// Function GA_ToFight_Vision.GA_ToFight_Vision_C.ExecuteUbergraph_GA_ToFight_Vision
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGA_ToFight_Vision_C::ExecuteUbergraph_GA_ToFight_Vision(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_ToFight_Vision_C", "ExecuteUbergraph_GA_ToFight_Vision");

	Params::GA_ToFight_Vision_C_ExecuteUbergraph_GA_ToFight_Vision Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_ToFight_Vision.GA_ToFight_Vision_C.K2_OnEndAbility
// (Event, Protected, BlueprintEvent)
// Parameters:
// bool                                    bWasCancelled                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UGA_ToFight_Vision_C::K2_OnEndAbility(bool bWasCancelled)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_ToFight_Vision_C", "K2_OnEndAbility");

	Params::GA_ToFight_Vision_C_K2_OnEndAbility Parms{};

	Parms.bWasCancelled = bWasCancelled;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_ToFight_Vision.GA_ToFight_Vision_C.K2_ActivateAbility
// (Event, Protected, BlueprintEvent)

void UGA_ToFight_Vision_C::K2_ActivateAbility()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_ToFight_Vision_C", "K2_ActivateAbility");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_ToFight_Vision.GA_ToFight_Vision_C.OnCompleted_5D118C384AE61F1C80292E8161096401
// (BlueprintCallable, BlueprintEvent)

void UGA_ToFight_Vision_C::OnCompleted_5D118C384AE61F1C80292E8161096401()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_ToFight_Vision_C", "OnCompleted_5D118C384AE61F1C80292E8161096401");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_ToFight_Vision.GA_ToFight_Vision_C.OnBlendOut_5D118C384AE61F1C80292E8161096401
// (BlueprintCallable, BlueprintEvent)

void UGA_ToFight_Vision_C::OnBlendOut_5D118C384AE61F1C80292E8161096401()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_ToFight_Vision_C", "OnBlendOut_5D118C384AE61F1C80292E8161096401");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_ToFight_Vision.GA_ToFight_Vision_C.OnInterrupted_5D118C384AE61F1C80292E8161096401
// (BlueprintCallable, BlueprintEvent)

void UGA_ToFight_Vision_C::OnInterrupted_5D118C384AE61F1C80292E8161096401()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_ToFight_Vision_C", "OnInterrupted_5D118C384AE61F1C80292E8161096401");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_ToFight_Vision.GA_ToFight_Vision_C.OnCancelled_5D118C384AE61F1C80292E8161096401
// (BlueprintCallable, BlueprintEvent)

void UGA_ToFight_Vision_C::OnCancelled_5D118C384AE61F1C80292E8161096401()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_ToFight_Vision_C", "OnCancelled_5D118C384AE61F1C80292E8161096401");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_ToFight_Vision.GA_ToFight_Vision_C.OnTick_5D118C384AE61F1C80292E8161096401
// (BlueprintCallable, BlueprintEvent)

void UGA_ToFight_Vision_C::OnTick_5D118C384AE61F1C80292E8161096401()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_ToFight_Vision_C", "OnTick_5D118C384AE61F1C80292E8161096401");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_ToFight_Vision.GA_ToFight_Vision_C.��{apn
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class ATsBaseCharacter_C*               Entity                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    __0                                                    (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
// struct FSVisionData                     __L                                                    (Parm, OutParm, ContainsInstancedReference, HasGetValueTypeHash)

void UGA_ToFight_Vision_C::___apn(class ATsBaseCharacter_C* Entity, bool* __0, struct FSVisionData* __L)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_ToFight_Vision_C", "��{apn");

	Params::GA_ToFight_Vision_C____apn Parms{};

	Parms.Entity = Entity;

	UObject::ProcessEvent(Func, &Parms);

	if (__0 != nullptr)
		*__0 = Parms.__0;

	if (__L != nullptr)
		*__L = std::move(Parms.__L);
}

}
