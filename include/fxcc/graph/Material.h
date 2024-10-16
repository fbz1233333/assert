#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/Texture2D.h"

#define FXCC_GRAPH_MATERIAL_TEXTURE_TYPE 32

namespace fxcc
{
    namespace graph
    {
        template<typename Impl>
        struct Material
        {
            std::string m_Name;
            std::vector<std::shared_ptr<fxcc::graph::Texture2D>> m_Textures[FXCC_GRAPH_MATERIAL_TEXTURE_TYPE];
        };
    };
};