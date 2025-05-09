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

	structs::MinMax <float>accelSpeed			= {1.0f, 100000.0f, 1000.0f};
	structs::MinMax <float>animSpeed			= { 1.0f, 10.0f, 2.0f };
	// structs::MinMax dilationSpeed		= { 1, 5, 1 };
	structs::MinMax <float>worldSpeed			= { 1.0f, 10.0f, 3.0f };
	structs::MinMax <float>flySpeed			= { 1.0f, 100000.0f, 3.0f };

	// Bindings
	bool bSettingKey{ false };
	KeyBindToggle kbToggle = KeyBindToggle(KeyBind::KeyCode::Z);

	void ResetSpeed();

public:
	SpeedHack() : FeatureFactory("SpeedHack") {}

	void HandleKeys() {
		if (GetAsyncKeyState(kbToggle.toInt()) & 0x1) {
			bEnable = !bEnable;
		}
	}

	void Draw();
	void Run();
	void Call(UObject*, UFunction*, void*);
	
	// Сериализация настроек в JSON
	nlohmann::json Serialize() const override {
	    nlohmann::json j = FeatureFactory::Serialize();
	    
	    // Сохраняем состояния
	    j["character_animation_speed"] = bCharacterAnimationSpeed;
	    j["character_accelerated_speed"] = bCharacterAcceleratedSpeed;
	    j["character_accelerated_fly_speed"] = bCharacterAcceleratedFlySpeed;
	    j["world_dilation"] = bWorldDilation;
	    j["disable_enemy_attack_anim"] = bDisableEnemyAttackAnim;
	    
	    // Сохраняем значения скоростей
	    j["accel_speed"] = {
	        {"min", accelSpeed.Min}, 
	        {"max", accelSpeed.Max}, 
	        {"current", accelSpeed.Current}
	    };
	    
	    j["anim_speed"] = {
	        {"min", animSpeed.Min}, 
	        {"max", animSpeed.Max}, 
	        {"current", animSpeed.Current}
	    };
	    
	    j["world_speed"] = {
	        {"min", worldSpeed.Min}, 
	        {"max", worldSpeed.Max}, 
	        {"current", worldSpeed.Current}
	    };
	    
	    j["fly_speed"] = {
	        {"min", flySpeed.Min}, 
	        {"max", flySpeed.Max}, 
	        {"current", flySpeed.Current}
	    };
	    
	    // Сохраняем биндинг клавиш
	    // j["key_binding"] = static_cast<int>(kbToggle.keyCode);
	    
	    return j;
	}
	
	// Десериализация настроек из JSON
	void Deserialize(const nlohmann::json& json) override {
	    FeatureFactory::Deserialize(json);
	    
	    // Загружаем состояния
	    if (json.contains("character_animation_speed")) 
	        bCharacterAnimationSpeed = json["character_animation_speed"].get<bool>();
	        
	    if (json.contains("character_accelerated_speed")) 
	        bCharacterAcceleratedSpeed = json["character_accelerated_speed"].get<bool>();
	        
	    if (json.contains("character_accelerated_fly_speed")) 
	        bCharacterAcceleratedFlySpeed = json["character_accelerated_fly_speed"].get<bool>();
	        
	    if (json.contains("world_dilation")) 
	        bWorldDilation = json["world_dilation"].get<bool>();
	        
	    if (json.contains("disable_enemy_attack_anim")) 
	        bDisableEnemyAttackAnim = json["disable_enemy_attack_anim"].get<bool>();
	    
	    // Загружаем значения скоростей
	    if (json.contains("accel_speed")) {
	        auto& speed = json["accel_speed"];
	        if (speed.contains("min")) accelSpeed.Min = speed["min"].get<float>();
	        if (speed.contains("max")) accelSpeed.Max = speed["max"].get<float>();
	        if (speed.contains("current")) accelSpeed.Current = speed["current"].get<float>();
	    }
	    
	    if (json.contains("anim_speed")) {
	        auto& speed = json["anim_speed"];
	        if (speed.contains("min")) animSpeed.Min = speed["min"].get<float>();
	        if (speed.contains("max")) animSpeed.Max = speed["max"].get<float>();
	        if (speed.contains("current")) animSpeed.Current = speed["current"].get<float>();
	    }
	    
	    if (json.contains("world_speed")) {
	        auto& speed = json["world_speed"];
	        if (speed.contains("min")) worldSpeed.Min = speed["min"].get<float>();
	        if (speed.contains("max")) worldSpeed.Max = speed["max"].get<float>();
	        if (speed.contains("current")) worldSpeed.Current = speed["current"].get<float>();
	    }
	    
	    if (json.contains("fly_speed")) {
	        auto& speed = json["fly_speed"];
	        if (speed.contains("min")) flySpeed.Min = speed["min"].get<float>();
	        if (speed.contains("max")) flySpeed.Max = speed["max"].get<float>();
	        if (speed.contains("current")) flySpeed.Current = speed["current"].get<float>();
	    }
	    
	    // Загружаем биндинг клавиш
	    if (json.contains("key_binding")) {
	        int keyCode = json["key_binding"].get<int>();
	        kbToggle = KeyBindToggle(static_cast<KeyBind::KeyCode>(keyCode));
	    }
	}
};
