#pragma once
#include "../imgui/imgui.h"

class Feature
{
private:
	bool Initalized = false;

public:
	Feature() {};

	// Handle setup, like hook creation and variable initalization
	virtual bool Setup() = 0;

	// Handle clean up, like restoring hooked functions 
	virtual void Destroy() = 0;

	// Handle checking for any key/hotkey presses or holds needed for features
	virtual void HandleKeys() = 0;

	// This should be run in the ImGUI draw loop, used to draw anything to the menu
	virtual void DrawMenuItems() = 0;

	// This should be run at the top of the ImGUI draw loop, used to render things like ESP, Tracers, and Debug Info
	virtual void Render(void** args, size_t numArgs) = 0;

	// This should be run in the feature loop, used to run any acutal feature code like setting a value for godmode
	virtual void Run(void** args, size_t numArgs) = 0;
};