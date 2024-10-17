#pragma once

#include "fxcc/graph/pch.h"

namespace Ogl
{
    namespace Gut
    {
        struct VertexWeight
        {
            unsigned int m_VertexId;
            float m_Weight;

            VertexWeight(aiVertexWeight *vw)
                : m_VertexId(vw->mVertexId),
                  m_Weight(vw->mWeight)
            {
            }
        };
    }
}