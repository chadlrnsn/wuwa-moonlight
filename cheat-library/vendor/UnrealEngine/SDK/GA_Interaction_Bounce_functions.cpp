#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GA_Interaction_Bounce

#include "Basic.hpp"

#include "GA_Interaction_Bounce_classes.hpp"
#include "GA_Interaction_Bounce_parameters.hpp"


namespace SDK
{

// Function GA_Interaction_Bounce.GA_Interaction_Bounce_C.ExecuteUbergraph_GA_Interaction_Bounce
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGA_Interaction_Bounce_C::ExecuteUbergraph_GA_Interaction_Bounce(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Interaction_Bounce_C", "ExecuteUbergraph_GA_Interaction_Bounce");

	Params::GA_Interaction_Bounce_C_ExecuteUbergraph_GA_Interaction_Bounce Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_Interaction_Bounce.GA_Interaction_Bounce_C.MovementModeChange
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class ACharacter*                       Character                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// EMovementMode                           PrevMovementMode                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// uint8                                   PreviousCustomMode                                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGA_Interaction_Bounce_C::MovementModeChange(class ACharacter* Character, EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Interaction_Bounce_C", "MovementModeChange");

	Params::GA_Interaction_Bounce_C_MovementModeChange Parms{};

	Parms.Character = Character;
	Parms.PrevMovementMode = PrevMovementMode;
	Parms.PreviousCustomMode = PreviousCustomMode;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_Interaction_Bounce.GA_Interaction_Bounce_C.K2_OnEndAbility
// (Event, Protected, BlueprintEvent)
// Parameters:
// bool                                    bWasCancelled                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UGA_Interaction_Bounce_C::K2_OnEndAbility(bool bWasCancelled)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Interaction_Bounce_C", "K2_OnEndAbility");

	Params::GA_Interaction_Bounce_C_K2_OnEndAbility Parms{};

	Parms.bWasCancelled = bWasCancelled;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GA_Interaction_Bounce.GA_Interaction_Bounce_C.K2_ActivateAbility
// (Event, Protected, BlueprintEvent)

void UGA_Interaction_Bounce_C::K2_ActivateAbility()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Interaction_Bounce_C", "K2_ActivateAbility");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_Interaction_Bounce.GA_Interaction_Bounce_C.OnCompleted_5D118C384AE61F1C80292E818F2F100F
// (BlueprintCallable, BlueprintEvent)

void UGA_Interaction_Bounce_C::OnCompleted_5D118C384AE61F1C80292E818F2F100F()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Interaction_Bounce_C", "OnCompleted_5D118C384AE61F1C80292E818F2F100F");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_Interaction_Bounce.GA_Interaction_Bounce_C.OnBlendOut_5D118C384AE61F1C80292E818F2F100F
// (BlueprintCallable, BlueprintEvent)

void UGA_Interaction_Bounce_C::OnBlendOut_5D118C384AE61F1C80292E818F2F100F()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Interaction_Bounce_C", "OnBlendOut_5D118C384AE61F1C80292E818F2F100F");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_Interaction_Bounce.GA_Interaction_Bounce_C.OnInterrupted_5D118C384AE61F1C80292E818F2F100F
// (BlueprintCallable, BlueprintEvent)

void UGA_Interaction_Bounce_C::OnInterrupted_5D118C384AE61F1C80292E818F2F100F()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Interaction_Bounce_C", "OnInterrupted_5D118C384AE61F1C80292E818F2F100F");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_Interaction_Bounce.GA_Interaction_Bounce_C.OnCancelled_5D118C384AE61F1C80292E818F2F100F
// (BlueprintCallable, BlueprintEvent)

void UGA_Interaction_Bounce_C::OnCancelled_5D118C384AE61F1C80292E818F2F100F()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Interaction_Bounce_C", "OnCancelled_5D118C384AE61F1C80292E818F2F100F");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GA_Interaction_Bounce.GA_Interaction_Bounce_C.OnTick_5D118C384AE61F1C80292E818F2F100F
// (BlueprintCallable, BlueprintEvent)

void UGA_Interaction_Bounce_C::OnTick_5D118C384AE61F1C80292E818F2F100F()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GA_Interaction_Bounce_C", "OnTick_5D118C384AE61F1C80292E818F2F100F");

	UObject::ProcessEvent(Func, nullptr);
}

}

