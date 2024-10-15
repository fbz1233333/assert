#pragma once

#include "fxcc/graph/pch.h"

namespace fxcc
{
    namespace graph
    {
        struct Effect2d
        {
            virtual void LoadGlsl() = 0;

            virtual void LoadHlsl() = 0;

            virtual void Init() = 0;

            virtual void Begin() = 0;

            virtual void End() = 0;
        };
    };
};