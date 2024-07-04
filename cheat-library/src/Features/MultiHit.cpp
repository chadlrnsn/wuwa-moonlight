#include "MultiHit.h"
#include "PE_Hook/vmthook.h"
#define HOOK_INDEX 0x49

using ProcessEvent = void(__thiscall*)(UObject*, UFunction*, void*);
static ProcessEvent ProcessEventOriginal = nullptr;


void __stdcall ProcessEventHooked(UObject* object, UFunction* function, void* parms) {
	printf("ProcessEvent Function Called\n");

    ProcessEventOriginal(object, function, parms);

	return ProcessEventOriginal(object, function, parms);
}

UGameViewportClient* getViewport(UWorld* world) noexcept {
	return world->OwningGameInstance->LocalPlayers[0]->ViewportClient;
}


void HitMultiplier::DrawMenuItems()
{
	ImGui::Checkbox("Multi Hit", &bEnable);
	if (bEnable) {
		ImGui::BeginChild(2, ImVec2(0,100), 1);
			ImGui::Text("Hit multiplier");
			ImGui::SliderInt("##Hit multiplier", &iCurrent, iMin, iMax);
		ImGui::EndChild();
	}
}


std::unique_ptr<CVMTHook> g_processEventHook;

void HitMultiplier::Run(void** args, size_t numArgs) {
    if (!Initalized || numArgs != 1) {
        Destroy();
        return;
    }

    APawn* Pawn = (APawn*)args[0];
    UWorld* World = (UWorld*)args[1];

    if (bEnable) {
        UGameViewportClient* viewport = getViewport(World);
        UObject* VTableClass = viewport->FindObject("Function TsAnimNotifyReSkillEvent.TsAnimNotifyReSkillEvent_C.K2_Notify");
        
        if (!g_processEventHook) {
            g_processEventHook = std::make_unique<CVMTHook>(VTableClass);
            ProcessEventOriginal = reinterpret_cast<ProcessEvent>(
                g_processEventHook->HookMethod(reinterpret_cast<void*>(&ProcessEventHooked), HOOK_INDEX)
                );


            printf("Hook created successfully. o: [0x%p]\n", ProcessEventOriginal);
        }
    } 
    else 
    {
        if (g_processEventHook) {
            g_processEventHook->RestoreTable();
            g_processEventHook.reset();
        }
    }
}
