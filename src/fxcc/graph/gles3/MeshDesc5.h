#pragma once

#include "fxcc/graph/Type.h"
#include "fxcc/graph/Dictionary.h"
#include "fxcc/graph/Base.h"

namespace Ogl
{
	namespace Gut
	{

		struct MeshDesc5:public Base
		{
			std::string m_Path;
			int m_Index;
			VertexType m_Type;

			MeshDesc5()
				:m_Index(0), m_Type(VertexType::_vertex_none_)
			{

			}
			MeshDesc5(const std::string& path, int index, VertexType type) :m_Path(path), m_Index(index), m_Type(type)
			{

			}

		
		};
	}
}