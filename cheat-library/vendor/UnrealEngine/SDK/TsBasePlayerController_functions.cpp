#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TsBasePlayerController

#include "Basic.hpp"

#include "TsBasePlayerController_classes.hpp"
#include "TsBasePlayerController_parameters.hpp"


namespace SDK
{

// Function TsBasePlayerController.TsBasePlayerController_C.ExecuteUbergraph_TsBasePlayerController
// (Final, Native, UbergraphFunction, Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ATsBasePlayerController_C::ExecuteUbergraph_TsBasePlayerController(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "ExecuteUbergraph_TsBasePlayerController");

	Params::TsBasePlayerController_C_ExecuteUbergraph_TsBasePlayerController Parms{};

	Parms.EntryPoint = EntryPoint;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function TsBasePlayerController.TsBasePlayerController_C.ReceiveTick
// (Native, Event, Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   DeltaSeconds                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ATsBasePlayerController_C::ReceiveTick(float DeltaSeconds)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "ReceiveTick");

	Params::TsBasePlayerController_C_ReceiveTick Parms{};

	Parms.DeltaSeconds = DeltaSeconds;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function TsBasePlayerController.TsBasePlayerController_C.ReceiveBeginPlay
// (Native, Event, Public, Protected, BlueprintCallable, BlueprintEvent)

void ATsBasePlayerController_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "ReceiveBeginPlay");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// Function TsBasePlayerController.TsBasePlayerController_C.ReceiveDestroyed
// (Native, Event, Public, BlueprintCallable, BlueprintEvent)

void ATsBasePlayerController_C::ReceiveDestroyed()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "ReceiveDestroyed");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// Function TsBasePlayerController.TsBasePlayerController_C.ReceiveSetupInputComponent
// (Native, Event, Public, BlueprintCallable, BlueprintEvent)

void ATsBasePlayerController_C::ReceiveSetupInputComponent()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "ReceiveSetupInputComponent");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// Function TsBasePlayerController.TsBasePlayerController_C.GetActionHandle
// (Native, Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           ActionName                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
// class UTsActionHandle_C*                ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

class UTsActionHandle_C* ATsBasePlayerController_C::GetActionHandle(const class FString& ActionName)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "GetActionHandle");

	Params::TsBasePlayerController_C_GetActionHandle Parms{};

	Parms.ActionName = std::move(ActionName);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function TsBasePlayerController.TsBasePlayerController_C.RemoveActionHandle
// (Native, Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           ActionName                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, UObjectWrapper, HasGetValueTypeHash)

void ATsBasePlayerController_C::RemoveActionHandle(const class FString& ActionName)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "RemoveActionHandle");

	Params::TsBasePlayerController_C_RemoveActionHandle Parms{};

	Parms.ActionName = std::move(ActionName);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function TsBasePlayerController.TsBasePlayerController_C.RemoveAxisHandle
// (Native, Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           AxisName                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, UObjectWrapper, HasGetValueTypeHash)

void ATsBasePlayerController_C::RemoveAxisHandle(const class FString& AxisName)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "RemoveAxisHandle");

	Params::TsBasePlayerController_C_RemoveAxisHandle Parms{};

	Parms.AxisName = std::move(AxisName);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function TsBasePlayerController.TsBasePlayerController_C.GetAxisHandle
// (Native, Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           ActionName                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, UObjectWrapper, HasGetValueTypeHash)
// class UTsAxisHandle_C*                  ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

class UTsAxisHandle_C* ATsBasePlayerController_C::GetAxisHandle(const class FString& ActionName)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "GetAxisHandle");

	Params::TsBasePlayerController_C_GetAxisHandle Parms{};

	Parms.ActionName = std::move(ActionName);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function TsBasePlayerController.TsBasePlayerController_C.BindTouchHandle
// (Native, Public, BlueprintCallable, BlueprintEvent)

void ATsBasePlayerController_C::BindTouchHandle()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "BindTouchHandle");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// Function TsBasePlayerController.TsBasePlayerController_C.OnTouchBegin
// (Native, Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// ETouchIndex                             TouchIndex                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash)
// struct FVector                          Position                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash)

