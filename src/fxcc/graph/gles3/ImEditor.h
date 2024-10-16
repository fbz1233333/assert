#pragma once

#include "fxcc/graph/gles3/interface.h"
#include "fxcc/graph/ImEditor.h"

namespace fxcc
{
    namespace graph
    {
        template<>
        struct ImEditor<gles3::Impl>
        {
            void InitImGui();

            void BeginFrame();

            void RenderFrame();

            void DestoryImGui();

        };
    };
};
