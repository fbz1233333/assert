#pragma once

#include "fxcc/platform/glfw/pch.h"
#include "fxcc/platform/common/App.h"
#include "fxcc/platform/glfw/Callbacks.h"

namespace fxcc
{
    namespace platform
    {
        namespace glfw
        {
            struct App :public fxcc::platform::common::App
            {
                App(const App::Desc& desc);

                virtual bool Init();

                bool InitWindow();

                int Run();

                void GetJoyStickDevices();

                void OnJoystick();


            protected:
                
                virtual void BeginFrame() {};

                virtual void EndFrame() {}
                
                virtual void OnFrameRender() {};

                virtual void OnTick();

                virtual void OnAfterUpdate() {};


            public:

                GLFWwindow* m_GlfwWindow = nullptr;

                virtual void OnFramebuffersize(int w, int h);

                virtual void OnWindowPos(int x, int y);

                virtual void OnFocus(int e);

                virtual void OnIconify(int e);
                
                virtual void OnClose() ;
                
                virtual void OnRefresh();

                virtual void OnMonitor(int e);

                virtual void OnSwapBuffer() {};

                virtual void OnWindowHint();

                virtual void OnDestory();

            };
        };
    };
}
