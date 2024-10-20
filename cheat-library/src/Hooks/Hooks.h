#pragma once

namespace Hooks {
	void hkACE_BypassSetup();
	void hkACE_BypassCleanup();
	void AntiDebug();
	void RemoveHooks();

	namespace InGame {
		void PostRender();
		void ProcessEvent();
		void Initialize();
	}
}