#pragma once

#define ARESDX_APP_RD_CALL __cdecl

#ifdef _WIN32
    #ifdef ARESDX_APP_RD_LIBRARY
        #define ARESDX_APP_RD_API __declspec(dllexport)
    #else
        #define ARESDX_APP_RD_API __declspec(dllimport)
    #endif
#else
    #define ARESDX_APP_RD_API
#endif

#include <Windows.h>

namespace ares_app
{
    class ARESDX_APP_RD_API Application
    {
    public:
        Application();
        virtual ~Application();

        void SetWindowIconHandle(HICON hIcon);

    protected:
        virtual int UnloadStateList() = 0;
        virtual int OnDeviceRenderOneFrame() = 0;
        virtual int OnInitDeviceIndependent() = 0;
        virtual int OnShutdownDeviceIndependent() = 0;
        virtual int OnInitDeviceDependent() = 0;
        virtual int OnShutdownDeviceDependent() = 0;
        virtual int OnSystemRequestExit();
        virtual int NativeOnFullScreenStateChanged();
        virtual int NativeOnResolutionChanged();
        virtual BOOL NativeOnRun();
        virtual int OnWindowMessage();
        virtual int OnActivateWindow();
        virtual int OnDeactivateWindow();
    };
}
