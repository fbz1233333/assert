#pragma once


#include "fxcc/graph/Effect2d.h"
#include "fxcc/graph/Texture2D.h"

namespace Ogl
{

	namespace Gut
	{
		struct ImageEffect2d :public Ogl::Gut::Effect2d
		{

			ImageEffect2d();

			void Begin();
			void RenderQuad(const Ogl::Gut::Texture2D* texture);
			static std::string FragCode();

		};
	};
};