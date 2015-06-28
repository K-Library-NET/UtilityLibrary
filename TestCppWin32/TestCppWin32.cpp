// TestCppWin32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <atlbase.h>
#include <atlcom.h>
using namespace std;

//REGASM  SystemEnv.dll /tlb SystemEnv.tlh
//REGASM  /u SystemEnv.dll
#import "E:\MyDatas\�ҵ��ĵ�\GitHubVisualStudio\UtilityLibrary\TestCppWin32\SystemEnv.tlb" named_guids raw_interfaces_only
//using namespace SystemEnv; 

void _tmain(int argc, _TCHAR* argv[])
{
	HRESULT hr;
	// ��ʼ��COM 
	CoInitialize(NULL);

	//// <namespace>::<InterfaceName>
	SystemEnv::ComInteropInterfacePtr pDotNetCOMPtr;

	// CreateInstance parameters
	// e.g. CreateInstance (<namespace::CLSID_<ClassName>)
	HRESULT hRes = pDotNetCOMPtr.CreateInstance(__uuidof(SystemEnv::ComInterop));
	if (hRes == S_OK)
	{
		BSTR str;
		pDotNetCOMPtr -> GetSystemInfo(&str);
		std::cout << str;
		//call .NET COM exported function ShowDialog ()
	}


	//// ��������ָ��ComInteropDemo::ComInteropInterface 
	//CComPtr<SystemEnv::ComInteropInterface> ptr;

	//// ����ʵ��  
	//if (SUCCEEDED(ptr.CoCreateInstance(__uuidof(SystemEnv::ComInteropInterface))))
	//{
	//	cout << ptrToString();
	//}

	//int *result; 

	//return 0;
}

