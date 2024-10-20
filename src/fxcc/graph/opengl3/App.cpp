#include "fxcc/graph/opengl3/App.h"
#include "fxcc/graph/opengl3/RenderStates.h"

using namespace fxcc::graph;
using namespace fxcc::platform;


namespace
{
	RenderStateDesc m_RenderStateDesc;
}

opengl3::App::App(const fxcc::platform::common::App::Desc& desc)
	:glfw::App(desc)
{

};

bool opengl3::App::Init()
{
	if (!glfw::App::Init())
	{
		ztclog::info("failed init glfw app");
		return false;
	}

#ifdef _WIN32
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		ztclog::error("Failed to initialize GLAD");
		return false;
	}
#endif


	m_RenderStateDesc.m_BackgroudColor = glm::vec4(1.0f);
	m_RenderStateDesc.m_ClearColor = true;

	return true;
}

void opengl3::App::OnSwapBuffer()
{
	glfwSwapBuffers(m_GlfwWindow);
};


void opengl3::App::OnFrameRender()
{
	RenderStatus::Clear(m_RenderStateDesc);
}
