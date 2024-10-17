#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/Buffer.h"

namespace Ogl
{
	namespace Gut
	{

		struct VertexBuffer :public Ogl::Gut::Buffer
		{
			VertexBuffer()
				:Ogl::Gut::Buffer(GL_ARRAY_BUFFER)
			{

			}
			static void UnBind()
			{
				glBindBuffer(GL_ARRAY_BUFFER, 0);
			}
		};
	}
}
