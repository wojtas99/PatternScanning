#include "PatternScan.h"
#include <iostream>
DWORD WINAPI main(LPVOID lpParameter)
{
    FILE* f;
    AllocConsole();
    freopen_s(&f, "CONOUT$", "w", stdout);
    const BYTE pattern[] = { 0x80, 0x26, 0x68, 0x0E, 0xB0, 0x00 };
    LPCSTR patternMask = "xxxxx?";
    LPVOID address = FindPattern(pattern, patternMask);
    FreeLibraryAndExitThread((HMODULE)lpParameter, NULL);
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CreateThread(NULL, 0, main, hModule, 0, NULL);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

