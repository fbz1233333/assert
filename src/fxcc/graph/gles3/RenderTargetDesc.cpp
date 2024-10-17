#include "fxcc/graph/RenderTargetDesc.h"

void Ogl::Gut::RenderTargetDesc::InitDesc2(int numTextures, int width, int height, int component, int hdr)
{

    auto &desc = m_Desc2;
    desc.m_ImageHD.m_Width = width;
    desc.m_ImageHD.m_Height = height;
    desc.m_ImageHD.m_NrComponent = component;
    desc.m_ImageHD.m_Hdr = hdr;
    desc.m_NumTextures = numTextures;
    m_Type = _desc2_;
};