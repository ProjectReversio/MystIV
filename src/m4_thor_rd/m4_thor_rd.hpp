#pragma once

#define M4_THOR_RD_CALL __cdecl

#ifdef _WIN32
    #ifdef M4_THOR_RD_LIBRARY
        #define M4_THOR_RD_API __declspec(dllexport)
    #else
        #define M4_THOR_RD_API __declspec(dllimport)
    #endif
#else
    #define M4_THOR_RD_API
#endif

#include <aresdx_app_rd.hpp>

namespace thor
{
    class M4_THOR_RD_API Application : public ares_app::Application
    {
        typedef ares_app::Application Parent;
    public:
        Application(const char* cmd);
        ~Application() override;

        int UnloadStateList() override;
        int OnDeviceRenderOneFrame() override;
        int OnInitDeviceIndependent() override;
        int OnShutdownDeviceIndependent() override;
        int OnInitDeviceDependent() override;
        int OnShutdownDeviceDependent() override;

    public:
        virtual BOOL NativeOnRun();

    private:
        char gap[40];

    public:
        bool unknownBool;
    };
}