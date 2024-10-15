#pragma once

#include "fxcc/graph/pch.h"

namespace fxcc
{
    namespace graph
    {
        struct Texture2D
        {
            virtual void Init() = 0;
            virtual ~Texture2D() = 0;
        };
    };
};