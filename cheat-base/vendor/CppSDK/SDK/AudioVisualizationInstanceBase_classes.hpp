#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AudioVisualizationInstanceBase

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "AkAudio_structs.hpp"


namespace SDK
{

// TypeScriptGeneratedClass AudioVisualizationInstanceBase.AudioVisualizationInstanceBase_C
// 0x0020 (0x02C8 - 0x02A8)
class AAudioVisualizationInstanceBase_C final : public AActor
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x02A8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x02B0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class FString                                 Identifier;                                        // 0x02B8(0x0010)(Edit, BlueprintVisible, ZeroConstructor, UObjectWrapper, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_AudioVisualizationInstanceBase(int32 EntryPoint);
	void ReceiveEndPlay(EEndPlayReason EndPlayReason);
	void EndInternal();
	void CallBackInternal(class UAkCallbackInfo* CallbackInfo, EAkCallbackType CallbackType, const class FString& State);
	void MidiBpm();
	void StartInternal();
	void MidiC3On(uint8 Velocity1);
	void MidiCs3On(uint8 Velocity1);
	void MidiD3On(uint8 Velocity1);
	void MidiDs3On(uint8 Velocity1);
	void MidiE3On(uint8 Velocity1);
	void MidiF3On(uint8 Velocity1);
	void MidiFs3On(uint8 Velocity1);
	void MidiG3On(uint8 Velocity1);
	void MidiGs3On(uint8 Velocity1);
	void MidiA3On(uint8 Velocity1);
	void MidiAs3On(uint8 Velocity1);
	void MidiB3On(uint8 Velocity1);
	void MidiC3Off(uint8 Velocity1);
	void MidiCs3Off(uint8 Velocity1);
	void MidiD3Off(uint8 Velocity1);
	void MidiDs3Off(uint8 Velocity1);
	void MidiE3Off(uint8 Velocity1);
	void MidiF3Off(uint8 Velocity1);
	void MidiFs3Off(uint8 Velocity1);
	void MidiG3Off(uint8 Velocity1);
	void MidiGs3Off(uint8 Velocity1);
	void MidiA3Off(uint8 Velocity1);
	void MidiAs3Off(uint8 Velocity1);
	void MidiB3Off(uint8 Velocity1);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AudioVisualizationInstanceBase_C">();
	}
	static class AAudioVisualizationInstanceBase_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AAudioVisualizationInstanceBase_C>();
	}
};
static_assert(alignof(AAudioVisualizationInstanceBase_C) == 0x000008, "Wrong alignment on AAudioVisualizationInstanceBase_C");
static_assert(sizeof(AAudioVisualizationInstanceBase_C) == 0x0002C8, "Wrong size on AAudioVisualizationInstanceBase_C");
static_assert(offsetof(AAudioVisualizationInstanceBase_C, UberGraphFrame) == 0x0002A8, "Member 'AAudioVisualizationInstanceBase_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(AAudioVisualizationInstanceBase_C, DefaultSceneRoot) == 0x0002B0, "Member 'AAudioVisualizationInstanceBase_C::DefaultSceneRoot' has a wrong offset!");
static_assert(offsetof(AAudioVisualizationInstanceBase_C, Identifier) == 0x0002B8, "Member 'AAudioVisualizationInstanceBase_C::Identifier' has a wrong offset!");

}
