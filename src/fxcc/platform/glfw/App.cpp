#include "fxcc/platform/glfw/App.h"
#include "fxcc/platform/common/Input.h"

using namespace fxcc::platform::glfw;



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
}

void fxcc::platform::glfw::App::OnMonitor(int e)
{
	ztclog::debug("Current window %s Monitor %d", m_Desc.m_Title.c_str()), e;

}
;

void App::Destory()
{
	glfwDestroyWindow(m_GlfwWindow);
	glfwTerminate();

}
