#pragma once

#include "fxcc/graph/pch.h"

namespace Ogl
{
    namespace Gut
    {
        struct RotationKey
        {
            double m_Time;

            glm::quat m_Value;

            RotationKey(aiQuatKey *key)
            {
                m_Time = key->mTime;
                Load(key->mValue, m_Value);
            }
        };
    }
}