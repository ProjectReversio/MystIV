#include "m4_thor_rd.hpp"

namespace thor
{
    Application::Application(const char* cmd)
    {

    }

    Application::~Application()
    {

    }

    int Application::UnloadStateList()
    {
        return 0;
    }

    int Application::OnDeviceRenderOneFrame()
    {
        return 0;
    }

    int Application::OnInitDeviceIndependent()
    {
        return 0;
    }

    int Application::OnShutdownDeviceIndependent()
    {
        return 0;
    }

    int Application::OnInitDeviceDependent()
    {
        return 0;
    }

    int Application::OnShutdownDeviceDependent()
    {
        return 0;
    }

    BOOL Application::NativeOnRun()
    {
        return Parent::NativeOnRun();
    }
}