#pragma once
#include <cstdint>

namespace js {

using NewString_t = void* (*)(void* Isolate, const char* data, int type, int length);

// Глобальные переменные
extern std::uintptr_t NewStringAddress;
extern NewString_t NewString_Origin;
constexpr std::uintptr_t NewStringOffset = 0x528ea30; // Client-Win64-Shipping.exe+0x528ea30

// Хук-функция для перехвата
void* hkEvalScript(void* Isolate, const char* data, int type, int length);

// Инициализация хука
bool EvalScript_Initialize();

// Отключение хука
bool EvalScript_Shutdown();

} // namespace js