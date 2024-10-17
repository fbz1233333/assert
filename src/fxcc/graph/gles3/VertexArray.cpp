#include "fxcc/graph/VertexArray.h"

using namespace Ogl::Gut;

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_Id);
}

void VertexArray::Bind() const
{
	glBindVertexArray(m_Id);
}

void VertexArray::ArrtibPointer(unsigned index, int sz, unsigned type, bool normalized, int stride, const void* pointer)
{
	glVertexAttribPointer(index, sz, type, normalized, stride, pointer);
}

void VertexArray::EnablePointer(unsigned int index)
{
	glEnableVertexAttribArray(index);
}

void VertexArray::AttribIPointer(unsigned int index, int size, int type, int stride, const void* pointer)
{
	glVertexAttribIPointer(index, size, type, stride , pointer);

}

void VertexArray::UnBind()
{
	glBindVertexArray(0);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_Id);
}


void VertexArray::DrawElements(unsigned int mode, int count, int type, const void* indices) const
{
	glDrawElements(mode, count, type, indices);
}

void Ogl::Gut::VertexArray::DrawArrays(GLenum mode, GLint first, GLsizei count) const
{
	glDrawArrays(mode, first, count);
}

void VertexArray::DrawInstanced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount) const
{
	glDrawElementsInstanced(mode, count, type, indices, instancecount);
}
