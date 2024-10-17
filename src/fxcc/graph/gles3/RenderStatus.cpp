#include "fxcc/graph/RenderStatus.h"

using namespace Ogl::Gut;

RenderStatus* RenderStatus::g_inst = 0;

Ogl::Gut::RenderStatus::RenderStatus()
{
    bsFontRender.enableBlend = true;
    bsFontRender.sfactor = GL_SRC_ALPHA;
    bsFontRender.dfactor = GL_ONE_MINUS_SRC_ALPHA;

    ssFontRender.wrapS = GL_CLAMP_TO_EDGE;
    ssFontRender.wrapT = GL_CLAMP_TO_EDGE;
    ssFontRender.minFilter = GL_LINEAR;
    ssFontRender.magFilter = GL_LINEAR;

    rsNoCullface.enableCullFace = false;

    {
        Ogl::Gut::DepthStencilDesc& desc = dessDrawAndWriteStencil;
        desc.enableDepthTest = true;
        desc.depthFunc = GL_LESS;

        desc.enableDepthTest = true;
        desc.enableStencilTest = true;
        desc.stencilFail = GL_KEEP;
        desc.stencilZFail = GL_KEEP;
        desc.stencilZPass = GL_REPLACE;
        desc.stencilFunc = GL_ALWAYS;
        desc.stencilRef = 1;
        desc.stencilRefMask = 0xFF;
    }

    {

        Ogl::Gut::DepthStencilDesc& desc = this->dessDefault;
        desc.enableDepthTest = true;
        desc.depthFunc = GL_LESS;

        desc.enableDepthTest = false;

    }

    {
        Ogl::Gut::DepthStencilDesc& desc = this->dessDrawBorder;

        desc.enableDepthTest = false;
        desc.enableStencilTest = true;
        desc.stencilFunc = GL_NOTEQUAL;
        desc.stencilRef = 1;
        desc.stencilRefMask = 0xFF;
    }
    {

        auto& desc = this->sdllrr;
        desc.minFilter = GL_LINEAR;
        desc.magFilter = GL_LINEAR;
        desc.wrapS = GL_REPEAT;
        desc.wrapT = GL_REPEAT;

    }

    {
        auto& desc = this->sdllcc;
        desc.wrapS = GL_CLAMP_TO_EDGE;
        desc.wrapT = GL_CLAMP_TO_EDGE;
        desc.minFilter = GL_LINEAR;
        desc.magFilter = GL_LINEAR;
    }
}

RenderStatus *RenderStatus::Inst()
{
    if (g_inst == 0)
    {
        g_inst = new RenderStatus();
    }
    return g_inst;
}

