#pragma once

#include "fxcc/graph/pch.h"

#include <GLES3/gl3.h>

#define FXCC_GRAPH_GLES3_IMPL

namespace fxcc
{
    namespace graph
    {
        namespace gles3
        {
            struct Impl
            {
            };
        };
    };
    using GraphImpl = graph::gles3::Impl;
};
