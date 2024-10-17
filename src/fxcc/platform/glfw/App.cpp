#include "fxcc/platform/glfw/App.h"
#include "fxcc/platform/core/pch.h"

using namespace fxcc::platform;

std::unordered_map<GLFWwindow *, App<glfw::Impl> *> App<glfw::Impl>::m_Apps;

bool App<fxcc::platform::glfw::Impl>::Init()
{
	if (!glfwInit())
	{
		ztclog::warn("failed create glfw window");
		return false;
	}

	// Decide GL+GLSL versions
#if defined(FXCC_USE_GRAPH_GLES2)
	// GL ES 2.0 + GLSL 100
	const char *glsl_version = "#version 100";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(FXCC_USE_GRAPH_GLES3)
	// GL 3.2 + GLSL 150
	const char *glsl_version = "#version 150";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);		   // Required on Mac
#else
	// GL 3.0 + GLSL 130
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);		   // 3.0+ only
#endif

	m_GlfwWindow = glfwCreateWindow(m_Desc.m_Size.x, m_Desc.m_Size.y, m_Desc.m_Title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(m_GlfwWindow);

	glfwSetWindowSize(m_GlfwWindow, m_Desc.m_Size.x,m_Desc.m_Size.y);
	glfwSetWindowPos(m_GlfwWindow, m_Desc.m_Pos.x, m_Desc.m_Pos.y);
	glfwSetWindowTitle(m_GlfwWindow, m_Desc.m_Title.c_str());

	glfwSwapInterval(m_Desc.m_Interval);
	// glfwSetErrorCallback(CallBacks::glfw_error_callback);

	// glad.c related to some specificed opengl(version) implemnetion;
//#ifdef _WIN32
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		//std::cout << "Failed to initialize GLAD" << std::endl;
//		ztclog::warn("failed to initialized glad");
//		return false;
//	}
//#endif

	return true;
};

int App<fxcc::platform::glfw::Impl>::Run()
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
void App<fxcc::platform::glfw::Impl>::Destory()
{
	glfwDestroyWindow(m_GlfwWindow);
	glfwTerminate();

}
