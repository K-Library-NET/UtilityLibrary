// TestCppWin32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <atlbase.h>
#include <atlcom.h>
using namespace std;

//REGASM  SystemEnv.dll /tlb SystemEnv.tlh
//REGASM  /u SystemEnv.dll
#import "E:\MyDatas\我的文档\GitHubVisualStudio\UtilityLibrary\TestCppWin32\SystemEnv.tlb" named_guids raw_interfaces_only
//using namespace SystemEnv; 

void _tmain(int argc, _TCHAR* argv[])
{
	HRESULT hr;
	// 初始化COM 
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


	//// 创建智能指针ComInteropDemo::ComInteropInterface 
	//CComPtr<SystemEnv::ComInteropInterface> ptr;

	//// 创建实例  
	//if (SUCCEEDED(ptr.CoCreateInstance(__uuidof(SystemEnv::ComInteropInterface))))
	//{
	//	cout << ptrToString();
	//}

	//int *result; 

	//return 0;
}

