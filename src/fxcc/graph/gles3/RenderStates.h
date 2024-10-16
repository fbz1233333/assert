#pragma once
#include "fxcc/graph/gles3/interface.h"
#include "fxcc/graph/RenderStates.h"
#include "fxcc/graph/PipelineState.h"

namespace fxcc
{
    namespace graph
    {
        template <>
        struct RenderStates<gles3::Impl>
        {
            static void ClearPipelineState(const PipelineState &pipelineState);

        };
    };
};
