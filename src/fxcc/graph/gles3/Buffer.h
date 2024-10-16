#pragma once

#include "fxcc/graph/gles3/pch.h"

namespace fxcc
{

	namespace graph
	{
		namespace gles3
		{
			struct Buffer
			{
				unsigned int m_Id;
				unsigned int m_Target;

				Buffer(const unsigned int target) : m_Target(target)
				{
					Create();
				}
				void Bind() const
				{
					glBindBuffer(GetTarget(), m_Id);
				}
				void BufferDataBase(unsigned int binding) const
				{
					glBindBufferBase(GetTarget(), binding, m_Id);
				}
				void BufferData(const size_t &sz, const void *header, unsigned int usage = GL_STATIC_DRAW)
				{
					glBufferData(GetTarget(), sz, header, usage);
				}
				unsigned int GetTarget() const
				{
					return m_Target;
				}

				template <typename T>
				void BufferData(const std::vector<T> &ts, unsigned int usage = GL_STATIC_DRAW)
				{
					BufferData(ts.size() * sizeof(T), &ts[0], usage);
				}
				void Create()
				{
					glGenBuffers(1, &m_Id);
				}
				void Delete()
				{
					glDeleteBuffers(1, &m_Id);
				}

				virtual ~Buffer()
				{
					Delete();
				}
			};
		};
	};
};