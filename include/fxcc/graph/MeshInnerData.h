#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/Mesh.h"

namespace fxcc
{
    namespace graph
    {

        template <typename Impl>
        struct MeshInnerData
        {
            std::shared_ptr<fxcc::graph::Mesh<Impl>> m_FixedMesh, m_SkinnedMesh;
        };
    }
};