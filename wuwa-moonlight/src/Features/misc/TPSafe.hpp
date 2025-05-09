#pragma once
#include <includes.h>

class CTPSafe : public FeatureFactory
{
private:
    bool bEnable{ true };
public:
    CTPSafe() : FeatureFactory("TPSafe") {}
    
    void Draw();
    void Run();
    
    // Сериализация настроек в JSON
    nlohmann::json Serialize() const;
    
    // Десериализация настроек из JSON
    void Deserialize(const nlohmann::json& json);
};