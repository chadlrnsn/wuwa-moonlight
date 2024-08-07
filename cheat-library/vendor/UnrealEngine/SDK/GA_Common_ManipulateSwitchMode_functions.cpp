#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_Common_ManipulateSwitchMode

#include "Basic.hpp"

#include "GA_Common_ManipulateSwitchMode_classes.hpp"
#include "GA_Common_ManipulateSwitchMode_parameters.hpp"


namespace SDK
{

// Function GA_Common_ManipulateSwitchMode.GA_Common_ManipulateSwitchMode_C.ExecuteUbergraph_GA_Common_ManipulateSwitchMode
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGA_Common_ManipulateSwitchMode_C::ExecuteUbergraph_GA_Common_ManipulateSwitchMode(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Common_ManipulateSwitchMode_C", "ExecuteUbergraph_GA_Common_ManipulateSwitchMode");

	Params::GA_Common_ManipulateSwitchMode_C_ExecuteUbergraph_GA_Common_ManipulateSwitchMode Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_Common_ManipulateSwitchMode.GA_Common_ManipulateSwitchMode_C.K2_ActivateAbility
// (Event, Protected, BlueprintEvent)

void UGA_Common_ManipulateSwitchMode_C::K2_ActivateAbility()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Common_ManipulateSwitchMode_C", "K2_ActivateAbility");

	UObject::ProcessEvent(Func, nullptr);
}

}

