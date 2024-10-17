#pragma once


#include "fxcc/graph/Type.h"
#include "fxcc/graph/Image.h"
#include "fxcc/graph/Base.h"

namespace Ogl
{
	namespace Gut
	{
		struct Texture2DDesc2 :public Base
		{
		
			int m_Mipmap;
			Ogl::Gut::SamplerType m_SamplerType;
			Ogl::Gut::Image::Desc m_ImageDesc;
			Texture2DDesc2()
				:m_Mipmap(0), m_SamplerType(SamplerType::_sampler_none_)
			{

			}
		};
	};
};