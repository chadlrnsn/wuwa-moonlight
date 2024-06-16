#include "Feature.h"
#include <SDK.hpp>
#include <SDKTools/Player.h>
#include "Bindings.h"

class Fly : Feature
{
private:
	bool Initalized = false;
	bool bFlySwitch = false;
	bool bSettingKey = false;
	bool bUpKey = false;
	bool bDownKey = false;

public:
	bool bEnabled = false;
	float fMaxSpeed = 100.0f;
	float fMinSpeed = 1.0f;
	float fSpeed = 10.0f;
	bool bNoClip = false;
	float fZSpeed = 100.0f;
	float fZSpeedMin = 10.0f;
	float fZSpeedMax = 2000.0f;

	KeyBindToggle kbToggle = KeyBindToggle(KeyBind::KeyCode::F);
	//KeyBind kbUp = KeyBind::isPressed(KeyBind::KeyCode::SPACE);
	//KeyBind kbDown = KeyBindToggle(KeyBind::KeyCode::LCTRL);

private:
	float fOldSpeed = 0.0f;

public:
	Fly() {};

	// Handle setup, like hook creation and variable initalization
	bool Setup() override
	{
		Initalized = true;

		return Initalized;
	};

	// Handle clean up, like restoring hooked functions 
	void Destroy() override
	{
		Initalized = false;
	}

	// Handle checking for any key/hotkey presses or holds needed for features
	void HandleKeys() override 
	{
		if (GetAsyncKeyState(kbToggle.toInt()) & 0x1)
			bEnabled = !bEnabled;

		//if (GetAsyncKeyState(kbUp.toInt()) & 0x1)
		//	bEnabled = !bEnabled;

		//if (GetAsyncKeyState(kbDown.toInt()) & 0x1)
		//	bEnabled = !bEnabled;
	}

	// This should be run in the ImGUI draw loop, used to draw anything to the menu
	void DrawMenuItems() override;

	// This should be run at the top of the ImGUI draw loop, used to render things like ESP, Tracers, and Debug Info
	void Render(void** args, size_t numArgs) override {}

	// This should be run in the feature loop, used to run any acutal feature code like setting a value for godmode
	void Run(void** args, size_t numArgs) override;
};