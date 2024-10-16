#pragma once

#include "fxcc/graph/gles3/pch.h"
#include "fxcc/graph/Factory.h"

namespace fxcc
{
    namespace graph
    {
        template<>
        struct Factory<gles3::Impl>
        {
        };
    
    };
};
