#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/Buffer.h"

namespace Ogl
{
	namespace Gut
	{

		struct UniformBuffer :public Ogl::Gut::Buffer
		{
			struct Desc
			{
				unsigned int dataSize;

			} m_Desc;

			bool Init();

			UniformBuffer(const Desc& desc);
			
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