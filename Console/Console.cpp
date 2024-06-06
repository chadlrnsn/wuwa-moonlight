//#include "pch.h"
#include "Console.hpp"

void Console::Initalize()
{
    if (this->bInitalized)
        return;

    if (this->stdoutDummy == nullptr || this->stdinDummy == nullptr)
        this->Alloc();

    this->bInitalized = true;
}

Console& Console::Instance()
{
    static Console _Instance;

    if (!_Instance.bInitalized)
        _Instance.Initalize();

    return _Instance;
}

Console& Console::Instance(bool bVisibility)
{
    static Console _Instance;

    if (!_Instance.bInitalized)
        _Instance.Initalize();

    _Instance.SetVisibility(bVisibility);

    return _Instance;
}

bool Console::Alloc()
{
    if (this->bAllocated)
    {
        std::cout << "Console already allocated!\n";
        return true;
    }

    if (!AllocConsole()) {
        std::cout << "AllocConsole() Error: " << GetLastError() << std::endl;
        return false;
    }

    freopen_s(&stdoutDummy, "CONOUT$", "w", stdout);
    freopen_s(&stdinDummy, "CONIN$", "r", stdin);
    std::cout.clear();
    std::cin.clear();

    this->bAllocated = true;
    return true;
}

bool Console::Free()
{
    if (!this->bAllocated)
    {
        std::cout << "No console allocated!\n";
        return false;
    }

    if (stdoutDummy)
        fclose(stdoutDummy);
    if (stdinDummy)
        fclose(stdinDummy);

    if (!FreeConsole())
    {
        std::cout << "FreeConsole() Error: " << GetLastError() << std::endl;
        return false;
    }

    this->bAllocated = false;
    return true;
}

void Console::SetVisibility(bool bVisibility)
{
    this->bVisible = bVisibility;
    ShowWindow(GetConsoleWindow(), (bVisibility) ? SW_SHOW : SW_HIDE);
    return;
}

void Console::ToggleVisibility()
{
    SetVisibility(!this->bVisible);
    return;
}

void Console::Close()
{
    CloseWindow(GetConsoleWindow());
    return;
}