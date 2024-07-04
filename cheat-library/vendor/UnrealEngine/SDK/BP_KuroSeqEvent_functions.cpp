#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_KuroSeqEvent

#include "Basic.hpp"

#include "BP_KuroSeqEvent_classes.hpp"
#include "BP_KuroSeqEvent_parameters.hpp"


namespace SDK
{

// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.ExecuteUbergraph_BP_KuroSeqEvent
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_KuroSeqEvent_C::ExecuteUbergraph_BP_KuroSeqEvent(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "ExecuteUbergraph_BP_KuroSeqEvent");

	Params::BP_KuroSeqEvent_C_ExecuteUbergraph_BP_KuroSeqEvent Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.ReceiveDestroyed
// (Event, Public, BlueprintEvent)

void ABP_KuroSeqEvent_C::ReceiveDestroyed()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "ReceiveDestroyed");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.ReceiveTick
// (Event, Public, BlueprintEvent)
// Parameters:
// float                                   DeltaSeconds                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_KuroSeqEvent_C::ReceiveTick(float DeltaSeconds)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "ReceiveTick");

	Params::BP_KuroSeqEvent_C_ReceiveTick Parms{};

	Parms.DeltaSeconds = DeltaSeconds;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.��t_0__UpdateFunc
// (BlueprintEvent)

void ABP_KuroSeqEvent_C::__t_0__UpdateFunc()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "��t_0__UpdateFunc");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.��t_0__FinishedFunc
// (BlueprintEvent)

void ABP_KuroSeqEvent_C::__t_0__FinishedFunc()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "��t_0__FinishedFunc");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.Play Subtitle
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FSSubtitleSettings               InSubtitle                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_KuroSeqEvent_C::Play_Subtitle(const struct FSSubtitleSettings& InSubtitle)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "Play Subtitle");

	Params::BP_KuroSeqEvent_C_Play_Subtitle Parms{};

	Parms.InSubtitle = std::move(InSubtitle);

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.JumpToSequenceNode
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FName                             InSeqNodeID                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_KuroSeqEvent_C::JumpToSequenceNode(class FName InSeqNodeID)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "JumpToSequenceNode");

	Params::BP_KuroSeqEvent_C_JumpToSequenceNode Parms{};

	Parms.InSeqNodeID = InSeqNodeID;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.PauseSequence
// (Public, BlueprintCallable, BlueprintEvent)

void ABP_KuroSeqEvent_C::PauseSequence()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "PauseSequence");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.ResumeSequnece
// (Public, BlueprintCallable, BlueprintEvent)

void ABP_KuroSeqEvent_C::ResumeSequnece()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "ResumeSequnece");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.EnableUIInput
// (Public, BlueprintCallable, BlueprintEvent)

void ABP_KuroSeqEvent_C::EnableUIInput()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "EnableUIInput");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.JumpToSequenceNodeWithOption
// (Public, BlueprintCallable, BlueprintEvent)

