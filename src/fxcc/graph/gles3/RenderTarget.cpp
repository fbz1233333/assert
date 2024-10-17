#include "fxcc/graph/RenderTarget.h"
#include "RenderTarget.h"

Ogl::Gut::RenderTarget::RenderTarget(const RenderTargetDesc &desc)
    : m_Desc(desc)
{
    Init();
}

void Ogl::Gut::RenderTarget::Init()
{
    switch (m_Desc.m_Type)
    {
    case RenderTargetDescType::_desc1_:
        Init1();
        break;
    case RenderTargetDescType::_desc2_:
        Init2();
        break;
    default:
        std::cout << "cannot create render target from desc" << std::endl;
        break;
    }
};

void Ogl::Gut::RenderTarget::Init1()
{

    m_Textures.clear();
    m_Attachments.clear();

    auto& desc = m_Desc.m_Desc1;

    m_FrameBuffer.Bind();
    m_RenderBuffer.Bind();

    for (int i = 0; i < desc.m_Images.size(); i++)
    {
        Ogl::Gut::Texture2DDesc1 texDesc1;

        texDesc1.m_Mipmap = false;
        texDesc1.m_SamplerType = SamplerType::_sampler_2d_default_;
        texDesc1.m_Image = desc.m_Images[i];

        std::shared_ptr<Ogl::Gut::Texture2D> texture = std::make_shared<Ogl::Gut::Texture2D>(texDesc1);

        this->m_Textures.push_back(texture);

        int attachment = GL_COLOR_ATTACHMENT0 + i;

        texture->Bind();
        m_FrameBuffer.BufferTexture2D(attachment, GL_TEXTURE_2D, texture->m_Id);
        m_Attachments.push_back(attachment);
    }
    m_FrameBuffer.DrawBuffers(&m_Attachments[0], m_Attachments.size());

    //std::cout << "width " << desc.m_Width << "height  " << desc.m_Height << std::endl;

    m_RenderBuffer.Bind();
    m_RenderBuffer.Storage(GL_DEPTH24_STENCIL8, desc.m_ImageHD.m_Width, desc.m_ImageHD.m_Height);

    m_FrameBuffer.Bind();
    m_FrameBuffer.FrameRenderBuffer(GL_DEPTH_STENCIL_ATTACHMENT, m_RenderBuffer.m_Id);

    Ogl::Gut::FrameBuffer::CheckError();

    Ogl::Gut::RenderBuffer::UnBind();
    Ogl::Gut::FrameBuffer::UnBind();
    Ogl::Gut::Texture2D::UnBind();
}

void Ogl::Gut::RenderTarget::Init2()
{
    m_Desc.Parse2To1();
    Init1();
}

void Ogl::Gut::RenderTarget::Begin()
{
    m_FrameBuffer.Bind();
    Viewport();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Ogl::Gut::RenderTarget::Viewport()
{
    glViewport(0, 0, m_Desc.m_Desc1.m_ImageHD.m_Width, m_Desc.m_Desc1.m_ImageHD.m_Height);
}

void Ogl::Gut::RenderTarget::End()
{
    Ogl::Gut::FrameBuffer::UnBind();
}

void Ogl::Gut::RenderTarget::Framebuffersize(int w, int h)
{
    m_Desc.m_Desc1.m_ImageHD.m_Width = w;
    m_Desc.m_Desc1.m_ImageHD.m_Height = h;

    m_RenderBuffer.Bind();
    m_RenderBuffer.Storage(GL_DEPTH24_STENCIL8, w, h);

    for (auto &texture : m_Textures)
    {
        texture->Resize(w, h);
    }
}
