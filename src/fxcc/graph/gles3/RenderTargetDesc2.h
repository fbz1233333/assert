#pragma once

#include "fxcc/graph/Image.h"

namespace Ogl
{
	namespace Gut
	{

		struct RenderTargetDesc2:public Base
		{
			Ogl::Gut::Image::HD m_ImageHD;
			int m_NumTextures;
			RenderTargetDesc2() :m_NumTextures(0) {};
			RenderTargetDesc2(const Ogl::Gut::Image::HD &hd, const int &numTextures);
		};
	};

};