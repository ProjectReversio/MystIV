#pragma once

#define CRASHRPT_CALL __cdecl

#ifdef _WIN32
    #ifdef CRASHRPT_LIBRARY
        #define CRASHRPT_API __declspec(dllexport)
    #else
        #define CRASHRPT_API __declspec(dllimport)
    #endif
#else
    #define CRASHRPT_API
#endif

class CrashRpt
{
public:
    CrashRpt() = default;
    ~CrashRpt() = default;

};

extern "C"
{
    CRASHRPT_API int CRASHRPT_CALL CrashRpt_AddFile(CrashRpt* instance, const char* path, const char* description);
    CRASHRPT_API int CRASHRPT_CALL CrashRpt_GenerateErrorReport(int a1, int a2);
    CRASHRPT_API CrashRpt* CRASHRPT_CALL CrashRpt_Install(int a1, int a2, int a3, const char* zipName);
    CRASHRPT_API void CRASHRPT_CALL CrashRpt_Uninstall(CrashRpt* instance);
}