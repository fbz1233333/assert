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
                void glfw_error_callback(int error, const char *description)
                {
                    ztclog::info("Glfw Error %d: %s\n", error, description);
                }
                void glfw_key_callback(GLFWwindow *window, int key, int scancode, int action, int mode)
                {
            
                }
                void glfw_cursorpos_callback(GLFWwindow *window, double x, double y)
                {
            
                }
                void glfw_mouse_callback(GLFWwindow *window, int key, int action, int mode)
                {
         
                }
                void glfw_frame_callback(GLFWwindow *window, int width, int height)
                {
     
                }
                void glfw_monitor_callback(GLFWmonitor *window, int ev)
                {
     }
                void glfw_window_focus_callback(GLFWwindow *window, int e)
                {
         
                }
                void glfw_close_callback(GLFWwindow *window)
                {
           
                }
                void glfw_joystick_callback(int joy, int event)
                {
          
                }
                void glfw_window_iconify_callback(GLFWwindow *window, int ev)
                {
         
                }
                void glfw_scroll_callback(GLFWwindow *window, double x, double y)
                {
          
                }
                void glfw_refresh_callback(GLFWwindow *window)
                {
                }
                void glfw_pos_callback(GLFWwindow *, int x, int y)
                {
                }

                void glfw_drop_callback(GLFWwindow *window, int count, const char **paths)
                {
                };
            };
        };
    };
};
