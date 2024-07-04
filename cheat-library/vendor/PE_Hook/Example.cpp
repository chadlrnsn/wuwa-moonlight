#include "PE_Hook.hpp"

//
// https://docs.unrealengine.com/4.27/en-US/API/Runtime/CoreUObject/UObject/UObject/ProcessEvent/
//
typedef void(__fastcall* tProcessEvent)(void* Class, void* Function, void* Parms);
static tProcessEvent hkProcessEvent = nullptr;

void HookedProcessEvent(void* Class, void* Function, void* Parms)
{
	std::printf("[#] Hello From ProcessEvent");

	return hkProcessEvent(Class, Function, Parms);
}

//
// ARK: Survival Evolved (UE4) Example
//
int main()
{
	auto module_base = GetModuleHandleA(NULL);

#define GWorld 0x4633498

	auto world = *reinterpret_cast<std::uintptr_t*>(module_base + GWorld);

	//
	// Must Be Static
	//
	static auto world_peh = Hook::ProcessEventHook(world);

	//
	// Call This Every Tick/Loop/Frame
	//
	world_peh.ApplyHook(world, (std::uintptr_t)hkProcessEvent, (std::uintptr_t)HookedProcessEvent);
}