#pragma once
#include "fxcc/graph/pch.h"
#include "fxcc/graph/Type.h"

namespace Ogl
{
    namespace Gut
    {
        struct Light
        {
            std::string m_Name;

            LightSourceType m_LightType;

            static std::vector<std::string> g_sourceTypesStrs;

            glm::vec3 m_Position;

            glm::vec3 m_Direction;
            
            glm::vec3 m_Up;
            
            float m_AttenuationConstant;
            
            float m_AttenuationLinear;
            
            float m_AttenuationQuadratic;

            glm::vec3 m_ColorDiffuse;

            glm::vec3 m_ColorSpecular;
            
            glm::vec3 m_ColorAmbient;

            float m_AngleInnerCone;
            
            float m_AngleOuterCone;

            glm::vec2 m_Size;

            Light(aiLight *light);
        };
    }
}