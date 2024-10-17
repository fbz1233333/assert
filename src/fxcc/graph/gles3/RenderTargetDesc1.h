#pragma once

#include "fxcc/graph/Image.h"

namespace Ogl
{
	namespace Gut
	{
		struct RenderTargetDesc1:public Base
		{
			Image::HD m_ImageHD;

			std::vector<Ogl::Gut::Image> m_Images;

			void Resize(int w, int h)
			{
				m_ImageHD.m_Width = w;
				m_ImageHD.m_Height = h;
				for (auto &image : m_Images)
				{
					image.Resize(w, h);
				}
			};
		};
	};

};