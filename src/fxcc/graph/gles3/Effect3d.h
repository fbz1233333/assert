#pragma once

#include "fxcc/graph/gles3/interface.h"
#include "fxcc/graph/Effect3d.h"

namespace fxcc
{
    namespace graph
    {
        template <>
        struct Effect3d<gles3::Impl>
        {

        };
    };
};