#pragma once

#include "fxcc/platform/common/pch.h"

namespace fxcc
{
    namespace platform
    {
        namespace common
        {
            struct AppDesc
            {
                glm::ivec2 m_Pos;
                glm::ivec2 m_Size;
                std::string m_Title;
                bool m_Focused;
                bool m_Interval;
                bool m_Iconify;

                AppDesc() :m_Interval(false), m_Focused(false), m_Iconify(false), m_Pos(0), m_Size(glm::ivec2(800, 600))
                {

                }

                // what should the to do
            };
        };
    };
};