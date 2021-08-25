// dllmain.cpp : 定义 DLL 应用程序的入口点。
// 属性-高级-公共语言运行时支持  公共语言运行时支持(/clr)
// 属性-C/C++-语言  符合格式 否
// CSDllMain.dll 的 DLL 要放到目标程序下

#include "pch.h"
#include<windows.h>
#include<iostream>
#include<cstdio>
#include <gcroot.h>
#include "dllmain.h"
#using "CSDllMain.dll"

using namespace CSDllMain;


//gcroot<Class1^> testClass;


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                       )
{

    switch (ul_reason_for_call)
    {
        // DLL_PROCESS_ATTACH: 进程第一次加载时通知
        case DLL_PROCESS_ATTACH:
            // CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)main, hModule, 0, NULL);
            injection();
            break;
        // DLL_THREAD_ATTACH: 新线程创建时通知
        case DLL_THREAD_ATTACH:
            break;

        // DLL_THREAD_DETACH: 线程消亡时通知
        case DLL_THREAD_DETACH:
            break;

        // DLL_PROCESS_DETACH: 进程卸载dll时通知
        case DLL_PROCESS_DETACH:
            un_injection();
            break;
    }
    return TRUE;
}

void main()
{
//    MessageBox(NULL, TEXT("C++ DLL Injection Successful"), TEXT("Title"), MB_OK);
//    testClass = gcnew Class1();
//    testClass->hook();
}

void injection()
{
    MessageBox(NULL, TEXT("C++ DLL Injection Successful"), TEXT("Title"), MB_OK);
    Class1^ testClass = gcnew Class1();
    testClass = gcnew Class1();
    testClass->hook();
}

void un_injection()
{
    MessageBox(NULL, TEXT("C++ DLL Un_injection Successful"), TEXT("Title"), MB_OK);
}