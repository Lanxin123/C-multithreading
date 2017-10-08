#include "stdafx.h"
#include <windows.h>
#include <iostream>

using namespace std;

DWORD WINAPI StartAddress(LPVOID lpParameter)
{
	cout << "Hello. I am a very simple thread."
		<< endl
		<< "I am used to demonstrate thread creation."
		<< endl;

	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//创建线程。注意，我们只需在相同的代码段中定义StartAddress例程即可。
	//因为主函数负责开始线程和执行并发操作
	HANDLE hThread = CreateThread(NULL, 0, StartAddress, NULL, 0, NULL);

	//创建线程。注意CreateProcess的第一个参数，它指向要从磁盘加载文件。
	STARTUPINFO startupInfo = { 0 };
	PROCESS_INFORMATION processInformation = { 0 };

#ifdef _DEBUG
	BOOL bSuccess = CreateProcess(TEXT("..//Debug//tmpProcess.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo, &processInformation);
#else
	BOOL bSuccess = CreateProcess(TEXT("..//Release//tmpProcess.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo, &processInformation);
#endif

	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);

	return system("pause");
}
