#pragma once
#include <Features/misc/FpsUnlock.hpp>
#include <Features/combat/MultiHit.h>
#include <Features/visuals/ESP.hpp>
#include <Features/movement/SpeedHack.h>
#include <Features/movement/Fly.h>
#include <Features/misc/TPSafe.hpp>

// Debug stuff
#include <gui/components/Debug.hpp>

inline auto fpsUnlock   = std::make_unique<FpsUnlock>();
inline auto esp         = std::make_unique<ESP>();
inline auto speedhack   = std::make_unique<SpeedHack>();
inline auto multihit    = std::make_unique<HitMultiplier>();
inline auto fly         = std::make_unique<Fly>();
inline auto ptpsafe     = std::make_unique<CTPSafe>();

// Debug stuff
inline auto debugComponent = std::make_unique<CheatDebugComponent>();
