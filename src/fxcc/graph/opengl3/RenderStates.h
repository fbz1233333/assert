#pragma once
#include "fxcc/graph/opengl3/pch.h"
#include "fxcc/graph/interface.h"

namespace fxcc
{
    namespace graph
    {
        template <>
        struct RenderStates<opengl3::Impl>
        {
            static void ClearPipelineState(const PipelineState<opengl3::Impl> &pipelineState);
           
        };
    };
};
