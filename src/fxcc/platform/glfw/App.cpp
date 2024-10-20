#include "fxcc/platform/glfw/App.h"
#include "fxcc/platform/common/Input.h"

using namespace fxcc::platform::glfw;

fxcc::platform::glfw::App::App(const common::App::Desc& desc)
    : common::App(desc) 
{
};

bool App::Init()
{
	if (!InitWindow())
	{
		ztclog::info("failed init window");
	}

	return true;
}

bool fxcc::platform::glfw::App::InitWindow()
{
	if (!glfwInit())
	{
		ztclog::warn("failed create glfw window");
		return false;
	}
	OnWindowHint();

	glm::ivec2 wndPos = m_Desc.GetGflwPos();
	glm::ivec2 wndSize = m_Desc.GetGflwSize();

	m_GlfwWindow = glfwCreateWindow(wndSize.x, wndSize.y, m_Desc.m_Title.c_str(), nullptr, nullptr);
	if (!m_GlfwWindow) {
		ztclog::warn("failed create window");
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(m_GlfwWindow);

	glfwSetWindowSize(m_GlfwWindow, wndSize.x, wndSize.y);
	glfwSetWindowPos(m_GlfwWindow, wndPos.x, wndPos.y);
	glfwSetWindowTitle(m_GlfwWindow, m_Desc.m_Title.c_str());

	if (m_Desc.m_Iconify)
	{
		glfwIconifyWindow(m_GlfwWindow);
	}

	glfwSwapInterval(m_Desc.m_Interval);

	CallBacks::Register(this);

	GetJoyStickDevices();

	return true;
}

void fxcc::platform::glfw::App::OnWindowHint()
{

	const char* glsl_version = "#version 330";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);		   
};

int App::Run()
{
	while (!glfwWindowShouldClose(m_GlfwWindow))
	{
		glfwPollEvents();

		OnFrameRender();

		OnTick();

		OnAfterUpdate();

		OnSwapBuffer();
	}

	OnDestory();
	return 0;

}
void fxcc::platform::glfw::App::GetJoyStickDevices()
{
	for (int i = 0; i < GLFW_JOYSTICK_LAST; ++i)
	{
		if (glfwJoystickPresent(i))
		{
			m_Input.JoysticCallback(i, 1, glfwGetJoystickName(i));
		}
	}
}

void fxcc::platform::glfw::App::OnJoystick()
{
	std::vector<int> joyDecvices = m_Input.GetJoystickNos();
	for (const auto& jId : joyDecvices)
	{
		int count;
		const unsigned char* buttons = glfwGetJoystickButtons(jId, &count);
		m_Input.SetJoystickStates(jId, count, buttons);

		int axesCount;
		const float* axes = glfwGetJoystickAxes(jId, &axesCount);
		m_Input.SetJoystickAxes(jId, axesCount, axes);
	}
	
};

void fxcc::platform::glfw::App::OnTick()
{
	OnJoystick();
};


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

void App::OnDestory()
{
	glfwDestroyWindow(m_GlfwWindow);
	glfwTerminate();
}