void ATsBasePlayerController_C::OnTouchBegin(ETouchIndex TouchIndex, const struct FVector& Position)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "OnTouchBegin");

	Params::TsBasePlayerController_C_OnTouchBegin Parms{};

	Parms.TouchIndex = TouchIndex;
	Parms.Position = std::move(Position);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function TsBasePlayerController.TsBasePlayerController_C.OnTouchEnd
// (Native, Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// ETouchIndex                             TouchIndex                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash)
// struct FVector                          Position                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash)

void ATsBasePlayerController_C::OnTouchEnd(ETouchIndex TouchIndex, const struct FVector& Position)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "OnTouchEnd");

	Params::TsBasePlayerController_C_OnTouchEnd Parms{};

	Parms.TouchIndex = TouchIndex;
	Parms.Position = std::move(Position);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function TsBasePlayerController.TsBasePlayerController_C.OnTouchMove
// (Native, Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// ETouchIndex                             TouchIndex                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash)
// struct FVector                          Position                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash)

void ATsBasePlayerController_C::OnTouchMove(ETouchIndex TouchIndex, const struct FVector& Position)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "OnTouchMove");

	Params::TsBasePlayerController_C_OnTouchMove Parms{};

	Parms.TouchIndex = TouchIndex;
	Parms.Position = std::move(Position);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function TsBasePlayerController.TsBasePlayerController_C.OnSetupInputComponent
// (Native, Public, BlueprintCallable, BlueprintEvent)

void ATsBasePlayerController_C::OnSetupInputComponent()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "OnSetupInputComponent");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// Function TsBasePlayerController.TsBasePlayerController_C.OnPressAnyKey
// (Native, Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FKey                             Key                                                    (BlueprintVisible, BlueprintReadOnly, Parm, UObjectWrapper, HasGetValueTypeHash)

void ATsBasePlayerController_C::OnPressAnyKey(const struct FKey& Key)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "OnPressAnyKey");

	Params::TsBasePlayerController_C_OnPressAnyKey Parms{};

	Parms.Key = std::move(Key);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function TsBasePlayerController.TsBasePlayerController_C.IsInTouch
// (Native, Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   TouchId                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)

bool ATsBasePlayerController_C::IsInTouch(float TouchId)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "IsInTouch");

	Params::TsBasePlayerController_C_IsInTouch Parms{};

	Parms.TouchId = TouchId;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function TsBasePlayerController.TsBasePlayerController_C.ClearInputBinding
// (Native, Public, BlueprintCallable, BlueprintEvent)

void ATsBasePlayerController_C::ClearInputBinding()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "ClearInputBinding");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// Function TsBasePlayerController.TsBasePlayerController_C.AddInputBinding
// (Native, Public, BlueprintCallable, BlueprintEvent)

void ATsBasePlayerController_C::AddInputBinding()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "AddInputBinding");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// Function TsBasePlayerController.TsBasePlayerController_C.OnReleaseAnyKey
// (Native, Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FKey                             Key                                                    (BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)

void ATsBasePlayerController_C::OnReleaseAnyKey(const struct FKey& Key)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "OnReleaseAnyKey");

	Params::TsBasePlayerController_C_OnReleaseAnyKey Parms{};

	Parms.Key = std::move(Key);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function TsBasePlayerController.TsBasePlayerController_C.SetIsPrintKeyName
// (Native, Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    bPrintKeyName                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ATsBasePlayerController_C::SetIsPrintKeyName(bool bPrintKeyName)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "SetIsPrintKeyName");

	Params::TsBasePlayerController_C_SetIsPrintKeyName Parms{};

	Parms.bPrintKeyName = bPrintKeyName;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function TsBasePlayerController.TsBasePlayerController_C.InitInputHandle
// (Native, Public, BlueprintCallable, BlueprintEvent)

void ATsBasePlayerController_C::InitInputHandle()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("TsBasePlayerController_C", "InitInputHandle");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}

}

