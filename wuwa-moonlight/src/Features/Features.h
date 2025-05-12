#pragma once
#include <Features/misc/FpsUnlock.hpp>
#include <Features/combat/MultiHit.h>
#include <Features/visuals/ESP.hpp>
#include <Features/movement/SpeedHack.h>
#include <Features/movement/Fly.hpp>
#include <Features/misc/TPSafe.hpp>

// Debug stuff
#include <gui/components/Debug.hpp>

// Создаем все фичи с использованием общего интерфейса
inline auto fpsUnlock   = std::make_shared<FpsUnlock>();
inline auto esp         = std::make_shared<ESP>();
inline auto speedhack   = std::make_shared<SpeedHack>();
inline auto multihit    = std::make_shared<HitMultiplier>();
inline auto fly         = std::make_shared<Fly>();
inline auto ptpsafe     = std::make_shared<CTPSafe>();

// Debug stuff
inline auto debugComponent = std::make_shared<CheatDebugComponent>();
