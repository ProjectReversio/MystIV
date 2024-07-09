#include "aresdx_app_rd.hpp"

namespace ares_app
{
    Application::Application()
    {

    }

    Application::~Application()
    {

    }

    void Application::SetWindowIconHandle(HICON hIcon)
    {

    }

    int Application::OnSystemRequestExit()
    {
        return 0;
    }

    int Application::NativeOnFullScreenStateChanged()
    {
        return 0;
    }

    int Application::NativeOnResolutionChanged()
    {
        return 0;
    }

    BOOL Application::NativeOnRun()
    {
        return false;
    }

    int Application::OnWindowMessage()
    {
        return 0;
    }

    int Application::OnActivateWindow()
    {
        return 0;
    }

    int Application::OnDeactivateWindow()
    {
        return 0;
    }
}