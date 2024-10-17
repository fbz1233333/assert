#pragma once


#include "fxcc/graph/Type.h"
#include "fxcc/graph/Image.h"


namespace Ogl
{
	namespace Gut
	{
		struct Texture2DDesc1 :public Base
		{
			int m_Mipmap;
			Ogl::Gut::SamplerType m_SamplerType;
			Ogl::Gut::Image m_Image;

			void Write(const std::string& path);

			void Write(std::ofstream& ofs);

			void Read(const std::string& path);

			void Read(std::ifstream& ifs);

		};
	};
}