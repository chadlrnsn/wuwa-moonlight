#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BPL_BulletPreview

#include "Basic.hpp"

#include "BPL_BulletPreview_classes.hpp"
#include "BPL_BulletPreview_parameters.hpp"


namespace SDK
{

// Function BPL_BulletPreview.BPL_BulletPreview_C.ShowBulletPreview
// (Static, Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           P9h__                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
// class FName                             P9ID                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class AActor*                           ___                                                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class USkeletalMeshComponent*           MeshComp                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class AActor*                           Ret                                                    (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBPL_BulletPreview_C::ShowBulletPreview(const class FString& P9h__, class FName P9ID, class AActor* ___, class USkeletalMeshComponent* MeshComp, class UObject* __WorldContext, class AActor** Ret)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("BPL_BulletPreview_C", "ShowBulletPreview");

	Params::BPL_BulletPreview_C_ShowBulletPreview Parms{};

	Parms.P9h__ = std::move(P9h__);
	Parms.P9ID = P9ID;
	Parms.___ = ___;
	Parms.MeshComp = MeshComp;
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (Ret != nullptr)
		*Ret = Parms.Ret;
}

}

