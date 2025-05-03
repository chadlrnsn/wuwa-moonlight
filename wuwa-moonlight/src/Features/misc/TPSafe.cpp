#include "TPSafe.hpp"

void CTPSafe::Draw()
{
    ImGui::Checkbox("TpSafe", &m_bTpsafe);
}

void CTPSafe::Run()
{
    if (m_bTpsafe && !bOnce)
    {
        auto tpsafe = UTpSafeSetting::GetDefaultObj();
        if (tpsafe) 
        {
            tpsafe->Enable = false;
            bOnce = true;
        }
    }
}
