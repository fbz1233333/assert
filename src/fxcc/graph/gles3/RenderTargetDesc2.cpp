#include "fxcc/graph/RenderTargetDesc2.h"

Ogl::Gut::RenderTargetDesc2::RenderTargetDesc2(const Ogl::Gut::Image::HD &hd, const int &numTextures)
    : m_NumTextures(numTextures), m_ImageHD(hd)
{
}