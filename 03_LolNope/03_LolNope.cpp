#include <Windows.h>

void Payload()
{
	MessageBox(NULL, L"Hello from proxy dll", L"Payload", MB_OK);
	TerminateProcess(GetCurrentProcess(), 0);
}

void nop() {}

BOOL WINAPI DllMain(HMODULE, DWORD r, LPVOID)
{
	if (r == DLL_PROCESS_ATTACH)
	{
		Payload();
	}
	return TRUE;
}
