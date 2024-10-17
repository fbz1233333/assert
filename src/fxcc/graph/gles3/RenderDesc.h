#pragma once

#include "fxcc/graph/pch.h"

namespace Ogl
{
	namespace Gut
	{
		enum BlendDescType
		{
			_blenddesc_none_ = 0,
			_blenddesc_text_,
			_blenddesc_end_,
		};

		struct BlendDesc
		{
			std::string m_Name;
			bool enableBlend = false;
			int sfactor = GL_SRC_ALPHA;
			int dfactor = GL_ONE_MINUS_SRC_ALPHA;
			void Clear() const;
		};
		enum RasterizerDescType
		{
			_rasterizer_none_ = 0,
			_rasterizer_cull_back_bkCCW,
			_rasterizer_end_,
		};
		struct RasterizerDesc
		{
			std::string m_Name;
			bool enableCullFace = true;
			int cullFace = GL_BACK;
			int frontFace = GL_CCW;

			void Clear() const;
		};
		enum DepthStencilType
		{
			_depthStencil_none_ = 0,
			_depthStencil_dlns_,
			_depthStencil_dl_stencil_always_,
			_depthStencil_dl_stencil_selected_,
			_depthStencil_end_,

		};
		struct DepthStencilDesc
		{
			std::string m_Name;

			bool enableDepthTest = true;
			int depthFunc = GL_LESS;

			bool enableStencilTest = false;
			int stencilFunc = GL_ALWAYS;
			int stencilRef = 0;
			int stencilRefMask = 0x00;

			int stencilFail = GL_KEEP;
			int stencilZFail = GL_KEEP;
			int stencilZPass = GL_REPLACE;

			int stencilMask = 0xFF;

			void Clear() const;
		};
	};
};