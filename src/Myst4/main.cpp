#include <iostream>
#include <Windows.h>
#include "resource.h"

#include <CrashRpt.hpp>
#include <aresdx_app_rd.hpp>
#include <base_rd.hpp>
#include <m4_thor_rd.hpp>

std::string& getFilenameBuffer(std::string& buffer)
{
    // TODO: Cleanup Decompiled Code

    char path[256];
    GetModuleFileName(nullptr, path, 256);
    char* c = path;
    if (path[0])
        while(*++c);
    char* c2 = c - 1;
    if (path == c2)
    {
LABEL_6:
        c2 = nullptr;
    }
    else
    {
        while (*c2 != '\\')
        {
            if (path == --c2)
                goto LABEL_6;
        }
    }
    c2[1] = 0;

    //auto alloc = ubi::Mem::GetGeneralAlloc();
    //alloc->Malloc(1);

    // TODO: Use ubisoft allocator like in the original binary
    buffer = path;

    return buffer;
}

bool file_exists(const char* filename)
{
    WIN32_FIND_DATA findData;
    HANDLE first = FindFirstFile(filename, &findData);
    if (first == INVALID_HANDLE_VALUE)
        return false;
    FindClose(first);
    return (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != FILE_ATTRIBUTE_DIRECTORY;
}

bool load_config()
{
    std::string filename;
    getFilenameBuffer(filename);

    std::string detectionApp = filename + "\\configurator\\myst_detection.exe";
    std::string config = filename + "\\detect_config.ini";

    bool configExists = file_exists(config.c_str());
    bool detectionAppExists = file_exists(detectionApp.c_str());

    if (!configExists && detectionAppExists)
    {
        HANDLE file = CreateFile(config.c_str(), GENERIC_WRITE, FILE_SHARE_WRITE, nullptr, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, nullptr);
        if (file != INVALID_HANDLE_VALUE)
            CloseHandle(file);

        ShellExecute(nullptr, "Open", detectionApp.c_str(), "/autolaunchgame", nullptr, SW_SHOWNORMAL);
        return false;
    }

    return true;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    std::string filename;
    getFilenameBuffer(filename);
    std::string reportZip = filename + "\\crash_report.zip";
    std::string config_log = filename + "\\configurator\\config_log.txt";

    CrashRpt* crashRpt = CrashRpt_Install(0, 0, 0, reportZip.c_str());
    CrashRpt_AddFile(crashRpt, config_log.c_str(), "System configuration");

    HANDLE Mutex = CreateMutex(nullptr, TRUE, "Myst4 Mutex");
    if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        HWND window = nullptr;
        EnumWindows([](HWND hWnd, LPARAM lParam) -> BOOL
        {
            char buffer[256];
            GetWindowText(hWnd, buffer, 256);
            char* c = buffer;
            if (buffer[0])
                while (*++c);

            if ((c - buffer) < 7)
                return TRUE;

            if (strncmp(buffer, "Myst IV", 7))
                return TRUE;
            *(HWND*)lParam = hWnd;
            return FALSE;

        }, (LPARAM)&window);
        ShowWindow(window, SW_MINIMIZE);
        ShowWindow(window, SW_RESTORE);

        // TODO: They didn't uninstall the crash reporter in the original binary? Memory Leak Bug?
        //CrashRpt_Uninstall(crashRpt);
    }
    else
    {
        SetErrorMode(SEM_FAILCRITICALERRORS);
        if (load_config())
        {
            thor::Application app(lpCmdLine);
            HICON icon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APP_ICON));
            app.SetWindowIconHandle(icon);
            app.unknownBool = true;
            (&app)->NativeOnRun(); // This weird hack ensures that the call uses an offset and not a dllimport
        }
        CloseHandle(Mutex);
        SetErrorMode(0);
        CrashRpt_Uninstall(crashRpt);
    }
    return 0;
}
