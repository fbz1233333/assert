#pragma once

#include "fxcc/graph/opengl3/RenderStateDesc.h"
#include "fxcc/graph/common/RenderStateType.h"

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