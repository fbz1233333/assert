#pragma once

#include "fxcc/platform/core/pch.h"

namespace fxcc
{
    namespace platform
    {
        namespace core
        {
            struct AppDesc
            {
                glm::ivec2 m_Pos;
                glm::ivec2 m_Size;
                std::string m_Title;
                bool m_Interval;
                // what should the to do
            };
        };
    };
};