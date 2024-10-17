#pragma once

#include "fxcc/graph/pch.h"

namespace Ogl
{
    namespace Gut
    {
        struct Face
        {
            std::vector<unsigned int> m_Indices;
            Face(aiFace *face)
            {
                for (int i = 0; i < face->mNumIndices; i++)
                {
                    m_Indices.push_back(face->mIndices[i]);
                }
            }
        };
    }
};