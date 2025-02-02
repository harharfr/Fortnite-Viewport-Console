#include <windows.h>
#include <process.h>

#include "sakura.h"

VOID WINAPIV MainThread(LPVOID lpParameter)
{
    BOOL bInitialized = FALSE;

    while (!bInitialized)
    {
        if (GetAsyncKeyState(VK_F1) & 1)
        {
            bInitialized = TRUE;
        }
    }

    if (SDK::Init())
    {
        InitializeViewportConsole();
    }

    _endthread();
}

BOOL APIPRIVATE IsValid()
{
    WCHAR PATH[MAX_PATH];

    if (GetModuleFileName(GetModuleHandle(NULL), PATH, sizeof(PATH)) == 0)
        return FALSE;

    if (wcsstr(PATH, TEXT("FortniteClient-Win64-Shipping.exe")) == nullptr)
        return FALSE;

    if (CreateSemaphore(NULL, 1, 1, TEXT("Global\\Sakura")) == NULL)
        return FALSE;

    if (GetLastError() == ERROR_ALREADY_EXISTS)
        return FALSE;

    return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        if (IsValid())
        {
            uintptr_t thread = _beginthread(MainThread, 0, nullptr);
        }
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
