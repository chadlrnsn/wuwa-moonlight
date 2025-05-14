#pragma once

#include <includes.h>
#include <globals.h>

class CView : public FeatureFactory
{
private:
    bool bFOV{ false };
    bool bAspectRatio{ false };
    bool bAspectRatioConstraint{ false };
    structs::MinMax <float>AspectRatio = { 0.01f, 5.0f, 2.0f };
    structs::MinMax <float>FOV = { 0.01f, 150.0f, 75.0f };

public:
    void Run();
    void Draw();
};
