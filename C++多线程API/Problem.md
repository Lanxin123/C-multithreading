CloseHandle()函数的使用？

看到不少程序在创建线程的时候的是这样写的:
ThreadHandle = Create(NULL,0,......);
CloseHandle(ThreadHandle);
刚刚创建就关闭了？

实际上CloseHandle结束的是一个线程句柄，线程和线程句柄不是一个东西，线程是在cpu上运行的。。。线程句柄是一个内核的对象，
我们可以通过句柄来操作线程，但是线程的生命周期和线程句柄的生命周期确是不一样的，线程句柄的生命周期就是线程函数从开始执行到return，
线程的生命周期是从CreateThread返回到CloseThread()。
