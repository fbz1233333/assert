#pragma once

#include "fxcc/graph/MeshData.h"
#include "fxcc/graph/Material.h"

namespace fxcc
{
    namespace graph
    {
        template<typename Impl>
        struct Scene
        {
            std::string m_Name;
            std::vector<std::shared_ptr<MeshData<Impl>>> m_Meshes;
            std::vector<std::shared_ptr<Material<Impl>>> m_Materials;

        };
    };
};