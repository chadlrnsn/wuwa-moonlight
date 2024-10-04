#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: KuroData

#include "Basic.hpp"

#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function KuroData.KuroHitResult.GetHitCount
// 0x0004 (0x0004 - 0x0000)
struct KuroHitResult_GetHitCount final
{
public:
	int32                                         ReturnValue;                                       // 0x0000(0x0004)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(KuroHitResult_GetHitCount) == 0x000004, "Wrong alignment on KuroHitResult_GetHitCount");
static_assert(sizeof(KuroHitResult_GetHitCount) == 0x000004, "Wrong size on KuroHitResult_GetHitCount");
static_assert(offsetof(KuroHitResult_GetHitCount, ReturnValue) == 0x000000, "Member 'KuroHitResult_GetHitCount::ReturnValue' has a wrong offset!");

// Function KuroData.KuroTraceLibrary.BoxTrace
// 0x0020 (0x0020 - 0x0000)
struct KuroTraceLibrary_BoxTrace final
{
public:
	class UTraceBoxElement*                       Element;                                           // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 ProfileKey;                                        // 0x0008(0x0010)(Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          ReturnValue;                                       // 0x0018(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19[0x7];                                       // 0x0019(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};
static_assert(alignof(KuroTraceLibrary_BoxTrace) == 0x000008, "Wrong alignment on KuroTraceLibrary_BoxTrace");
static_assert(sizeof(KuroTraceLibrary_BoxTrace) == 0x000020, "Wrong size on KuroTraceLibrary_BoxTrace");
static_assert(offsetof(KuroTraceLibrary_BoxTrace, Element) == 0x000000, "Member 'KuroTraceLibrary_BoxTrace::Element' has a wrong offset!");
static_assert(offsetof(KuroTraceLibrary_BoxTrace, ProfileKey) == 0x000008, "Member 'KuroTraceLibrary_BoxTrace::ProfileKey' has a wrong offset!");
static_assert(offsetof(KuroTraceLibrary_BoxTrace, ReturnValue) == 0x000018, "Member 'KuroTraceLibrary_BoxTrace::ReturnValue' has a wrong offset!");

// Function KuroData.KuroTraceLibrary.CapsuleTrace
// 0x0020 (0x0020 - 0x0000)
struct KuroTraceLibrary_CapsuleTrace final
{
public:
	class UTraceCapsuleElement*                   Element;                                           // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 ProfileKey;                                        // 0x0008(0x0010)(Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          ReturnValue;                                       // 0x0018(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19[0x7];                                       // 0x0019(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};
static_assert(alignof(KuroTraceLibrary_CapsuleTrace) == 0x000008, "Wrong alignment on KuroTraceLibrary_CapsuleTrace");
static_assert(sizeof(KuroTraceLibrary_CapsuleTrace) == 0x000020, "Wrong size on KuroTraceLibrary_CapsuleTrace");
static_assert(offsetof(KuroTraceLibrary_CapsuleTrace, Element) == 0x000000, "Member 'KuroTraceLibrary_CapsuleTrace::Element' has a wrong offset!");
static_assert(offsetof(KuroTraceLibrary_CapsuleTrace, ProfileKey) == 0x000008, "Member 'KuroTraceLibrary_CapsuleTrace::ProfileKey' has a wrong offset!");
static_assert(offsetof(KuroTraceLibrary_CapsuleTrace, ReturnValue) == 0x000018, "Member 'KuroTraceLibrary_CapsuleTrace::ReturnValue' has a wrong offset!");

// Function KuroData.KuroTraceLibrary.LineTrace
// 0x0020 (0x0020 - 0x0000)
struct KuroTraceLibrary_LineTrace final
{
public:
	class UTraceLineElement*                      Element;                                           // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 ProfileKey;                                        // 0x0008(0x0010)(Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          ReturnValue;                                       // 0x0018(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19[0x7];                                       // 0x0019(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};
static_assert(alignof(KuroTraceLibrary_LineTrace) == 0x000008, "Wrong alignment on KuroTraceLibrary_LineTrace");
static_assert(sizeof(KuroTraceLibrary_LineTrace) == 0x000020, "Wrong size on KuroTraceLibrary_LineTrace");
static_assert(offsetof(KuroTraceLibrary_LineTrace, Element) == 0x000000, "Member 'KuroTraceLibrary_LineTrace::Element' has a wrong offset!");
static_assert(offsetof(KuroTraceLibrary_LineTrace, ProfileKey) == 0x000008, "Member 'KuroTraceLibrary_LineTrace::ProfileKey' has a wrong offset!");
static_assert(offsetof(KuroTraceLibrary_LineTrace, ReturnValue) == 0x000018, "Member 'KuroTraceLibrary_LineTrace::ReturnValue' has a wrong offset!");

// Function KuroData.KuroTraceLibrary.ShapeTrace
// 0x0038 (0x0038 - 0x0000)
struct KuroTraceLibrary_ShapeTrace final
{
public:
	class UShapeComponent*                        InShapeComp;                                       // 0x0000(0x0008)(Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTraceBaseElement*                      Element;                                           // 0x0008(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FName                                   TraceTagName;                                      // 0x0010(0x000C)(ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1C[0x4];                                       // 0x001C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 ProfileKey;                                        // 0x0020(0x0010)(Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          ReturnValue;                                       // 0x0030(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_31[0x7];                                       // 0x0031(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};
static_assert(alignof(KuroTraceLibrary_ShapeTrace) == 0x000008, "Wrong alignment on KuroTraceLibrary_ShapeTrace");
static_assert(sizeof(KuroTraceLibrary_ShapeTrace) == 0x000038, "Wrong size on KuroTraceLibrary_ShapeTrace");
static_assert(offsetof(KuroTraceLibrary_ShapeTrace, InShapeComp) == 0x000000, "Member 'KuroTraceLibrary_ShapeTrace::InShapeComp' has a wrong offset!");
static_assert(offsetof(KuroTraceLibrary_ShapeTrace, Element) == 0x000008, "Member 'KuroTraceLibrary_ShapeTrace::Element' has a wrong offset!");
static_assert(offsetof(KuroTraceLibrary_ShapeTrace, TraceTagName) == 0x000010, "Member 'KuroTraceLibrary_ShapeTrace::TraceTagName' has a wrong offset!");
static_assert(offsetof(KuroTraceLibrary_ShapeTrace, ProfileKey) == 0x000020, "Member 'KuroTraceLibrary_ShapeTrace::ProfileKey' has a wrong offset!");
static_assert(offsetof(KuroTraceLibrary_ShapeTrace, ReturnValue) == 0x000030, "Member 'KuroTraceLibrary_ShapeTrace::ReturnValue' has a wrong offset!");

// Function KuroData.KuroTraceLibrary.SphereTrace
// 0x0020 (0x0020 - 0x0000)
struct KuroTraceLibrary_SphereTrace final
{
public:
	class UTraceSphereElement*                    Element;                                           // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 ProfileKey;                                        // 0x0008(0x0010)(Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          ReturnValue;                                       // 0x0018(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19[0x7];                                       // 0x0019(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};
static_assert(alignof(KuroTraceLibrary_SphereTrace) == 0x000008, "Wrong alignment on KuroTraceLibrary_SphereTrace");
static_assert(sizeof(KuroTraceLibrary_SphereTrace) == 0x000020, "Wrong size on KuroTraceLibrary_SphereTrace");
static_assert(offsetof(KuroTraceLibrary_SphereTrace, Element) == 0x000000, "Member 'KuroTraceLibrary_SphereTrace::Element' has a wrong offset!");
static_assert(offsetof(KuroTraceLibrary_SphereTrace, ProfileKey) == 0x000008, "Member 'KuroTraceLibrary_SphereTrace::ProfileKey' has a wrong offset!");
static_assert(offsetof(KuroTraceLibrary_SphereTrace, ReturnValue) == 0x000018, "Member 'KuroTraceLibrary_SphereTrace::ReturnValue' has a wrong offset!");

// Function KuroData.TraceBaseElement.AddObjectTypeQuery
// 0x0001 (0x0001 - 0x0000)
struct TraceBaseElement_AddObjectTypeQuery final
{
public:
	EObjectTypeQuery                              ObjectType;                                        // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(TraceBaseElement_AddObjectTypeQuery) == 0x000001, "Wrong alignment on TraceBaseElement_AddObjectTypeQuery");
static_assert(sizeof(TraceBaseElement_AddObjectTypeQuery) == 0x000001, "Wrong size on TraceBaseElement_AddObjectTypeQuery");
static_assert(offsetof(TraceBaseElement_AddObjectTypeQuery, ObjectType) == 0x000000, "Member 'TraceBaseElement_AddObjectTypeQuery::ObjectType' has a wrong offset!");

// Function KuroData.TraceBaseElement.ClearCacheData
// 0x0001 (0x0001 - 0x0000)
struct TraceBaseElement_ClearCacheData final
{
public:
	bool                                          bClearWorld;                                       // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(TraceBaseElement_ClearCacheData) == 0x000001, "Wrong alignment on TraceBaseElement_ClearCacheData");
static_assert(sizeof(TraceBaseElement_ClearCacheData) == 0x000001, "Wrong size on TraceBaseElement_ClearCacheData");
static_assert(offsetof(TraceBaseElement_ClearCacheData, bClearWorld) == 0x000000, "Member 'TraceBaseElement_ClearCacheData::bClearWorld' has a wrong offset!");

// Function KuroData.TraceBaseElement.SetDrawDebugTrace
// 0x0001 (0x0001 - 0x0000)
struct TraceBaseElement_SetDrawDebugTrace final
{
public:
	EDrawDebugTrace                               Type;                                              // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(TraceBaseElement_SetDrawDebugTrace) == 0x000001, "Wrong alignment on TraceBaseElement_SetDrawDebugTrace");
static_assert(sizeof(TraceBaseElement_SetDrawDebugTrace) == 0x000001, "Wrong size on TraceBaseElement_SetDrawDebugTrace");
static_assert(offsetof(TraceBaseElement_SetDrawDebugTrace, Type) == 0x000000, "Member 'TraceBaseElement_SetDrawDebugTrace::Type' has a wrong offset!");

// Function KuroData.TraceBaseElement.SetEndLocation
// 0x000C (0x000C - 0x0000)
struct TraceBaseElement_SetEndLocation final
{
public:
	float                                         X;                                                 // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         Y;                                                 // 0x0004(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         Z;                                                 // 0x0008(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(TraceBaseElement_SetEndLocation) == 0x000004, "Wrong alignment on TraceBaseElement_SetEndLocation");
static_assert(sizeof(TraceBaseElement_SetEndLocation) == 0x00000C, "Wrong size on TraceBaseElement_SetEndLocation");
static_assert(offsetof(TraceBaseElement_SetEndLocation, X) == 0x000000, "Member 'TraceBaseElement_SetEndLocation::X' has a wrong offset!");
static_assert(offsetof(TraceBaseElement_SetEndLocation, Y) == 0x000004, "Member 'TraceBaseElement_SetEndLocation::Y' has a wrong offset!");
static_assert(offsetof(TraceBaseElement_SetEndLocation, Z) == 0x000008, "Member 'TraceBaseElement_SetEndLocation::Z' has a wrong offset!");

// Function KuroData.TraceBaseElement.SetObjectTypesQuery
// 0x0010 (0x0010 - 0x0000)
struct TraceBaseElement_SetObjectTypesQuery final
{
public:
	TArray<EObjectTypeQuery>                      ObjectTypes;                                       // 0x0000(0x0010)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};
static_assert(alignof(TraceBaseElement_SetObjectTypesQuery) == 0x000008, "Wrong alignment on TraceBaseElement_SetObjectTypesQuery");
static_assert(sizeof(TraceBaseElement_SetObjectTypesQuery) == 0x000010, "Wrong size on TraceBaseElement_SetObjectTypesQuery");
static_assert(offsetof(TraceBaseElement_SetObjectTypesQuery, ObjectTypes) == 0x000000, "Member 'TraceBaseElement_SetObjectTypesQuery::ObjectTypes' has a wrong offset!");

// Function KuroData.TraceBaseElement.SetStartLocation
// 0x000C (0x000C - 0x0000)
struct TraceBaseElement_SetStartLocation final
{
public:
	float                                         X;                                                 // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         Y;                                                 // 0x0004(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         Z;                                                 // 0x0008(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(TraceBaseElement_SetStartLocation) == 0x000004, "Wrong alignment on TraceBaseElement_SetStartLocation");
static_assert(sizeof(TraceBaseElement_SetStartLocation) == 0x00000C, "Wrong size on TraceBaseElement_SetStartLocation");
static_assert(offsetof(TraceBaseElement_SetStartLocation, X) == 0x000000, "Member 'TraceBaseElement_SetStartLocation::X' has a wrong offset!");
static_assert(offsetof(TraceBaseElement_SetStartLocation, Y) == 0x000004, "Member 'TraceBaseElement_SetStartLocation::Y' has a wrong offset!");
static_assert(offsetof(TraceBaseElement_SetStartLocation, Z) == 0x000008, "Member 'TraceBaseElement_SetStartLocation::Z' has a wrong offset!");

// Function KuroData.TraceBaseElement.SetTraceColor
// 0x0010 (0x0010 - 0x0000)
struct TraceBaseElement_SetTraceColor final
{
public:
	float                                         R;                                                 // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         G;                                                 // 0x0004(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         B;                                                 // 0x0008(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         A;                                                 // 0x000C(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(TraceBaseElement_SetTraceColor) == 0x000004, "Wrong alignment on TraceBaseElement_SetTraceColor");
static_assert(sizeof(TraceBaseElement_SetTraceColor) == 0x000010, "Wrong size on TraceBaseElement_SetTraceColor");
static_assert(offsetof(TraceBaseElement_SetTraceColor, R) == 0x000000, "Member 'TraceBaseElement_SetTraceColor::R' has a wrong offset!");
static_assert(offsetof(TraceBaseElement_SetTraceColor, G) == 0x000004, "Member 'TraceBaseElement_SetTraceColor::G' has a wrong offset!");
static_assert(offsetof(TraceBaseElement_SetTraceColor, B) == 0x000008, "Member 'TraceBaseElement_SetTraceColor::B' has a wrong offset!");
static_assert(offsetof(TraceBaseElement_SetTraceColor, A) == 0x00000C, "Member 'TraceBaseElement_SetTraceColor::A' has a wrong offset!");

// Function KuroData.TraceBaseElement.SetTraceHitColor
// 0x0010 (0x0010 - 0x0000)
struct TraceBaseElement_SetTraceHitColor final
{
public:
	float                                         R;                                                 // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         G;                                                 // 0x0004(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         B;                                                 // 0x0008(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         A;                                                 // 0x000C(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(TraceBaseElement_SetTraceHitColor) == 0x000004, "Wrong alignment on TraceBaseElement_SetTraceHitColor");
static_assert(sizeof(TraceBaseElement_SetTraceHitColor) == 0x000010, "Wrong size on TraceBaseElement_SetTraceHitColor");
static_assert(offsetof(TraceBaseElement_SetTraceHitColor, R) == 0x000000, "Member 'TraceBaseElement_SetTraceHitColor::R' has a wrong offset!");
static_assert(offsetof(TraceBaseElement_SetTraceHitColor, G) == 0x000004, "Member 'TraceBaseElement_SetTraceHitColor::G' has a wrong offset!");
static_assert(offsetof(TraceBaseElement_SetTraceHitColor, B) == 0x000008, "Member 'TraceBaseElement_SetTraceHitColor::B' has a wrong offset!");
static_assert(offsetof(TraceBaseElement_SetTraceHitColor, A) == 0x00000C, "Member 'TraceBaseElement_SetTraceHitColor::A' has a wrong offset!");

// Function KuroData.TraceBaseElement.SetTraceTypeQuery
// 0x0001 (0x0001 - 0x0000)
struct TraceBaseElement_SetTraceTypeQuery final
{
public:
	ETraceTypeQuery                               Type;                                              // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(TraceBaseElement_SetTraceTypeQuery) == 0x000001, "Wrong alignment on TraceBaseElement_SetTraceTypeQuery");
static_assert(sizeof(TraceBaseElement_SetTraceTypeQuery) == 0x000001, "Wrong size on TraceBaseElement_SetTraceTypeQuery");
static_assert(offsetof(TraceBaseElement_SetTraceTypeQuery, Type) == 0x000000, "Member 'TraceBaseElement_SetTraceTypeQuery::Type' has a wrong offset!");

// Function KuroData.TraceBoxElement.SetBoxHalfSize
// 0x000C (0x000C - 0x0000)
struct TraceBoxElement_SetBoxHalfSize final
{
public:
	float                                         X;                                                 // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         Y;                                                 // 0x0004(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         Z;                                                 // 0x0008(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(TraceBoxElement_SetBoxHalfSize) == 0x000004, "Wrong alignment on TraceBoxElement_SetBoxHalfSize");
static_assert(sizeof(TraceBoxElement_SetBoxHalfSize) == 0x00000C, "Wrong size on TraceBoxElement_SetBoxHalfSize");
static_assert(offsetof(TraceBoxElement_SetBoxHalfSize, X) == 0x000000, "Member 'TraceBoxElement_SetBoxHalfSize::X' has a wrong offset!");
static_assert(offsetof(TraceBoxElement_SetBoxHalfSize, Y) == 0x000004, "Member 'TraceBoxElement_SetBoxHalfSize::Y' has a wrong offset!");
static_assert(offsetof(TraceBoxElement_SetBoxHalfSize, Z) == 0x000008, "Member 'TraceBoxElement_SetBoxHalfSize::Z' has a wrong offset!");

// Function KuroData.TraceBoxElement.SetBoxOrientation
// 0x000C (0x000C - 0x0000)
struct TraceBoxElement_SetBoxOrientation final
{
public:
	float                                         Pitch;                                             // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         Yaw;                                               // 0x0004(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         Roll;                                              // 0x0008(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(TraceBoxElement_SetBoxOrientation) == 0x000004, "Wrong alignment on TraceBoxElement_SetBoxOrientation");
static_assert(sizeof(TraceBoxElement_SetBoxOrientation) == 0x00000C, "Wrong size on TraceBoxElement_SetBoxOrientation");
static_assert(offsetof(TraceBoxElement_SetBoxOrientation, Pitch) == 0x000000, "Member 'TraceBoxElement_SetBoxOrientation::Pitch' has a wrong offset!");
static_assert(offsetof(TraceBoxElement_SetBoxOrientation, Yaw) == 0x000004, "Member 'TraceBoxElement_SetBoxOrientation::Yaw' has a wrong offset!");
static_assert(offsetof(TraceBoxElement_SetBoxOrientation, Roll) == 0x000008, "Member 'TraceBoxElement_SetBoxOrientation::Roll' has a wrong offset!");

}
