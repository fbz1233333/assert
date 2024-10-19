#include "fxcc/platform/glfw/Callbacks.h"
#include "fxcc/platform/glfw/App.h"

using namespace fxcc::platform::glfw;

std::unordered_map<GLFWwindow*, struct App*> CallBacks::m_Apps;


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

    auto& input = Input::Inst();
    input.KeyCallback(key, scancode, action, mode);

}
void fxcc::platform::glfw::CallBacks::glfw_cursorpos_callback(GLFWwindow* window, double x, double y)
{
    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
    auto& input = Input::Inst();
    input.CursorPos((int)x, int(y));
}

void fxcc::platform::glfw::CallBacks::glfw_mouse_callback(GLFWwindow* window, int key, int action, int mode)

{
    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
    auto& input = Input::Inst();
    input.MouseCallBack(key, action, mode);
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

void fxcc::platform::glfw::CallBacks::glfw_joystick_callback(int joy, int event)
{
    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(glfwGetCurrentContext()));
    auto& input = Input::Inst();
    input.JoysticCallback(joy, event);
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
    auto& input = Input::Inst();
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