#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/Texture2D.h"

#define FXCC_MAX_TEXTURE_NUM 32;

namespace fxcc
{
    namespace graph
    {
        template <typename Impl>
        struct Material
        {
            std::string m_Name;
            std::vector<std::shared_ptr<Texture2D<Impl>>> m_Textures[FXCC_MAX_TEXTURE_NUM];
        };
    };
}