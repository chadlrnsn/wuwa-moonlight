#pragma once
#include <SDK.hpp>

using namespace SDK;

namespace ue4
{
    inline void UE_RenderText(
        UCanvas *canvas,
        UFont *font,
        FString text,
        FVector2D Position = {0, 0},
        FVector2D Scale = {1, 1},
        FLinearColor color = {1, 1, 1, 1})
    {
        canvas->K2_DrawText(
            font,
            text,
            Position,
            Scale, // text offset
            color, // Text color
            false,
            FLinearColor({0, 0, 0, 1}), // Shadow color
            FVector2D({0, 0}),          // Shadow offset
            false,
            false,
            false,
            FLinearColor({0, 0, 0, 1}));
    }

    inline void UE_RenderTextEx(
        UCanvas *canvas,
        UFont *font,
        FString text,
        FVector2D Position = {0, 0},
        FVector2D Scale = {1, 1},
        FLinearColor color = {1, 1, 1, 1},
        bool centeredX = false,
        bool centeredY = false,
        bool outline = false,
        FLinearColor outlineColor = {0, 0, 0, 1})
    {
        canvas->K2_DrawText(
            font,
            text,
            Position,
            Scale, // text offset
            color, // Text color
            false,
            FLinearColor({0, 0, 0, 1}), // Shadow color
            FVector2D({0, 0}),          // Shadow offset
            centeredX,
            centeredY,
            outline,
            outlineColor);
    }
}
