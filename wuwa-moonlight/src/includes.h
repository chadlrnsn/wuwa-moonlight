#pragma once
#ifndef IMGUI_DEFINE_MATH_OPERATORS
#define IMGUI_DEFINE_MATH_OPERATORS
#endif // IMGUI_DEFINE_MATH_OPERATORS

#include <imgui.h>
#include <iostream>
#include <SDK.hpp>
#include <Minhook.h>
#include <thread>
#include <chrono>
#include <config.h>
#include <logger.h>

using namespace SDK;

using ProcessEvent = void(__thiscall*)(UObject*, UFunction*, void*);
using PostRender = void(__thiscall*)(UGameViewportClient*, UCanvas*);
