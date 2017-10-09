HANDLE WINAPI CreateMutex(
	LPSECURITY_ATTRIBUTES	lpMutexAttributes, // 指向安全属性的指针
	BOOL					bInitialOwner, // 初始化互斥对象的所有者
	LPCTSTR					szName // 指向互斥对象名的指针
);
第1个参数是安全特征，可以指定也可以空出不填（如果空出不填，该参数将被设为默认值）。
第2个参数表示所有权，如果把bInitialOwner设置为TRUE，调用方将立即获得互斥量的所有权。
第3个参数指定互斥量的名字，必须提供互斥量名。

HANDLE WINAPI OpenMutex(
DWORD dwDesiredAccess, // access
BOOL bInheritHandle, // inheritance option
LPCTSTR lpName // object name
);
如果互斥量不存在，该例程失败并返回ERROR_FILE_NOT_FOUND。线程操作完毕后，
必须释放互斥量以便让其他线程获取。可以使用ReleaseMutex API释放量。
BOOL WINAPI ReleaseMutex(
	HANDLE hMutex
);
该例程只有一个参数，即之前CreateMutex或OpenMutex返回的互斥量句柄。
HANDLE WINAPI CreateSemaphore(
    LPSECURITY_ATTRIBUTES	lpSemaphoreAttributes, // SD
    LONG					lInitialCount, // initial count
    LONG					lMaximumCount, // maximum count
    LPCTSTR					szName// object name
);
第1个参数是安全特征，可以指定也可以空出不填（如果空出不填，该参数将被设为默认值）。
第2个参数设置初始数目以确定型号领的初始触发状态。如果设置为0，信号量为未触发状态。这个值必须小于第3个参数lMaxmumCount的值。
lMaximumCount表示可同时持有信号量所有权最多对象（线程）数目。
必须提供信号量名（szName）。
HANDLE WINAPI OpenSemaphore(
DWORDdwDesiredAccess, // access
BOOLbInheritHandle, // inheritance option
LPCTSTRlpName // object name
);
如果信号量不存在，该例程将失败并返回NULL。线程操作完毕后，北徐释放信号量以递减计数器技术，
这样其他线程才能获得信号量。
BOOL WINAPI ReleaseSemaphore(
HANDLE hSemaphore,
LONG lReleaseCount,
LPLONG lpPreviousCount
);
第1个参数是之前CreateSemaphore或OpenSemaphore返回的信号量的句柄。
第2个参数是信号量要递减的对象的数量，其值通常是1，因为线程总是逐个被释放的。有一种情况例外：
线程A获得一个信号量，然后要创建也需要信号量的线程B。线程A在线程B创建好之前完成了自己的任务，
线程B不知道它将被将至终止，所以线程A要终止子线程且递减信号量为2。
HANDLE WINAPI CreateEvent(
LPSECURITY_ATTRIBUTES	lpEventAttributes,// 安全属性
BOOL					bManualReset,// 复位方式
BOOL					bInitialState,// 初始状态
LPCTSTR					szName // 对象名称
);

HANDLE WINAPI CreateEventEx(
LPSECURITY_ATTRIBUTES lpEventAttributes,
LPCTSTR				  szName,
DWORD 				  dwFlags,
DWORD                 dwDesiredAccess	
);
对于CreateEvent API,可以指定安全特征，也可以空出不填（如果不填，该参数将被设为默认值）。
bManualReset值用于确定事件对象。如果bManualReset设置为TRUE，则必须把ResetEvent中的事件对象设置为未触发状态。
bInitialState值设置事件的初始状态。如果设置为TRUE,该事件对象则被立即设置为已触发状态。必须提供事件名（szName）。
CreateEventEx与CreateEvent的工作原理几乎相同。这两个API唯一真正的区别是CreateEventEx的dwDesiredAccess参数可以给事件对象设置访问掩码。
HANDLE WINAPI OpenEvent(
DWORD 				dwDesiredAccess,
BOOL				bInheritHandle,
LPCTSTR				szName				
);
如果事件不存在，该例程失败并返回NULL。调用OpenEvent可以让多线程持有相同的时间，但前提是调用CreateEvent或CreateEventEx创建事件。
BOOL WINAPI SetEvent(
HANDLE hEvent
);
SetEvent只有一个参数，即之前用CreateEvent和CreateEventEx创建或由OpenEvent打开的事件对象的句柄。
手动重置事件在调用ResetEvent API显式设置为触发状态之前一直保持已触发状态。
BOOL WINAPI ResetEvent(
HANDLE hEvent
);
ResetEvent也只有一个参数，即之前用CreateEvent和CreateEventEx创建或由OpenEvent打开的事件对象的句柄。
手动重置事件在调用SetEvent API显式设置为触发状态之前一直保持已触发状态。
BOOL WINAPI PulseEvent(
HANDLE hEvent
);
该方法把事件对象设置为已触发状态，然后将其重置为未触发状态，释放特定数量的等待线程。

临界区的使用：
首先先声明临界区对象：
	CRITICAL_SECTION cs;
接着初始化它：
	void WINAPI InitializeCriticalSection(
		LPCRITICAL_SECTION lpCriticalSection
	);
然后，通过调用EnterCriticalSection或TryEnterCriticalSection API让一个线程进入临界区：
	void WINAPI EnterCriticalSection(
		LPCRITICAL_SECTION lpCriticalSection
	);
	BOOL WINAPI TryEnterCiticalSection(
		LPCRITICAL_SECTION lpCriticalSection
	);
线程完成任务后，必须调用LeaveCriticalSection API离开临界区：
	void WINAPI LeaveCriticalSection(
		LPCRITICAL_SECTION lpCriticalSection
	);
接着调用DeleteCriticalSection API释放资源：
	void WINAPI DeleteCriticalSection(
		LPCRITICAL_SECTION lpCriticalSection
	);






















