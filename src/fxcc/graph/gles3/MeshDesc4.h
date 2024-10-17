#pragma once

#include "fxcc/graph/Type.h"
#include "fxcc/graph/Dictionary.h"

namespace Ogl
{
	namespace Gut
	{
		// Desc2 Save the path
		struct MeshDesc4:public Base
		{
			std::string m_Path;
			MeshDesc4() = default;
			MeshDesc4(const std::string& path) : m_Path(path)
			{
			}
		};
	}
}