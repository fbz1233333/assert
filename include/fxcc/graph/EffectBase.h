#pragma once

#include "fxcc/graph/PipelineState.h"

namespace fxcc
{
    namespace graph
    {
        struct EffectBase
        {
            fxcc::graph::PipelineState m_PipelineState;
            void Begin();
        };
    };
};