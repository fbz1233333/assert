#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/RenderDesc.h"

namespace Ogl
{
	namespace Gut {

		struct EffectBase {

			Ogl::Gut::DepthStencilDesc m_DepthStencilDesc;
			Ogl::Gut::RasterizerDesc m_RasterizerDesc;
			Ogl::Gut::BlendDesc m_BlendDesc;
			void Clear();
			void Begin();
			void End();
		};
	};

};