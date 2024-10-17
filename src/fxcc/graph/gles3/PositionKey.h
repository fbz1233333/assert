#pragma once

#include "fxcc/graph/pch.h"

namespace Ogl
{
    namespace Gut
    {
        struct PositionKey
        {
            double m_Time;

            glm::vec3 m_Value;

            PositionKey(aiVectorKey* key)
            {
                m_Time=key->mTime;
                Load(key->mValue, m_Value);
                        }
        };
    }
}