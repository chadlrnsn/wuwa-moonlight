#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_ThunderGenerator

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "KuroCurve_structs.hpp"
#include "KuroRenderingRuntimeBPPlugin_classes.hpp"
#include "AkAudio_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_ThunderGenerator.BP_ThunderGenerator_C
// 0x00B8 (0x0598 - 0x04E0)
class ABP_ThunderGenerator_C final : public AThunderGenerator
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x04E0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UPDA_ThunderConfigMap_C*                ThunderConfigMap;                                  // 0x04E8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UPDA_ThunderConfig_C*                   ThunderConfig;                                     // 0x04F0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, Transient, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAkAudioEvent*                          CachedAudioEvent2D;                                // 0x04F8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, Transient, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CachedTransition;                                  // 0x0500(0x0004)(Edit, BlueprintVisible, ZeroConstructor, Transient, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_35C0[0x4];                                     // 0x0504(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FKuroCurveFloat                        CachedCloudLightCurve;                             // 0x0508(0x0090)(Edit, BlueprintVisible, Transient, DisableEditOnInstance)

public:
	void ExecuteUbergraph_BP_ThunderGenerator(int32 EntryPoint);
	void ReceiveEndPlay(EEndPlayReason EndPlayReason);
	void OnUpdateThunderEffect(float DeltaSeconds);
	void OnThunderTypeChanged();
	void OnReceiveThunderAttack(const struct FVector& Location, bool bAttack);
	void UpdateAudio2D();
	void ClearThunder();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_ThunderGenerator_C">();
	}
	static class ABP_ThunderGenerator_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_ThunderGenerator_C>();
	}
};
static_assert(alignof(ABP_ThunderGenerator_C) == 0x000008, "Wrong alignment on ABP_ThunderGenerator_C");
static_assert(sizeof(ABP_ThunderGenerator_C) == 0x000598, "Wrong size on ABP_ThunderGenerator_C");
static_assert(offsetof(ABP_ThunderGenerator_C, UberGraphFrame) == 0x0004E0, "Member 'ABP_ThunderGenerator_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, ThunderConfigMap) == 0x0004E8, "Member 'ABP_ThunderGenerator_C::ThunderConfigMap' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, ThunderConfig) == 0x0004F0, "Member 'ABP_ThunderGenerator_C::ThunderConfig' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, CachedAudioEvent2D) == 0x0004F8, "Member 'ABP_ThunderGenerator_C::CachedAudioEvent2D' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, CachedTransition) == 0x000500, "Member 'ABP_ThunderGenerator_C::CachedTransition' has a wrong offset!");
static_assert(offsetof(ABP_ThunderGenerator_C, CachedCloudLightCurve) == 0x000508, "Member 'ABP_ThunderGenerator_C::CachedCloudLightCurve' has a wrong offset!");

}
