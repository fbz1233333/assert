#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/Base.h"

namespace Ogl
{
	namespace Gut
	{

		struct VertexArray :public Base
		{

			unsigned int m_Id;

			VertexArray();
			void Bind() const;
			void ArrtibPointer(unsigned index, int size, unsigned type, bool normalized, int stride, const void* pointer = 0);
			void EnablePointer(unsigned int index);
			void AttribIPointer(unsigned int index, int size, int type, int stride, const void* pointer = 0);
			void DrawElements(unsigned int mode, int count, int type, const void* indices = 0) const;
			void DrawArrays(GLenum mode, GLint first, GLsizei count) const;
			void DrawInstanced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount) const;

			static void UnBind();
			virtual ~VertexArray();

		};
	};
};