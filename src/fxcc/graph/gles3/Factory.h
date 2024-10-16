#pragma once

#include "fxcc/graph/gles3/interface.h"
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
