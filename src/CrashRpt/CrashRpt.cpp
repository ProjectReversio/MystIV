#include "CrashRpt.hpp"
#include <Windows.h>

int CRASHRPT_CALL CrashRpt_AddFile(CrashRpt* instance, const char* path, const char* description)
{
    return 0;
}

int CRASHRPT_CALL CrashRpt_GenerateErrorReport(int a1, int a2)
{
    return 0;
}

CrashRpt* CRASHRPT_CALL CrashRpt_Install(int a1, int a2, int a3, const char* zipName)
{
    return new CrashRpt();
}

void CRASHRPT_CALL CrashRpt_Uninstall(CrashRpt* instance)
{
    delete instance;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    return TRUE;
}
