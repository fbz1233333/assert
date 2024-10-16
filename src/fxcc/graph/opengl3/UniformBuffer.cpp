#include "fxcc/graph/opengl3/UniformBuffer.h"

using namespace fxcc::graph::opengl3;

void UniformBuffer::Upload(const void *data, size_t off, size_t len) const
{
    Bind();
    glBufferSubData(GL_UNIFORM_BUFFER, off, len, data);

    UnBind();
}

void UniformBuffer::Upload(const void *data, size_t len) const
{
    Upload(data, 0, len);
}

void UniformBuffer::Binding(unsigned int binding)
{
    BufferDataBase(binding);
}

bool UniformBuffer::Init()
{
    Buffer::Bind();
    BufferData(m_Desc.dataSize, 0, GL_DYNAMIC_DRAW);

    return true;
};

UniformBuffer::UniformBuffer(const Desc& desc) 
    :Buffer(GL_UNIFORM_BUFFER), m_Desc(desc)
{

    Init();
}

UniformBuffer::UniformBuffer(const size_t &sz)
    :Buffer(GL_UNIFORM_BUFFER)
{
    m_Desc.dataSize = sz;

    Buffer::Bind();
    BufferData(m_Desc.dataSize, 0, GL_DYNAMIC_DRAW);
}

