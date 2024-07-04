#include "Feature.h"
using namespace SDK;

namespace DebugMenu
{
	void DebugMainPage();
}

extern void PostRenderHook(UObject* _this, UObject* canvas);
extern void ProcessEventHook(UObject* caller, UObject* fn, void* params);
extern BYTE* vmt_hook(void** VTable, int32 index, void* fn);

