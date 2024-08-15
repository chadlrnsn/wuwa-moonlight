#pragma once

#include <iostream>
#include <SDK.hpp>
#include <minhook/include/MinHook.h>
#include <thread>
#include <chrono>
#include <config.h>

using namespace SDK;

using ProcessEvent = void(__thiscall*)(UObject*, UFunction*, void*);
using PostRender = void(__thiscall*)(UGameViewportClient*, UCanvas*);
