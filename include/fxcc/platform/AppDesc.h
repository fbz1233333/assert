#pragma once

#include "fxcc/platform/pch.h"

namespace fxcc
{
    namespace platform
    {
        struct AppDesc
        {
            glm::ivec2 m_Pos;
            glm::ivec3 m_Size;
            std::string m_Title;
        };
    };
};