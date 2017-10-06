#include <iostream>   
#include <windows.h>   
using namespace std;

DWORD WINAPI Fun(LPVOID lpParamter)
{
    for (int i = 0; i < 10; i++)
        cout << "A Thread Fun Display!" << endl;
    return 0L;
}

int main()
{
    HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
    CloseHandle(hThread);
    for (int i = 0; i < 10; i++)//把10修改成6或更小的数字会使主线程运行后所占资源都释放掉，子线程还没有运行完。（具体和电脑性能有关）
        cout << "Main Thread Display!" << endl;
    return 0;
}