#pragma once

#include "fxcc/platform/glfw/pch.h"
#include "fxcc/platform/common/AppDesc.h"

namespace fxcc
{
    namespace platform
    {
        namespace glfw
        {
            struct App
            {
                common::AppDesc m_Desc;

                App(const common::AppDesc& desc);

                virtual bool Init();

                virtual void Destory();

                int Run();

            protected:
                virtual void OnFrameRender() {};

                virtual void OnTick() {};

                virtual void OnAfterUpdate() {};


            public:

                GLFWwindow* m_GlfwWindow = nullptr;

                virtual void OnFramebuffersize(int w, int h);

                virtual void OnWindowPos(int x, int y);

                virtual void OnFocus(int e);

                virtual void OnIconify(int e);
                
                virtual void OnClose() ;
                
                virtual void OnRefresh();


            };
        };
    };
}
