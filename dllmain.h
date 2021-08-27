#ifdef DLLMAIN_EXPORTS
#define DLLMAIN_API __declspec(dllexport)//注意decl前面是两个下划线
#else
#define DLLMAIN_API __declspec(dllimport)
#endif


DLLMAIN_API void injection();
DLLMAIN_API void un_injection();
DLLMAIN_API void main();


// namespace DLLMainSpace
// {

//导出类
//class MyDllClass
// {
// private:
//  double a;
// public:
//导出的函数
//DLLMAIN_API MyDllClass();
//DLLMAIN_API MyDllClass(double a_);
//DLLMAIN_API double multiply(double b);
//DLLMAIN_API void display();
//DLLMAIN_API static void conbine(MyDllClass m1, MyDllClass m2);
//};
// }

BOOL DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved);



