#pragma once

#include "fxcc/graph/opengl3/pch.h"
#include "fxcc/graph/interface.h"

namespace fxcc
{
    namespace graph
    {
        template<>
        struct Factory<opengl3::Impl>
        {
        };
    
    };
};
