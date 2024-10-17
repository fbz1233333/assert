#pragma once

#include "fxcc/graph/Image.h"
#include "fxcc/graph/Type.h"
#include "fxcc/graph/RenderTargetDesc1.h"
#include "fxcc/graph/RenderTargetDesc2.h"

namespace Ogl
{
	namespace Gut
	{

		struct RenderTargetDesc:public Base
		{
			RenderTargetDesc1 m_Desc1;
			RenderTargetDesc2 m_Desc2;
			RenderTargetDescType m_Type;
			RenderTargetDesc() = default;
			RenderTargetDesc(const RenderTargetDesc1 &desc1)
				: m_Desc1(desc1), m_Type(_desc1_)
			{
			}
			RenderTargetDesc(const RenderTargetDesc2 &d2)
				: m_Desc2(d2), m_Type(_desc2_) {

				  };
			void InitDesc2(int numTextures, int width, int height, int component = 4, int hdr = false);

			void Parse2To1()
			{
				m_Desc1.m_Images.clear();
				for (int i = 0; i < m_Desc2.m_NumTextures; i++)
				{
					Image image;
					image.m_HD = m_Desc2.m_ImageHD;

					m_Desc1.m_Images.push_back(image);
				};
				m_Desc1.m_ImageHD = m_Desc2.m_ImageHD;
			};
		};
	};
};