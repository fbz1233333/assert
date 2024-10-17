#pragma once

#include "fxcc/platform/glfw/interface.h"
#include "fxcc/platform/core/AppDesc.h"

namespace fxcc
{
    namespace platform
    {

        template <>
        struct App<fxcc::platform::glfw::Impl>
        {
            core::AppDesc m_Desc;
            App<fxcc::platform::glfw::Impl>(const core::AppDesc &desc) : m_Desc(desc)
            {
            };
            virtual bool Init();

            virtual void Destory();

            int Run();

        protected:
            virtual void OnFrameRender(){};

            virtual void OnTick(){};

            virtual void OnAfterUpdate() {};

        public:
            GLFWwindow *m_GlfwWindow = nullptr;

        public:
            static std::unordered_map<GLFWwindow *, App<glfw::Impl> *> m_Apps;
            struct CallBacks
            {
                static void glfw_error_callback(int no, const char *error) {

                };
                static void glfw_window_size(GLFWwindow *window, int w, int h) {
                    auto app = m_Apps[window];
                };
            };
        };
    };
};
