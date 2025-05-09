#pragma once
#include <includes.h>
#include "SDK.hpp"
#include <globals.h>
#include "TsAnimNotifyReSkillEvent_parameters.hpp"

class HitMultiplier : public FeatureFactory
{
private:
    bool m_bBlockEnemyHit{ true };
    structs::MinMax <int>hits = { 1, 100, 10 };
    
public:
    HitMultiplier() : FeatureFactory("HitMultiplier") {}
    
    void Call(UObject* Object, UFunction* Function, void* Parms);
    void Draw();
    
    // Сериализация настроек в JSON
    nlohmann::json Serialize() const override {
        nlohmann::json j = FeatureFactory::Serialize();
        
        j["block_enemy_hit"] = m_bBlockEnemyHit;
        j["hits"] = hits.Current;
        j["min_hits"] = hits.Min;
        j["max_hits"] = hits.Max;
        
        return j;
    }
    
    // Десериализация настроек из JSON
    void Deserialize(const nlohmann::json& json) override {
        FeatureFactory::Deserialize(json);
        
        if (json.contains("block_enemy_hit"))
            m_bBlockEnemyHit = json["block_enemy_hit"].get<bool>();
            
        if (json.contains("hits"))
            hits.Current = json["hits"].get<int>();
            
        if (json.contains("min_hits"))
            hits.Min = json["min_hits"].get<int>();
            
        if (json.contains("max_hits"))
            hits.Max = json["max_hits"].get<int>();
    }
};



inline void HitMultiplier::Draw() {
    ImGui::Checkbox("Attack Modifier", &bEnable);
    ImGui::SameLine();
    ImGui::WarningTooltip("is the character's attack modifier (don't set it over 20 otherwise there is a high risk of being banned)");

    ImGui::Checkbox("Block enemy hit", &m_bBlockEnemyHit);
    ImGui::SameLine();
    ImGui::Tooltip("I'm really don't know how it works (not tested)");

    ImGui::BeginDisabled(!bEnable);
    {
        ImGui::Text("Hit multiplier");
        ImGui::SliderInt("##Hit multiplier", &hits.Current, hits.Min, hits.Max);
    }
    ImGui::EndDisabled();
}

inline void HitMultiplier::Call(UObject* Object, UFunction* Function, void* Parms) {
    // Check if the function is enabled
    if (!bEnable) {
        return;
    }

    if (Function->Index != globals::FN_TsAnimNotifyReSkillEvent_C) {
        return;
    }

    // Get parameters and check their validity
    auto parameters = static_cast<SDK::Params::TsAnimNotifyReSkillEvent_C_K2_Notify*>(Parms);
    if (!parameters) {
        return;
    }

    USkeletalMeshComponent* meshComp = parameters->MeshComp;
    if (!meshComp) {
        return;
    }

    AActor* owner = meshComp->GetOwner();
    
    // Check if the action belongs to our character or an enemy
    if (owner == globals::pawn) {
        for (int i = 1; i < hits.Current; ++i) {
            globals::oProcessEvent(Object, Function, Parms);
        }
        
        LOG_INFO("MultiHit: executed %d additional hits", hits.Current - 1);
        return; // Return as hits have already been executed
    }
    else if (m_bBlockEnemyHit && owner != globals::pawn) {
        // If enemy attack blocking is enabled and the attacker is not the player
        // LOG_INFO("Enemy attack blocked");
        return; // Don't call the original function, blocking the attack
    }
    
    // Do not call globals::oProcessEvent at the end of the function, 
    // cuz this is will be in hooked func (hkProcessEvent)
}
