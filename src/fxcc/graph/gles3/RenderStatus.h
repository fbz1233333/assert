#pragma once

#include "fxcc/graph/RenderDesc.h"
#include "fxcc/graph/Sampler.h"

namespace Ogl
{
    namespace Gut
    {
        struct RenderStatus
        {

            // Draw And Not Write Stencil
            DepthStencilDesc dessDefault;
            // Draw And Write Stencil;
            DepthStencilDesc dessDrawAndWriteStencil;
            // Draw not In Stencil Selectec
            DepthStencilDesc dessDrawBorder;

            BlendDesc bsDefault;
            RasterizerDesc rsDefault, rsNoCullface;

            BlendDesc bsFontRender;

            SamplerDesc ssFontRender, sdllrr, sdllcc;

            RenderStatus();
            static RenderStatus *g_inst;
            static RenderStatus *Inst();
        };
    };
}