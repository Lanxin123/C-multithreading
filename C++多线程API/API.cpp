HANDLE CreateThread(
    LPSECURITY_ATTRIBUTES lpThreadAttributes,//SD：线程安全相关的属性，常置为NULL
    SIZE_T dwStackSize,//initialstacksize：新线程的初始化栈的大小，可设置为0
    LPTHREAD_START_ROUTINE lpStartAddress,//threadfunction：被线程执行的回调函数，也称为线程函数
    LPVOID lpParameter,//threadargument：传入线程函数的参数，不需传递参数时为NULL
    DWORD dwCreationFlags,//creationoption：控制线程创建的标志
    LPDWORD lpThreadId//threadidentifier：传出参数，用于获得线程ID，如果为NULL则不返回线程ID
    )

/*
lpThreadAttributes：指向SECURITY_ATTRIBUTES结构的指针，决定返回的句柄是否可被子进程继承，如果为NULL则表示返回的句柄不能被子进程继承。

dwStackSize：设置初始栈的大小，以字节为单位，如果为0，那么默认将使用与调用该函数的线程相同的栈空间大小。
任何情况下，Windows根据需要动态延长堆栈的大小。

lpStartAddress：指向线程函数的指针，函数名称没有限制，但是必须以下列形式声明：
DWORD WINAPI 函数名 (LPVOID lpParam) ，格式不正确将无法调用成功。

lpParameter：向线程函数传递的参数，是一个指向结构的指针，不需传递参数时，为NULL。

dwCreationFlags：控制线程创建的标志，可取值如下：
（1）CREATE_SUSPENDED(0x00000004)：创建一个挂起的线程（就绪状态），直到线程被唤醒时才调用
（2）0：表示创建后立即激活。
（3）STACK_SIZE_PARAM_IS_A_RESERVATION(0x00010000)：dwStackSize参数指定初始的保留堆栈的大小，
如果STACK_SIZE_PARAM_IS_A_RESERVATION标志未指定，dwStackSize将会设为系统预留的值

lpThreadId:保存新线程的id

返回值：函数成功，返回线程句柄，否则返回NULL。如果线程创建失败，可通过GetLastError函数获得错误信息。


*/

BOOL WINAPI CloseHandle(HANDLE hObject);        //关闭一个被打开的对象句柄
/*可用这个函数关闭创建的线程句柄，如果函数执行成功则返回true(非0),如果失败则返回false(0)，
如果执行失败可调用GetLastError.函数获得错误信息。
*/


