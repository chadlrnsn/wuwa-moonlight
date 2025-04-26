#pragma once
#include <Features/misc/FpsUnlock.hpp>
#include <Features/combat/MultiHit.h>
#include <Features/visuals/ESP.hpp>

inline std::unique_ptr<FpsUnlock> fpsUnlock = std::make_unique<FpsUnlock>();
inline std::unique_ptr<ESP> esp = std::make_unique<ESP>();