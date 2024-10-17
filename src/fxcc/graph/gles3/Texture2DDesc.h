#pragma once

#include "fxcc/graph/Type.h"
#include "fxcc/graph/Texture2DDesc1.h"
#include "fxcc/graph/Texture2DDesc2.h"
#include "fxcc/graph/Texture2DDesc3.h"
#include "fxcc/graph/Image.h"

namespace Ogl
{
	namespace Gut
	{
   

        struct Texture2DDesc:public Base
        {
            Texture2DDesc1 m_Desc1;
            Texture2DDesc2 m_Desc2;
            Texture2DDesc3 m_Desc3;
            Texture2DDescType m_Type;

            void Parse3To1();

            void Parse2To1();

            void Package1To2(const std::string& path);

            Texture2DDesc() = default;
            Texture2DDesc(const Texture2DDesc1& d1) : m_Desc1(d1), m_Type(Texture2DDescType::_texture_2d_desc_origin_data_) {};
            Texture2DDesc(const Texture2DDesc2& d2) : m_Desc2(d2), m_Type(Texture2DDescType::_texture_2d_desc_imaga_desc_) {};
            Texture2DDesc(const Texture2DDesc3& d3) : m_Desc3(d3), m_Type(Texture2DDescType::_texture_2d_desc_origin_file_) {};

        };
	};
}