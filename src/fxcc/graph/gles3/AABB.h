#pragma once

#include "fxcc/graph/pch.h"

namespace Ogl
{
    namespace Gut
    {
        struct AABB
        {
            glm::vec3 m_Min = glm::vec3(0.0f);
            glm::vec3 m_Max = glm::vec3(0.0f);
            glm::vec3 m_Center;
            glm::vec3 m_HalfExtends;

            AABB() = default;
            
            AABB(const aiAABB& aabb);
            AABB(const glm::vec3& minVal, const glm::vec3& maxVal);

            void CalCenterHalfExt();
        };
    }
};