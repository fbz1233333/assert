#include "fxcc/graph/Texture2DDesc.h"

void Ogl::Gut::Texture2DDesc::Parse3To1()
{
    m_Desc1.Read(m_Desc3.m_Path);
};

void Ogl::Gut::Texture2DDesc::Parse2To1()
{
    m_Desc1.m_Image = Ogl::Gut::Image(m_Desc2.m_ImageDesc);
    m_Desc1.m_Mipmap = m_Desc2.m_Mipmap;
    m_Desc1.m_SamplerType = m_Desc2.m_SamplerType;
};

void Ogl::Gut::Texture2DDesc::Package1To2(const std::string& path)
{
    m_Desc2.m_Mipmap = m_Desc1.m_Mipmap;
    m_Desc2.m_SamplerType = m_Desc1.m_SamplerType;

};