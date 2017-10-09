HANDLE WINAPI CreateMutex(
	LPSECURITY_ATTRIBUTES	lpMutexAttributes, // ָ��ȫ���Ե�ָ��
	BOOL					bInitialOwner, // ��ʼ����������������
	LPCTSTR					szName // ָ�򻥳��������ָ��
);
��1�������ǰ�ȫ����������ָ��Ҳ���Կճ��������ճ�����ò���������ΪĬ��ֵ����
��2��������ʾ����Ȩ�������bInitialOwner����ΪTRUE�����÷���������û�����������Ȩ��
��3������ָ�������������֣������ṩ����������

HANDLE WINAPI OpenMutex(
DWORD dwDesiredAccess, // access
BOOL bInheritHandle, // inheritance option
LPCTSTR lpName // object name
);
��������������ڣ�������ʧ�ܲ�����ERROR_FILE_NOT_FOUND���̲߳�����Ϻ�
�����ͷŻ������Ա��������̻߳�ȡ������ʹ��ReleaseMutex API�ͷ�����
BOOL WINAPI ReleaseMutex(
	HANDLE hMutex
);
������ֻ��һ����������֮ǰCreateMutex��OpenMutex���صĻ����������
HANDLE WINAPI CreateSemaphore(
    LPSECURITY_ATTRIBUTES	lpSemaphoreAttributes, // SD
    LONG					lInitialCount, // initial count
    LONG					lMaximumCount, // maximum count
    LPCTSTR					szName// object name
);
��1�������ǰ�ȫ����������ָ��Ҳ���Կճ��������ճ�����ò���������ΪĬ��ֵ����
��2���������ó�ʼ��Ŀ��ȷ���ͺ���ĳ�ʼ����״̬���������Ϊ0���ź���Ϊδ����״̬�����ֵ����С�ڵ�3������lMaxmumCount��ֵ��
lMaximumCount��ʾ��ͬʱ�����ź�������Ȩ�������̣߳���Ŀ��
�����ṩ�ź�������szName����
HANDLE WINAPI OpenSemaphore(
DWORDdwDesiredAccess, // access
BOOLbInheritHandle, // inheritance option
LPCTSTRlpName // object name
);
����ź��������ڣ������̽�ʧ�ܲ�����NULL���̲߳�����Ϻ󣬱����ͷ��ź����Եݼ�������������
���������̲߳��ܻ���ź�����
BOOL WINAPI ReleaseSemaphore(
HANDLE hSemaphore,
LONG lReleaseCount,
LPLONG lpPreviousCount
);
��1��������֮ǰCreateSemaphore��OpenSemaphore���ص��ź����ľ����
��2���������ź���Ҫ�ݼ��Ķ������������ֵͨ����1����Ϊ�߳�����������ͷŵġ���һ��������⣺
�߳�A���һ���ź�����Ȼ��Ҫ����Ҳ��Ҫ�ź������߳�B���߳�A���߳�B������֮ǰ������Լ�������
�߳�B��֪��������������ֹ�������߳�AҪ��ֹ���߳��ҵݼ��ź���Ϊ2��
HANDLE WINAPI CreateEvent(
LPSECURITY_ATTRIBUTES	lpEventAttributes,// ��ȫ����
BOOL					bManualReset,// ��λ��ʽ
BOOL					bInitialState,// ��ʼ״̬
LPCTSTR					szName // ��������
);

HANDLE WINAPI CreateEventEx(
LPSECURITY_ATTRIBUTES lpEventAttributes,
LPCTSTR				  szName,
DWORD 				  dwFlags,
DWORD                 dwDesiredAccess	
);
����CreateEvent API,����ָ����ȫ������Ҳ���Կճ�����������ò���������ΪĬ��ֵ����
bManualResetֵ����ȷ���¼��������bManualReset����ΪTRUE��������ResetEvent�е��¼���������Ϊδ����״̬��
bInitialStateֵ�����¼��ĳ�ʼ״̬���������ΪTRUE,���¼���������������Ϊ�Ѵ���״̬�������ṩ�¼�����szName����
CreateEventEx��CreateEvent�Ĺ���ԭ������ͬ��������APIΨһ������������CreateEventEx��dwDesiredAccess�������Ը��¼��������÷������롣
HANDLE WINAPI OpenEvent(
DWORD 				dwDesiredAccess,
BOOL				bInheritHandle,
LPCTSTR				szName				
);
����¼������ڣ�������ʧ�ܲ�����NULL������OpenEvent�����ö��̳߳�����ͬ��ʱ�䣬��ǰ���ǵ���CreateEvent��CreateEventEx�����¼���
BOOL WINAPI SetEvent(
HANDLE hEvent
);
SetEventֻ��һ����������֮ǰ��CreateEvent��CreateEventEx��������OpenEvent�򿪵��¼�����ľ����
�ֶ������¼��ڵ���ResetEvent API��ʽ����Ϊ����״̬֮ǰһֱ�����Ѵ���״̬��
BOOL WINAPI ResetEvent(
HANDLE hEvent
);
ResetEventҲֻ��һ����������֮ǰ��CreateEvent��CreateEventEx��������OpenEvent�򿪵��¼�����ľ����
�ֶ������¼��ڵ���SetEvent API��ʽ����Ϊ����״̬֮ǰһֱ�����Ѵ���״̬��
BOOL WINAPI PulseEvent(
HANDLE hEvent
);
�÷������¼���������Ϊ�Ѵ���״̬��Ȼ��������Ϊδ����״̬���ͷ��ض������ĵȴ��̡߳�

�ٽ�����ʹ�ã�
�����������ٽ�������
	CRITICAL_SECTION cs;
���ų�ʼ������
	void WINAPI InitializeCriticalSection(
		LPCRITICAL_SECTION lpCriticalSection
	);
Ȼ��ͨ������EnterCriticalSection��TryEnterCriticalSection API��һ���߳̽����ٽ�����
	void WINAPI EnterCriticalSection(
		LPCRITICAL_SECTION lpCriticalSection
	);
	BOOL WINAPI TryEnterCiticalSection(
		LPCRITICAL_SECTION lpCriticalSection
	);
�߳��������󣬱������LeaveCriticalSection API�뿪�ٽ�����
	void WINAPI LeaveCriticalSection(
		LPCRITICAL_SECTION lpCriticalSection
	);
���ŵ���DeleteCriticalSection API�ͷ���Դ��
	void WINAPI DeleteCriticalSection(
		LPCRITICAL_SECTION lpCriticalSection
	);






















