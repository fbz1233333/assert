#pragma once

#include "fxcc/graph/Type.h"
#include "fxcc/graph/Dictionary.h"

// Desc1 save the path
namespace Ogl
{
	namespace Gut
	{

		struct MeshDesc3:public Base
		{
			std::string m_Path;
			MeshDesc3() = default;

			MeshDesc3(const std::string& path)
				: m_Path(path)
			{
			}
		};
	}
}