#include "fxcc/graph/UniformBuffer.h"

void Ogl::Gut::UniformBuffer::Upload(const void *data, size_t off, size_t len) const
{
    Bind();
    glBufferSubData(GL_UNIFORM_BUFFER, off, len, data);

    UnBind();
}

void Ogl::Gut::UniformBuffer::Upload(const void *data, size_t len) const
{
    Upload(data, 0, len);
}

void Ogl::Gut::UniformBuffer::Binding(unsigned int binding)
{
    BufferDataBase(binding);
}

bool Ogl::Gut::UniformBuffer::Init()
{
    Ogl::Gut::Buffer::Bind();
    BufferData(m_Desc.dataSize, 0, GL_DYNAMIC_DRAW);

    return true;
};

Ogl::Gut::UniformBuffer::UniformBuffer(const Desc& desc) 
    :Ogl::Gut::Buffer(GL_UNIFORM_BUFFER), m_Desc(desc)
{

    Init();
}

Ogl::Gut::UniformBuffer::UniformBuffer(const size_t &sz)
    :Ogl::Gut::Buffer(GL_UNIFORM_BUFFER)
{
    m_Desc.dataSize = sz;

    Ogl::Gut::Buffer::Bind();
    BufferData(m_Desc.dataSize, 0, GL_DYNAMIC_DRAW);
}

