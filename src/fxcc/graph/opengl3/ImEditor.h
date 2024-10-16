#pragma once

#include "fxcc/graph/opengl/pch.h"
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