void ABP_KuroSeqEvent_C::JumpToSequenceNodeWithOption()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "JumpToSequenceNodeWithOption");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.JumpToOtherSeqNetwrok
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FName                             InRowName                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UDataTable*                       InSeqNetworks                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_KuroSeqEvent_C::JumpToOtherSeqNetwrok(class FName InRowName, class UDataTable* InSeqNetworks)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "JumpToOtherSeqNetwrok");

	Params::BP_KuroSeqEvent_C_JumpToOtherSeqNetwrok Parms{};

	Parms.InRowName = InRowName;
	Parms.InSeqNetworks = InSeqNetworks;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.Interaction
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FSSubtitleSettings               InSubtitleSettings                                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_KuroSeqEvent_C::Interaction(const struct FSSubtitleSettings& InSubtitleSettings)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "Interaction");

	Params::BP_KuroSeqEvent_C_Interaction Parms{};

	Parms.InSubtitleSettings = std::move(InSubtitleSettings);

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.GeneralEvent
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FName                             InEventID                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_KuroSeqEvent_C::GeneralEvent(class FName InEventID)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "GeneralEvent");

	Params::BP_KuroSeqEvent_C_GeneralEvent Parms{};

	Parms.InEventID = InEventID;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.NPC Rotate
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   __                                                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_KuroSeqEvent_C::NPC_Rotate(float __)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "NPC Rotate");

	Params::BP_KuroSeqEvent_C_NPC_Rotate Parms{};

	Parms.__ = __;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.PlayerUIMovie
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UFileMediaSource*                 MediaSource                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    IsMove                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// struct FVector                          Inlocation                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    IsTotate                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// struct FRotator                         InRotation                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ABP_KuroSeqEvent_C::PlayerUIMovie(class UFileMediaSource* MediaSource, bool IsMove, const struct FVector& Inlocation, bool IsTotate, const struct FRotator& InRotation)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "PlayerUIMovie");

	Params::BP_KuroSeqEvent_C_PlayerUIMovie Parms{};

	Parms.MediaSource = MediaSource;
	Parms.IsMove = IsMove;
	Parms.Inlocation = std::move(Inlocation);
	Parms.IsTotate = IsTotate;
	Parms.InRotation = std::move(InRotation);

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.MoveAfterMoviePlay
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void ABP_KuroSeqEvent_C::MoveAfterMoviePlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "MoveAfterMoviePlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.DirectInteraction
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FName                             InteractionID                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_KuroSeqEvent_C::DirectInteraction(class FName InteractionID)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "DirectInteraction");

	Params::BP_KuroSeqEvent_C_DirectInteraction Parms{};

	Parms.InteractionID = InteractionID;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.SetCharacterBinding
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           InTag                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)

void ABP_KuroSeqEvent_C::SetCharacterBinding(const class FString& InTag)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "SetCharacterBinding");

	Params::BP_KuroSeqEvent_C_SetCharacterBinding Parms{};

	Parms.InTag = std::move(InTag);

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.BlendingCharacter
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FSSeqCharacterBlendGroup         InSettings                                             (BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)

void ABP_KuroSeqEvent_C::BlendingCharacter(const struct FSSeqCharacterBlendGroup& InSettings)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "BlendingCharacter");

	Params::BP_KuroSeqEvent_C_BlendingCharacter Parms{};

	Parms.InSettings = std::move(InSettings);

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.BlendHelper
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void ABP_KuroSeqEvent_C::BlendHelper()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "BlendHelper");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.Set Motion Blur
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    _                                                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ABP_KuroSeqEvent_C::Set_Motion_Blur(bool _)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "Set Motion Blur");

	Params::BP_KuroSeqEvent_C_Set_Motion_Blur Parms{};

	Parms._ = _;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.ChangeWeather
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   __Id                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    __                                                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// float                                   ____                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_KuroSeqEvent_C::ChangeWeather(int32 __Id, bool __, float ____)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "ChangeWeather");

	Params::BP_KuroSeqEvent_C_ChangeWeather Parms{};

	Parms.__Id = __Id;
	Parms.__ = __;
	Parms.____ = ____;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_KuroSeqEvent.BP_KuroSeqEvent_C.ChangeTimeOfDay
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    __                                                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// int32                                   ___0                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   ___1                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   ___p                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   ____                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   _____0                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_KuroSeqEvent_C::ChangeTimeOfDay(bool __, int32 ___0, int32 ___1, int32 ___p, int32 ____, int32 _____0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_KuroSeqEvent_C", "ChangeTimeOfDay");

	Params::BP_KuroSeqEvent_C_ChangeTimeOfDay Parms{};

	Parms.__ = __;
	Parms.___0 = ___0;
	Parms.___1 = ___1;
	Parms.___p = ___p;
	Parms.____ = ____;
	Parms._____0 = _____0;

	UObject::ProcessEvent(Func, &Parms);
}

}
