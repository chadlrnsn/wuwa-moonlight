#pragma once
#include <Windows.h>
#include <iostream>

class Console
{
private:
	FILE* stdoutDummy = nullptr;
	FILE* stdinDummy = nullptr;
	bool bAllocated = FALSE;
	bool bInitalized = false;
	bool bVisible = true;
	void Initalize();
	Console() {};

public:
	static Console& Instance();
	static Console& Instance(bool bVisibility);
	bool Alloc();
	bool Free();
	void SetVisibility(bool bVisibility);
	void ToggleVisibility();
	void Close();
	bool GetVisibility() { return this->bVisible; };
	void SetTitle(std::string title) { SetConsoleTitleA(title.c_str()); };
	bool IsAllocated() { return this->bAllocated; };
};