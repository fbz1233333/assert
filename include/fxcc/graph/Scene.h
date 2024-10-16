#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/Mesh.h"
#include "fxcc/graph/Material.h"

namespace fxcc
{
    namespace graph
    {

        template<typename Impl>
        struct MeshInnerData
        {
            std::shared_ptr<fxcc::graph::Mesh<Impl>> m_FixedMesh, m_SkinnedMesh;
        };
        template <typename Impl>
        struct Scene
        {
            std::vector<std::shared_ptr<MeshInnerData<Impl>>> m_MeshInnerDatas;
            std::vector<std::shared_ptr<Material<Impl>>> m_Materials;
        };
    };
};