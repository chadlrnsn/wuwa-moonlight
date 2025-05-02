#pragma once
#include <includes.h>

class CTPSafe : public FeatureFactory
{
private:
    bool m_bTpsafe { true };
public:
    void Draw() override;
    void Run() override;

};