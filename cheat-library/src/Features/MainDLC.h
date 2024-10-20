#pragma once
//#include "Bindings.h"
#include "imgui.h"

class DLC {
protected:
	bool m_bOnce = false;
	bool m_bActive = false;


public:
    virtual void Run() {};
    virtual void Toggle() {};
    virtual void KeyHandle() {};
    virtual void DrawMenuItems() {};

	virtual ~DLC() = default;
};