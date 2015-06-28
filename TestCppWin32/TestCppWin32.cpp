// TestCppWin32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#pragma once 
//REGASM  SystemEnv.dll /tlb SystemEnv.tlh
//REGASM  /u SystemEnv.dll
#import "SystemEnv.tlh"
//using namespace SystemEnv;
#pragma managed 

int _tmain(int argc, _TCHAR* argv[])
{
	HRESULT hr;
	// ��ʼ��COM 
	CoInitialize(NULL);
	// ��������ָ��ComInteropDemo::ComInteropInterface 
	SystemEnv::ComInterop ptr;

	// ����ʵ�� 
	hr = ptr.CreateInstance(__uuidof (SystemEnv::ComInterop));

	if (hr == S_OK)
	{
 		cout << ptr -> ToString();
	}

	CoUninitialize();

	return 0;
}

