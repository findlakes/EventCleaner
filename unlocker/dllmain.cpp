// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include <Windows.h>
#include <iostream>



VOID fn_console_main() {

	Sleep(3000); // magic :)
	HANDLE hPipeFile = NULL;
	LPCWSTR lpNamePipe = L"\\\\.\\pipe\\kangaroo";
	CHAR buffer[1024];
	DWORD dwRealRecv = NULL;
	DWORD dwHandleValue = NULL;

	hPipeFile = CreateFile(lpNamePipe, GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_EXISTING, NULL, NULL);
	if (hPipeFile == INVALID_HANDLE_VALUE)
		return;


	ReadFile(hPipeFile, buffer, sizeof(buffer), &dwRealRecv, NULL);
	dwHandleValue = atoi(buffer);

	CloseHandle(hPipeFile);
	CloseHandle((HANDLE)dwHandleValue);
	CloseHandle((HANDLE)dwHandleValue);

	return;

}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		fn_console_main();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return FALSE;
}

