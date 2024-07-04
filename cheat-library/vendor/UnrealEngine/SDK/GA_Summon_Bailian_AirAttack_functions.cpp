#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_Summon_Bailian_AirAttack

#include "Basic.hpp"

#include "GA_Summon_Bailian_AirAttack_classes.hpp"
#include "GA_Summon_Bailian_AirAttack_parameters.hpp"


namespace SDK
{

// Function GA_Summon_Bailian_AirAttack.GA_Summon_Bailian_AirAttack_C.ExecuteUbergraph_GA_Summon_Bailian_AirAttack
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGA_Summon_Bailian_AirAttack_C::ExecuteUbergraph_GA_Summon_Bailian_AirAttack(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Summon_Bailian_AirAttack_C", "ExecuteUbergraph_GA_Summon_Bailian_AirAttack");

	Params::GA_Summon_Bailian_AirAttack_C_ExecuteUbergraph_GA_Summon_Bailian_AirAttack Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_Summon_Bailian_AirAttack.GA_Summon_Bailian_AirAttack_C.K2_OnEndAbility
// (Event, Protected, BlueprintEvent)
// Parameters:
// bool                                    bWasCancelled                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UGA_Summon_Bailian_AirAttack_C::K2_OnEndAbility(bool bWasCancelled)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Summon_Bailian_AirAttack_C", "K2_OnEndAbility");

	Params::GA_Summon_Bailian_AirAttack_C_K2_OnEndAbility Parms{};

	Parms.bWasCancelled = bWasCancelled;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_Summon_Bailian_AirAttack.GA_Summon_Bailian_AirAttack_C.K2_ActivateAbility
// (Event, Protected, BlueprintEvent)

void UGA_Summon_Bailian_AirAttack_C::K2_ActivateAbility()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Summon_Bailian_AirAttack_C", "K2_ActivateAbility");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_Summon_Bailian_AirAttack.GA_Summon_Bailian_AirAttack_C.OnCompleted_5D118C384AE61F1C80292E8198172FAE
// (BlueprintCallable, BlueprintEvent)

void UGA_Summon_Bailian_AirAttack_C::OnCompleted_5D118C384AE61F1C80292E8198172FAE()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Summon_Bailian_AirAttack_C", "OnCompleted_5D118C384AE61F1C80292E8198172FAE");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_Summon_Bailian_AirAttack.GA_Summon_Bailian_AirAttack_C.OnBlendOut_5D118C384AE61F1C80292E8198172FAE
// (BlueprintCallable, BlueprintEvent)

void UGA_Summon_Bailian_AirAttack_C::OnBlendOut_5D118C384AE61F1C80292E8198172FAE()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Summon_Bailian_AirAttack_C", "OnBlendOut_5D118C384AE61F1C80292E8198172FAE");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_Summon_Bailian_AirAttack.GA_Summon_Bailian_AirAttack_C.OnInterrupted_5D118C384AE61F1C80292E8198172FAE
// (BlueprintCallable, BlueprintEvent)

void UGA_Summon_Bailian_AirAttack_C::OnInterrupted_5D118C384AE61F1C80292E8198172FAE()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Summon_Bailian_AirAttack_C", "OnInterrupted_5D118C384AE61F1C80292E8198172FAE");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_Summon_Bailian_AirAttack.GA_Summon_Bailian_AirAttack_C.OnCancelled_5D118C384AE61F1C80292E8198172FAE
// (BlueprintCallable, BlueprintEvent)

void UGA_Summon_Bailian_AirAttack_C::OnCancelled_5D118C384AE61F1C80292E8198172FAE()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Summon_Bailian_AirAttack_C", "OnCancelled_5D118C384AE61F1C80292E8198172FAE");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_Summon_Bailian_AirAttack.GA_Summon_Bailian_AirAttack_C.OnTick_5D118C384AE61F1C80292E8198172FAE
// (BlueprintCallable, BlueprintEvent)

void UGA_Summon_Bailian_AirAttack_C::OnTick_5D118C384AE61F1C80292E8198172FAE()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Summon_Bailian_AirAttack_C", "OnTick_5D118C384AE61F1C80292E8198172FAE");

	UObject::ProcessEvent(Func, nullptr);
}

}
