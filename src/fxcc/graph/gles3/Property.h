#pragma once

#include "fxcc/graph/pch.h"

namespace Ogl
{
    namespace Gut
    {
        struct Property
        {
            std::string m_Key;

            unsigned int m_Semantic;

            unsigned int m_Index;

            unsigned int m_DataLength;

            enum Type
            {

                _Float = 0x1,
                _Double = 0x2,
                _String = 0x3,
                _Integer = 0x4,
                _Buffer = 0x5,

            } m_Type;

            std::vector<unsigned char> m_Data;

            Property(aiMaterialProperty *property);
        };
    }
}