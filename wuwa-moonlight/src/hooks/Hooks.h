#pragma once
#include <iostream>	
#include <Windows.h>
#include <MinHook.h>
#include <xorstr.hpp>
#include "debug/debugger.hpp"
namespace Hooks {
	namespace InGame {
		void PostRender();
		void ProcessEvent();
		void Initialize();
		void Uninitialize();
	}
	void Uninitialize();
}