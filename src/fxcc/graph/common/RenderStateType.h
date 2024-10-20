#pragma once

#include "fxcc/pch.h"

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

enum RasterizerType
{
	_r_none_ = 0,
	_r_cull_back_ccw
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
	BlendType m_BlendType;
	RasterizerType m_RasterizerType;

	RenderStateDesc() :
		m_ClearColor(true),
		m_ClearDepth(true),
		m_ClearStencil(false),
		m_BackgroudColor(glm::vec4(0.0f)),
		m_DepthValue(1),
		m_StencilValue(0),
		m_DepthStencilType(DepthStencilType::_dp_depth_less_stencil_no_),
		m_BlendType(BlendType::_b_none_),
		m_RasterizerType(RasterizerType::_r_none_)
	{

	};
};