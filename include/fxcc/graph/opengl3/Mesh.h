#pragma once

#include "fxcc/graph/opengl3/pch.h"
#include "fxcc/graph/common/Mesh.h"

namespace fxcc
{
	namespace graph {

		namespace opengl3
		{
			struct Mesh :public fxcc::graph::common::Mesh
			{
				unsigned int m_VAO, m_VBO, m_EBO;
				
				void DrawElements() const
				{
					
				};
			};
		};
	};
};