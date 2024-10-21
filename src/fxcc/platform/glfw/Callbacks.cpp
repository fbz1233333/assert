#include "fxcc/platform/glfw/Callbacks.h"
#include "fxcc/platform/glfw/App.h"

using namespace fxcc::platform::glfw;

std::unordered_map<GLFWwindow*, struct App*> CallBacks::m_Apps;

std::unordered_map<int, KeyCode> CallBacks::m_KeyMap = 
{
    {GLFW_KEY_A, KeyCode::A},
    {GLFW_KEY_B, KeyCode::B},
    {GLFW_KEY_C, KeyCode::C},
    {GLFW_KEY_D, KeyCode::D},
    {GLFW_KEY_E, KeyCode::E},
    {GLFW_KEY_F, KeyCode::F},
    {GLFW_KEY_G, KeyCode::G},
    {GLFW_KEY_H, KeyCode::H},
    {GLFW_KEY_I, KeyCode::I},
    {GLFW_KEY_J, KeyCode::J},
    {GLFW_KEY_K, KeyCode::K},
    {GLFW_KEY_L, KeyCode::L},
    {GLFW_KEY_M, KeyCode::M},
    {GLFW_KEY_N, KeyCode::N},
    {GLFW_KEY_O, KeyCode::O},
    {GLFW_KEY_P, KeyCode::P},
    {GLFW_KEY_Q, KeyCode::Q},
    {GLFW_KEY_R, KeyCode::R},
    {GLFW_KEY_S, KeyCode::S},
    {GLFW_KEY_T, KeyCode::T},
    {GLFW_KEY_U, KeyCode::U},
    {GLFW_KEY_V, KeyCode::V},
    {GLFW_KEY_W, KeyCode::W},
    {GLFW_KEY_X, KeyCode::X},
    {GLFW_KEY_Y, KeyCode::Y},
    {GLFW_KEY_Z, KeyCode::Z},
    {GLFW_KEY_0, KeyCode::NUM0},
    {GLFW_KEY_1, KeyCode::NUM1},
    {GLFW_KEY_2, KeyCode::NUM2},
    {GLFW_KEY_3, KeyCode::NUM3},
    {GLFW_KEY_4, KeyCode::NUM4},
    {GLFW_KEY_5, KeyCode::NUM5},
    {GLFW_KEY_6, KeyCode::NUM6},
    {GLFW_KEY_7, KeyCode::NUM7},
    {GLFW_KEY_8, KeyCode::NUM8},
    {GLFW_KEY_9, KeyCode::NUM9},
    {GLFW_KEY_ESCAPE, KeyCode::ESC},
    {GLFW_KEY_ENTER, KeyCode::ENTER},
    {GLFW_KEY_SPACE, KeyCode::SPACE},
    {GLFW_KEY_BACKSPACE, KeyCode::BACKSPACE},
    {GLFW_KEY_LEFT, KeyCode::LEFT},
    {GLFW_KEY_RIGHT, KeyCode::RIGHT},
    {GLFW_KEY_UP, KeyCode::UP},
    {GLFW_KEY_DOWN, KeyCode::DOWN},
    {GLFW_KEY_LEFT_ALT, KeyCode::LEFTALT}, 
    {GLFW_KEY_RIGHT_ALT, KeyCode::RIGHTALT}, 
    {GLFW_KEY_LEFT_SHIFT, KeyCode::LEFTSHIFT}, 
    {GLFW_KEY_RIGHT_SHIFT, KeyCode::RIGHTSHIFT},  
    {GLFW_KEY_LEFT_CONTROL, KeyCode::LEFTCTRL}, 
    {GLFW_KEY_RIGHT_CONTROL, KeyCode::RIGHTCTRL}  

};

std::unordered_map<int, MouseButton> CallBacks::m_MouseMap =
{
    {GLFW_MOUSE_BUTTON_1, MouseButton::LEFT},
    {GLFW_MOUSE_BUTTON_2, MouseButton::RIGHT},
    {GLFW_MOUSE_BUTTON_3, MouseButton::MIDDLE},   
    {GLFW_MOUSE_BUTTON_4, MouseButton::BUTTON1},  
    {GLFW_MOUSE_BUTTON_5, MouseButton::BUTTON2},  
};

std::unordered_map<int, JoystickButton> CallBacks::m_JoystickMap =
{
    {0, JoystickButton::A},    
    {1, JoystickButton::B},    
    {2, JoystickButton::X},    
    {3, JoystickButton::Y},    
    {4, JoystickButton::LB},   
    {5, JoystickButton::RB},   
    {6, JoystickButton::LSTICK},   
    {7, JoystickButton::RSTICK},   
    {8, JoystickButton::START},
    {9, JoystickButton::START}  
};

void fxcc::platform::glfw::CallBacks::Register(App* app)
{
    InjectWindow(app->m_GlfwWindow);
    m_Apps[app->m_GlfwWindow] = app;
}

