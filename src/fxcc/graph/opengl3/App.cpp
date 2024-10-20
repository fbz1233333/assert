#include "fxcc/graph/opengl3/App.h"

using namespace fxcc::graph;
using namespace fxcc::platform;


namespace
{
	enum DepthStencilType
	{
		_dp_none_ = 0,

		// depth less and no stencil 
		_dp_depth_less_stencil_no_,

		// depth less and stencil always
		_dp_depth_less_stencil_always_,
	};
	enum BlendType
	{
		_b_none_ = 0,

		// blend render font
		_b_font_,
	};


	struct RenderStateDesc
	{
		bool m_ClearColor;
		bool m_ClearDepth;
		bool m_ClearStencil;

		glm::vec4 m_BackgroudColor;
		int m_DepthValue;
		int m_StencilValue;

		DepthStencilType m_DepthStencilType;

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
		bool m_EnableStencilFunc;

		int m_DepthFunc;

		int m_StencilFunc;
		int m_StencilRef;
		int m_StencilMask;

		int m_StencilWriteMask;
		int m_StencilFail, m_DepthFail, m_DepthStencilPass;

		DepthStencilDesc() :m_EnableDepthFunc(true), m_DepthFunc(GL_LESS), m_EnableStencilFunc(false)
		{
		}
	};

	struct BlendDesc
	{
		bool m_EnableBlend;
		int m_Sfactor, m_Dfactor;
	};
	struct RasterizerDesc {
		int m_PolyMode;
		int m_PolyFillMode;
		bool m_EnableCullface;
		int m_Cullface;
		int m_FrontFace;

		RasterizerDesc()
			:
			m_PolyMode(GL_FRONT_AND_BACK),
			m_PolyFillMode(GL_FILL),
			m_EnableCullface(true),
			m_Cullface(GL_BACK),
			m_FrontFace(GL_CCW)
		{

		}
	
	};

	struct RenderStatus
	{

		static void Clear(const RasterizerDesc& desc)
		{
			glPolygonMode(desc.m_PolyMode, desc.m_PolyFillMode);

			if (desc.m_EnableCullface)
			{
				glEnable(GL_CULL_FACE);
				glCullFace(desc.m_Cullface);
				glFrontFace(desc.m_FrontFace);
			}
			else
			{
				glDisable(GL_CULL_FACE);
			}

		}
		static void Clear(const BlendDesc& desc)
		{
			if (desc.m_EnableBlend)
			{
				glEnable(GL_BLEND);
				glBlendFunc(desc.m_Sfactor, desc.m_Dfactor);
			}
			else
			{
				glDisable(GL_BLEND);
			}
		};
		static void Clear(const DepthStencilDesc& desc)
		{
			if (desc.m_EnableDepthFunc) {
				glEnable(GL_DEPTH_TEST);
				glDepthFunc(desc.m_DepthFunc); 
			}
			else {
				glDisable(GL_DEPTH_TEST);
			}
			if (desc.m_EnableStencilFunc)
			{
				glEnable(GL_STENCIL_TEST);
				glStencilFunc(desc.m_StencilFunc, desc.m_StencilRef, desc.m_StencilMask);
				glStencilMask(desc.m_StencilWriteMask);
				glStencilOp(desc.m_StencilFail, desc.m_DepthFail, desc.m_DepthStencilPass);
			}
			else
			{
				glDisable(GL_STENCIL_TEST);
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
