#pragma once

#include "fxcc/pch.h"

namespace fxcc
{
	namespace graph
	{
		namespace common
		{

			struct Mesh
			{
				struct Desc
				{
					enum Type
					{
						_MBXData_,
						_MBXFile_,
						_ModelPath_,
					} m_Type;

				} m_Desc;

				void Init()
				{

				}
			};
		};
	};
};