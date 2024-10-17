#pragma once
#include "fxcc/graph/pch.h"
#include "fxcc/graph/VertexWeight.h"

namespace Ogl
{
    namespace Gut
    {
        struct Bone
        {
            std::string m_Name;
            unsigned int m_Index;
            std::vector<VertexWeight> m_Weights;
            glm::mat4 m_OffsetMatrix;

            Bone(aiBone *bone);
        };
    }
}