#pragma once
#include <includes.h>
#include <globals.h>
#include "TsAnimNotifyReSkillEvent_parameters.hpp"
#include <Features/Bindings.h>

using namespace globals;

using namespace SDK;
using tProcessEvent = void(__thiscall*)(UObject*, UFunction*, void*);

class SpeedHack : public FeatureFactory
{
private:
	// bool bCharacterSpeed{ false }; 

	/**
	 * KuroGames fixed this method with editing CustomSpeed lol :D
	 * maybe I'll fix it later 
	 */
					
	bool bCharacterAnimationSpeed{ false };
	bool bCharacterAcceleratedSpeed{ false };
	bool bCharacterAcceleratedFlySpeed{ false };
	bool bWorldDilation{ false };
	bool bDisableEnemyAttackAnim{ true };

	structs::MinMax accelSpeed			= {1.0f, 100000.0f, 1000.0f};
	structs::MinMax animSpeed			= { 1.0f, 10.0f, 2.0f };
	// structs::MinMax dilationSpeed		= { 1, 5, 1 };
	structs::MinMax worldSpeed			= { 1.0f, 10.0f, 3.0f };
	structs::MinMax flySpeed			= { 1.0f, 100000.0f, 3.0f };

	// Bindings
	bool bSettingKey{ false };
	KeyBindToggle kbToggle = KeyBindToggle(KeyBind::KeyCode::Z);

	void ResetSpeed();

public:
	void HandleKeys() {
		if (GetAsyncKeyState(kbToggle.toInt()) & 0x1) {
			bEnable = !bEnable;
		}
	}

	void Draw();
	void Run();
	void Call(UObject*, UFunction*, void*);
};
