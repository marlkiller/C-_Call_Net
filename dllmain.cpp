// dllmain.cpp : 定义 DLL 应用程序的入口点。
// 属性-高级-公共语言运行时支持  公共语言运行时支持(/clr)
// 属性-C/C++-语言  否
// CSDllMain.dll 的 DLL 要放到目标程序下

#include "pch.h"
#include<windows.h>
#include<iostream>
#include<cstdio>
#include "dllmain.h"
#using "CSDllMain.dll"

using namespace CSDllMain;


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{

    switch (ul_reason_for_call)
    {
    // DLL_PROCESS_ATTACH: 进程第一次加载时通知
    case DLL_PROCESS_ATTACH:
        injection_net();
        break;
    // DLL_THREAD_ATTACH: 新线程创建时通知
    case DLL_THREAD_ATTACH:
        break;

    // DLL_THREAD_DETACH: 线程消亡时通知
    case DLL_THREAD_DETACH:
        break;

    // DLL_PROCESS_DETACH: 进程卸载dll时通知 
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

void injection_net() {
    MessageBox(NULL, TEXT("C++ DLL Injection Successful"), TEXT("Title"), MB_OK);
    Class1^ testClass = gcnew Class1();
    testClass->hook();
}

