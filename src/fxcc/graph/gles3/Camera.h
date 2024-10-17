#pragma once
#include "fxcc/graph/pch.h"
#include "fxcc/graph/Base.h"

namespace Ogl
{
    namespace Gut
    {
        struct Camera :public Base
        {

            std::string m_Name;
            glm::vec3 m_Position;
            glm::vec3 m_Up;
            glm::vec3 m_LookAt;
            float m_HorizontalFOV;
            float m_ClipPlaneNear;
            float m_ClipPlaneFar;
            float m_Aspect;

            Camera(aiCamera *camera);
        };
    }
}