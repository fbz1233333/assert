#pragma once
#include "fxcc/graph/gles3/pch.h"
#include "fxcc/graph/RenderTarget.h"

namespace fxcc
{
    namespace graph
    {
        template <>
        struct RenderTarget<gles3::Impl>
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
