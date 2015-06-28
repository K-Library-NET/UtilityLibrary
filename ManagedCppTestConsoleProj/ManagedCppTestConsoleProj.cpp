// ManagedCppTestConsoleProj.cpp : main project file.

#include "stdafx.h"

using namespace System;


int main(array<System::String ^> ^args)
{
    System::String ^ info = SystemEnv::ComInterop::ComInterop().GetSystemInfo();
	Console::WriteLine(info);
    Console::WriteLine(L"Hello World");
    return 0;
}
