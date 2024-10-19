#include "fxcc/platform/glfw/App.h"
#include "fxcc/platform/common/Input.h"

using namespace fxcc::platform::glfw;

#define FXCC_BUILD_PLATFORM_GFLW_FAILED(x) if(!x) return false
#define FXCC_BUILD_PLATFORM_GLFW_SUCCESE(x) if(!x) return true
#define FXCC_BUILD_PLATFORM_GLFW_BREAK(x) if(!x) return

namespace fxcc
{
    namespace platform
    {
        namespace glfw
        {
            struct CallBacks
            {
                static std::unordered_map<GLFWwindow*, struct App*> m_Apps;

                static void Register(App* app)
                {
                    InjectWindow(app->m_GlfwWindow);
                    m_Apps[app->m_GlfwWindow] = app;
                }
                static bool HasWindow(GLFWwindow* window)
                {
                    return m_Apps.find(window) != m_Apps.end();
                }
                static App* GetWindow(GLFWwindow* window)
                {
                    return m_Apps[window];
                }
                static void glfw_error_callback(int error, const char* description)
                {
                    ztclog::info("Glfw Error %d: %s\n", error, description);
                }
                static void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
                {
                    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));

                    auto& input = Input::Inst();
                    input.KeyCallback(key, scancode, action, mode);

                }
                static void glfw_cursorpos_callback(GLFWwindow* window, double x, double y)
                {
                    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
                    auto& input = Input::Inst();
                    input.CursorPos((int)x, int(y));
                }
                static void glfw_mouse_callback(GLFWwindow* window, int key, int action, int mode)
                {
                    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
                    auto& input = Input::Inst();
                    input.MouseCallBack(key, action, mode);
                }
                static void glfw_frame_callback(GLFWwindow* window, int width, int height)
                {
                    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
                    auto app = GetWindow(window);
                    app->OnFramebuffersize(width, height);
                }
                static void glfw_monitor_callback(GLFWmonitor* window, int ev)
                {
                    //FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
                }
                static void glfw_window_focus_callback(GLFWwindow* window, int e)
                {
                    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
                    auto app = GetWindow(window);
                    app->OnFocus(e);
                }
                static void glfw_close_callback(GLFWwindow* window)
                {
                    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
                    auto app = GetWindow(window);
                    app->OnClose();

                }
                static void glfw_joystick_callback(int joy, int event)
                {
                    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(glfwGetCurrentContext()));
                    auto& input = Input::Inst();
                    input.JoysticCallback(joy, event);
                }
                static void glfw_window_iconify_callback(GLFWwindow* window, int ev)
                {
                    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
                    auto app = GetWindow(window);
                    app->OnIconify(ev);

                }
                static void glfw_scroll_callback(GLFWwindow* window, double x, double y)
                {
                    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
                    auto& input = Input::Inst();
                    input.Scroll(x,y);
                }
                static void glfw_refresh_callback(GLFWwindow* window)
                {
                    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
                    auto app = GetWindow(window);
                    app->OnRefresh();
                }
                static void glfw_pos_callback(GLFWwindow* window, int x, int y)
                {
                    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
                    auto app = GetWindow(window);
                    app->OnWindowPos(x, y);
                }

                static void glfw_drop_callback(GLFWwindow* window, int count, const char** paths)
                {
                    FXCC_BUILD_PLATFORM_GLFW_BREAK(HasWindow(window));
                    auto app = GetWindow(window);
                    
                    std::vector<std::string> _paths;
                    _paths.resize(count);
                    for (int i = 0; i < count; i++)
                    {
                        _paths[i] = paths[i];
                    }
                };

                static void InjectWindow(GLFWwindow* window)
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
            };
        }
    }
};

std::unordered_map<GLFWwindow*, struct App*> CallBacks::m_Apps;

fxcc::platform::glfw::App::App(const common::App::Desc& desc)
    : common::App(desc) 
{
};

bool App::Init()
{
	if (!glfwInit())
	{
		ztclog::warn("failed create glfw window");
		return false;
	}

	const char* glsl_version = "#version 330";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);		   // Required on Mac

	m_GlfwWindow = glfwCreateWindow(m_Desc.m_Size.x, m_Desc.m_Size.y, m_Desc.m_Title.c_str(), nullptr, nullptr);

	if (!m_GlfwWindow) {
		//std::cerr << "Failed to create GLFW window" << std::endl;
		ztclog::warn("failed create window");
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(m_GlfwWindow);

	glfwSetWindowSize(m_GlfwWindow, m_Desc.m_Size.x,m_Desc.m_Size.y);
	glfwSetWindowPos(m_GlfwWindow, m_Desc.m_Pos.x, m_Desc.m_Pos.y);
	glfwSetWindowTitle(m_GlfwWindow, m_Desc.m_Title.c_str());
    
    if (m_Desc.m_Iconify)
    {
        glfwIconifyWindow(m_GlfwWindow);
    }

	glfwSwapInterval(m_Desc.m_Interval);

    CallBacks::Register(this);


	return true;
};

int App::Run()
{
	while (!glfwWindowShouldClose(m_GlfwWindow))
	{
		glfwPollEvents();

		// if (m_Desc.m_Focused)
		{
			OnFrameRender();

			OnTick();
			
			OnAfterUpdate();
		}

		glfwSwapBuffers(m_GlfwWindow);
	}

	Destory();
	return 0;

}
void App::OnFramebuffersize(int w, int h)
{
    m_Desc.m_Size.x = w; 
    m_Desc.m_Size.y = h;
}

void App::OnWindowPos(int x, int y)
{
    m_Desc.m_Pos.x = x;
    m_Desc.m_Pos.y;
}

void App::OnFocus(int e) {
    m_Desc.m_Focused = e;
}

void fxcc::platform::glfw::App::OnIconify(int e)
{
    m_Desc.m_Iconify = e;
};

void App::OnClose()
{
    ztclog::debug("Current window %s Close", m_Desc.m_Title.c_str());
}
void App::OnRefresh()
{
    ztclog::debug("Current window %s Refresh", m_Desc.m_Title.c_str());
};

void App::Destory()
{
	glfwDestroyWindow(m_GlfwWindow);
	glfwTerminate();

}
