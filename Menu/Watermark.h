#pragma once
#include "../imgui/imgui.h"
#include <iostream>
#include "Menu.hpp"
#include <thread>


class WM
{
private:
	bool enabled = true;

public:
	void Watermark();
	bool ISWM_Enabled();

};