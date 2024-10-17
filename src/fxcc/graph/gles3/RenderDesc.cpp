#include "fxcc/graph/RenderDesc.h"

using namespace Ogl::Gut;

void BlendDesc::Clear() const
{
    if (enableBlend)
    {
        glEnable(GL_BLEND);
        glBlendFunc(sfactor, dfactor);
    }
    else
    {
        glDisable(GL_CULL_FACE);
    }
}

void RasterizerDesc::Clear() const
{
    if (enableCullFace)
    {
        glEnable(GL_CULL_FACE);
        glCullFace(cullFace);
        glFrontFace(frontFace);
    }
    else
    {
        glDisable(GL_CULL_FACE);
    }
}

void DepthStencilDesc::Clear() const
{
    if (enableStencilTest)
    {
        glEnable(GL_STENCIL_TEST);
        glStencilFunc(stencilFunc, stencilRef, stencilRefMask);
        glStencilOp(stencilFail, stencilZFail, stencilZPass);
        glStencilMask(stencilMask);
    }
    else
    {
        glDisable(GL_STENCIL_TEST);
    }

    if (enableDepthTest)
    {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(this->depthFunc);
    }
    else
    {
        glDisable(GL_DEPTH_TEST);
    }
}