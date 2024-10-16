#pragma once

#include "fxcc/graph/gles3/interface.h"
#include "fxcc/graph/gles3/Buffer.h"

namespace fxcc
{
	namespace graph
	{
		namespace gles3
		{

			struct UniformBuffer : public Buffer
			{
				struct Desc
				{
					unsigned int dataSize;

				} m_Desc;

				bool Init();

				UniformBuffer(const Desc &desc);

				UniformBuffer(const size_t &sz);

				template <typename T>
				bool CreateFrom()
				{

					m_Desc.dataSize = sizeof(T);

					Init();
					return true;
				}

				void Upload(const void *data, size_t off, size_t len) const;
				void Upload(const void *data, size_t len) const;

				void Binding(unsigned int binding);

				template <typename T>
				void Upload(const T &t) const
				{
					Upload((void *)&t, sizeof(T));
				}
				static void UnBind()
				{
					glBindBuffer(GL_ARRAY_BUFFER, 0);
				}
			};
		};
	};
};