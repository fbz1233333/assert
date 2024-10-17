#include "fxcc/graph/RenderBuffer.h"

using namespace Ogl::Gut;

void RenderBuffer::Create()
{
    glGenRenderbuffers(1, &m_Id);
}

RenderBuffer::~RenderBuffer()
{
    glDeleteRenderbuffers(1, &m_Id);
}

Ogl::Gut::RenderBuffer::RenderBuffer()
{
    Create();
}


Ogl::Gut::RenderBuffer::RenderBuffer(unsigned int internalFormat, int width, int height)
{
    Storage(internalFormat, width, height);
}

void RenderBuffer::Storage(unsigned int internalFormat, int width, int height)
{
    glRenderbufferStorage(GL_RENDERBUFFER, internalFormat, width, height);
}
void RenderBuffer::Bind()
{
    glBindRenderbuffer(GL_RENDERBUFFER, m_Id);
}

void Ogl::Gut::RenderBuffer::UnBind()
{
    glBindRenderbuffer(GL_RENDERBUFFER, 0);

}
