#pragma once

#include "fxcc/platform/glfw/pch.h"
#include "fxcc/platform/common/Input.h"


namespace fxcc
{
    namespace platform
    {
        namespace glfw
        {
            struct CallBacks
            {
                
                static std::unordered_map<int, KeyCode> m_KeyMap;

                static std::unordered_map<int, MouseButton> m_MouseMap;
                
                static std::unordered_map<int, JoystickButton> m_JoystickMap;

                static std::unordered_map<GLFWwindow*, struct App*> m_Apps;

                static void Register(struct App* app);

                static bool HasWindow(GLFWwindow* window);

                static App* GetWindow(GLFWwindow* window);

                static void glfw_error_callback(int error, const char* description);

                static void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

                static void glfw_cursorpos_callback(GLFWwindow* window, double x, double y);

                static void glfw_mouse_callback(GLFWwindow* window, int key, int action, int mode);

                static void glfw_frame_callback(GLFWwindow* window, int width, int height);

                static void glfw_monitor_callback(GLFWmonitor* window, int ev);
               
                static void glfw_window_focus_callback(GLFWwindow* window, int e);

                static void glfw_close_callback(GLFWwindow* window);

                static void glfw_joystick_callback(int joy, int event);

                static void glfw_window_iconify_callback(GLFWwindow* window, int ev);

                static void glfw_scroll_callback(GLFWwindow* window, double x, double y);
           
                static void glfw_refresh_callback(GLFWwindow* window);

                static void glfw_pos_callback(GLFWwindow* window, int x, int y);

                static void glfw_drop_callback(GLFWwindow* window, int count, const char** paths);

                static void InjectWindow(GLFWwindow* window);

            };
        }
    }
};
