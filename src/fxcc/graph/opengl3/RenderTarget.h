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

            bool Create()
            {

                return true;
            };
            void Begin() {

            };
            void End() {
            };

            virtual ~RenderTarget() {

            };
        };
    };
};
