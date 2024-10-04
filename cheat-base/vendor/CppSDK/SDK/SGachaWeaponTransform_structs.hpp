#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SGachaWeaponTransform

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"


namespace SDK
{

// UserDefinedStruct SGachaWeaponTransform.SGachaWeaponTransform
// 0x003C (0x003C - 0x0000)
struct FSGachaWeaponTransform final
{
public:
	struct FVector                                Location_5_062EBDC048E48DFEF7F51A99A28E17D1;       // 0x0000(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                Rotation_7_4BA6364547B6DB171AE76DACB3FC7A09;       // 0x000C(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Size_19_1B8527E14B1D2CBC5304EEB401392CDB;          // 0x0018(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         RotateTime_20_75342653428D0F5597D2E5A666EE8135;    // 0x001C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                ScabbardOffset_15_5F50836146517CF7BAC23991551C5FC8; // 0x0020(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          ShowScabbard_18_CC76FA0D470815831819D2ADE0753C02;  // 0x002C(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2D[0x3];                                       // 0x002D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                AxisRotate_23_F5685CB54AFAA73871EA94B73BB81539;    // 0x0030(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(FSGachaWeaponTransform) == 0x000004, "Wrong alignment on FSGachaWeaponTransform");
static_assert(sizeof(FSGachaWeaponTransform) == 0x00003C, "Wrong size on FSGachaWeaponTransform");
static_assert(offsetof(FSGachaWeaponTransform, Location_5_062EBDC048E48DFEF7F51A99A28E17D1) == 0x000000, "Member 'FSGachaWeaponTransform::Location_5_062EBDC048E48DFEF7F51A99A28E17D1' has a wrong offset!");
static_assert(offsetof(FSGachaWeaponTransform, Rotation_7_4BA6364547B6DB171AE76DACB3FC7A09) == 0x00000C, "Member 'FSGachaWeaponTransform::Rotation_7_4BA6364547B6DB171AE76DACB3FC7A09' has a wrong offset!");
static_assert(offsetof(FSGachaWeaponTransform, Size_19_1B8527E14B1D2CBC5304EEB401392CDB) == 0x000018, "Member 'FSGachaWeaponTransform::Size_19_1B8527E14B1D2CBC5304EEB401392CDB' has a wrong offset!");
static_assert(offsetof(FSGachaWeaponTransform, RotateTime_20_75342653428D0F5597D2E5A666EE8135) == 0x00001C, "Member 'FSGachaWeaponTransform::RotateTime_20_75342653428D0F5597D2E5A666EE8135' has a wrong offset!");
static_assert(offsetof(FSGachaWeaponTransform, ScabbardOffset_15_5F50836146517CF7BAC23991551C5FC8) == 0x000020, "Member 'FSGachaWeaponTransform::ScabbardOffset_15_5F50836146517CF7BAC23991551C5FC8' has a wrong offset!");
static_assert(offsetof(FSGachaWeaponTransform, ShowScabbard_18_CC76FA0D470815831819D2ADE0753C02) == 0x00002C, "Member 'FSGachaWeaponTransform::ShowScabbard_18_CC76FA0D470815831819D2ADE0753C02' has a wrong offset!");
static_assert(offsetof(FSGachaWeaponTransform, AxisRotate_23_F5685CB54AFAA73871EA94B73BB81539) == 0x000030, "Member 'FSGachaWeaponTransform::AxisRotate_23_F5685CB54AFAA73871EA94B73BB81539' has a wrong offset!");

}
