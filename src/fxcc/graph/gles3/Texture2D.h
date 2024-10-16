#pragma once

#include "fxcc/graph/gles3/pch.h"
#include "fxcc/graph/Texture2D.h"

namespace fxcc
{
    namespace graph
    {
        template<>
        struct Texture2D<gles3::Impl>
        {

            unsigned int m_Id;
        };
    };
}