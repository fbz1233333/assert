#pragma once
#include "fxcc/graph/pch.h"
#include "fxcc/graph/Buffer.h"

namespace Ogl
{
	namespace Gut
	{

		struct IndexBuffer :public Ogl::Gut::Buffer
		{

			IndexBuffer()
				:Ogl::Gut::Buffer(GL_ELEMENT_ARRAY_BUFFER)
			{

			}
			static void UnBind()
			{
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			}

		};
	};
};