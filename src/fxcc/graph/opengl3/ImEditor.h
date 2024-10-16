#pragma once

#include "fxcc/graph/opengl3/interface.h"
#include "fxcc/graph/interface.h"

namespace fxcc
{
    namespace graph
    {
        template<>
        struct ImEditor<opengl3::Impl>
        {
            void InitImGui();

            void BeginFrame();

            void RenderFrame();

            void DestoryImGui();

        };

    };
};
