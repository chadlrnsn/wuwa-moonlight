#include "TPSafe.hpp"

void CTPSafe::Draw()
{
    ImGui::Checkbox("TpSafe", &bEnable);
}

void CTPSafe::Run()
{
    if (bEnable /*&& !bOnce*/)
    {
        auto tpsafe = UTpSafeSetting::GetDefaultObj();
        if (tpsafe && tpsafe->Enable == true) 
        {
            tpsafe->Enable = false;
            // bOnce = true;
        }
    }
}

nlohmann::json CTPSafe::Serialize() const
{
        nlohmann::json j = FeatureFactory::Serialize();
        j["tpsafe"] = bEnable;
        return j;
    }

void CTPSafe::Deserialize(const nlohmann::json &json)
 {
    FeatureFactory::Deserialize(json);
    if (json.contains("tpsafe")) bEnable = json["tpsafe"].get<bool>();
}