#pragma once
#include <includes.h> 
#include <globals.h>

class CheatDebugComponent : public FeatureFactory
{
public:
    CheatDebugComponent() : FeatureFactory("DebugComponent") {}
    
    void Draw();

    // Сериализация настроек в JSON
    // nlohmann::json Serialize() const {
    //     nlohmann::json j = FeatureFactory::Serialize();
    //     return j; // Нет дополнительных настроек для сохранения
    // }
    
    // // Десериализация настроек из JSON
    // void Deserialize(const nlohmann::json& json) {
    //     FeatureFactory::Deserialize(json);
    //     // Нет дополнительных настроек для загрузки
    // }
};