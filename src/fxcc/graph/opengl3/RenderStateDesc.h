#pragma once

#include "fxcc/graph/opengl3/pch.h"

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
	BlendDesc() :m_EnableBlend(false)
	{

	}
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