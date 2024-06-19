#pragma once
#include <SDK.hpp>

using namespace SDK;

namespace SDKTools::Player {
	bool IsPlayerLoaded(UWorld*);
	bool IsPawnControlled(APawn*);
}