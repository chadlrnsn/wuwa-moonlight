#include "../Helper.h"
#include "../Console/Console.hpp"
#include "../Globals.h"

typedef int(__cdecl* MYPROC)(LPWSTR);
using namespace Globals;

Helper p;
bool unload_dll(LPCSTR name) {
	//HINSTANCE hinstLib;
	//BOOL fFreeResult;

	//// Get a handle to the DLL module.
	//hinstLib = LoadLibrary(TEXT("wuwa-moonlight.dll"));    //1: load the DLL

	//// If the handle is valid, unload the DLL
	//if (hinstLib != NULL)
	//{
	//	fFreeResult = FreeLibrary(hinstLib);      //2: unload the DLL
	//}

	g_ShouldThreadClose = true;

	if (con && con->IsAllocated()) {
		con->Free();
	}

	return false;
}