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


VOID WINAPI Sleep(   
   __in  DWORD dwMilliseconds   
);
//使用Sleep可以暂停线程的执行


HANDLE WINAPI CreateMutex(
    LPSECURITY_ATTRIBUTES lpMutexAttributes,        //线程安全相关的属性，常置为NULL
    BOOL                  bInitialOwner,            //创建Mutex时的当前线程是否拥有Mutex的所有权
    LPCTSTR               lpName                    //Mutex的名称
);
/*
MutexAttributes:也是表示安全的结构，与CreateThread中的lpThreadAttributes功能相同，
表示决定返回的句柄是否可被子进程继承，如果为NULL则表示返回的句柄不能被子进程继承。

bInitialOwner:表示创建Mutex时的当前线程是否拥有Mutex的所有权，若为TRUE则指定为当
前的创建线程为Mutex对象的所有者，其它线程访问需要先ReleaseMutexlpName:Mutex的名称
*/

DWORD WINAPI WaitForSingleObject(
    HANDLE hHandle,                             //要获取的锁的句柄
    DWORD  dwMilliseconds                           //超时间隔
);

/*
WaitForSingleObject:等待一个指定的对象(如Mutex对象)，直到该对象处于非占用的状态(如Mutex对象被释放)
或超出设定的时间间隔。除此之外，还有一个与它类似的函数WaitForMultipleObjects，它的作用是等待一个
或所有指定的对象，直到所有的对象处于非占用的状态，或超出设定的时间间隔。 

hHandle：要等待的指定对象的句柄。

dwMilliseconds：超时的间隔，以毫秒为单位；如果dwMilliseconds为非0，则等待直到dwMilliseconds时间间隔
用完或对象变为非占用的状态，如果dwMilliseconds 为INFINITE则表示无限等待，直到等待的对象处于非占用的状态。
*/

BOOL WINAPI ReleaseMutex(HANDLE hMutex);

//说明：释放所拥有的互斥量锁对象，hMutex为释放的互斥量句柄

  

