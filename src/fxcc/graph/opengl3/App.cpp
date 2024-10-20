#include "fxcc/graph/opengl3/App.h"

using namespace fxcc::graph;
using namespace fxcc::platform;


namespace
{
	enum DepthStencilType
	{
		_dp_none_,

		// depth less and no stencil 
		_dp_dlns_,

		// depth less and stencil always
		_dp_dlas_,
	};


	struct RenderStateDesc
	{
		glm::vec4 m_BackgroudColor;
		int m_DepthValue;
		int m_StencilValue;

		bool m_ClearColor;
		bool m_ClearDepth;
		bool m_ClearStencil;

		RenderStateDesc() :
			m_ClearColor(true), 
			m_ClearDepth(true),
			m_ClearStencil(false), 
			m_BackgroudColor(glm::vec4(0.0f)),
			m_DepthValue(1),
			m_StencilValue(0)
		
		{

		};
	};

	RenderStateDesc m_RenderStateDesc;
	struct DepthStencilDesc
	{
		bool m_EnableDepthFunc;
		int m_DepthFunc;

		DepthStencilDesc() :m_EnableDepthFunc(true), m_DepthFunc(GL_LESS)
		{
		}
	};
	struct RenderStatus
	{
		static void Clear(const DepthStencilDesc& desc)
		{
			if (desc.m_EnableDepthFunc) {
				glEnable(GL_DEPTH_TEST);
				glDepthFunc(desc.m_DepthFunc); 
			}
			else {
				glDisable(GL_DEPTH_TEST);
			}
		}
		static void Clear(const RenderStateDesc& desc)
		{

			auto color = desc.m_BackgroudColor;
			glClearColor(color.x, color.y, color.z, color.w);
			glClearDepth(desc.m_DepthValue);
			glClearStencil(desc.m_StencilValue);
			int clearBit = 0;
			if (desc.m_ClearColor)
			{
				clearBit |= GL_COLOR_BUFFER_BIT;
			}
			if (desc.m_ClearDepth)
			{
				clearBit |= GL_DEPTH_BUFFER_BIT;
			}
			if (desc.m_ClearStencil)
			{
				clearBit |= GL_STENCIL_BUFFER_BIT;
			}
			glClear(clearBit);

		}

	};
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
