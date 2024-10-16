#pragma once
#include "fxcc/graph/opengl3/interface.h"
#include "fxcc/graph/interface.h"

namespace fxcc
{
    namespace graph
    {
        template <>
        struct RenderTarget<opengl3::Impl>
        {

            bool Create();

            void Begin();

            void End();

            void Release();

            virtual ~RenderTarget();
        };
    };
};