bool fxcc::platform::glfw::CallBacks::HasWindow(GLFWwindow* window)
{
    return m_Apps.find(window) != m_Apps.end();
}

App* fxcc::platform::glfw::CallBacks::GetWindow(GLFWwindow* window)
{
    return m_Apps[window];
}

void fxcc::platform::glfw::CallBacks::glfw_error_callback(int error, const char* description)
{
    ztclog::error("Glfw Error %d: %s\n", error, description);
}

void fxcc::platform::glfw::CallBacks::glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
    auto app = GetWindow(window);
    auto& input = app->m_Input;

    ztclog::info("key %d", key);
    input.KeyCallback(m_KeyMap[key], (ActionType)action);

}
void fxcc::platform::glfw::CallBacks::glfw_cursorpos_callback(GLFWwindow* window, double x, double y)
{
    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
    auto app = GetWindow(window);
    auto& input = app->m_Input;
    input.CursorPos((int)x, int(y));
}

void fxcc::platform::glfw::CallBacks::glfw_mouse_callback(GLFWwindow* window, int key, int action, int mode)
{
    ztclog::info("mode %d", mode);

    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
    auto app = GetWindow(window);
    auto& input = app->m_Input;
    input.MouseCallBack(m_MouseMap[key], (ActionType)action);
}
void fxcc::platform::glfw::CallBacks::glfw_frame_callback(GLFWwindow* window, int width, int height)
{
    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
    auto app = GetWindow(window);
    app->OnFramebuffersize(width, height);
}

void fxcc::platform::glfw::CallBacks::glfw_monitor_callback(GLFWmonitor* monitor, int ev)
{
    auto window = glfwGetCurrentContext();
    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
    auto app = GetWindow(window);
    app->OnMonitor(ev);

};

void fxcc::platform::glfw::CallBacks::glfw_window_focus_callback(GLFWwindow* window, int e)
{
    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
    auto app = GetWindow(window);
    app->OnFocus(e);
}
void fxcc::platform::glfw::CallBacks::glfw_close_callback(GLFWwindow* window)
{
    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
    auto app = GetWindow(window);
    app->OnClose();

}

void fxcc::platform::glfw::CallBacks::glfw_joystick_callback(int joy, int ev)
{
    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(glfwGetCurrentContext()));
    auto app = GetWindow(glfwGetCurrentContext());
    auto& input = app->m_Input;
    input.JoysticCallback(joy, ev, glfwGetJoystickName(joy));

}

void fxcc::platform::glfw::CallBacks::glfw_window_iconify_callback(GLFWwindow* window, int ev)

{
    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
    auto app = GetWindow(window);
    app->OnIconify(ev);

}

void fxcc::platform::glfw::CallBacks::glfw_scroll_callback(GLFWwindow* window, double x, double y)
{
    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
    auto app = GetWindow(glfwGetCurrentContext());
    auto& input = app->m_Input;
    input.Scroll(x, y);
}

void fxcc::platform::glfw::CallBacks::glfw_refresh_callback(GLFWwindow* window)

{
    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
    auto app = GetWindow(window);
    app->OnRefresh();
}

void fxcc::platform::glfw::CallBacks::glfw_pos_callback(GLFWwindow* window, int x, int y)

{
    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
    auto app = GetWindow(window);
    app->OnWindowPos(x, y);
}

void fxcc::platform::glfw::CallBacks::glfw_drop_callback(GLFWwindow* window, int count, const char** paths)
{
    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
    auto app = GetWindow(window);

    std::vector<std::string> _paths;
    _paths.resize(count);
    for (int i = 0; i < count; i++)
    {
        _paths[i] = paths[i];
    }
}

void fxcc::platform::glfw::CallBacks::InjectWindow(GLFWwindow* window)
{
    glfwSetFramebufferSizeCallback(window, glfw_frame_callback);
    glfwSetKeyCallback(window, glfw_key_callback);
    glfwSetCursorPosCallback(window, glfw_cursorpos_callback);
    glfwSetMouseButtonCallback(window, glfw_mouse_callback);
    glfwSetWindowFocusCallback(window, glfw_window_focus_callback);
    glfwSetWindowCloseCallback(window, glfw_close_callback);
    glfwSetScrollCallback(window, glfw_scroll_callback);
    glfwSetWindowPosCallback(window, glfw_pos_callback);
    glfwSetDropCallback(window, glfw_drop_callback);

    glfwSetWindowIconifyCallback(window, glfw_window_iconify_callback);
    glfwSetJoystickCallback(glfw_joystick_callback);
    glfwSetMonitorCallback(glfw_monitor_callback);
    // glfwSetClipboardString(window, "hello world");
    glfwSetWindowRefreshCallback(window, glfw_refresh_callback);
};