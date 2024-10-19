#pragma once

#include "fxcc/pch.h"

namespace fxcc
{
	namespace platform
	{
		namespace common
		{
			struct App
			{
				struct Desc
				{
					glm::ivec2 m_Pos;
					glm::ivec2 m_Size;
					std::string m_Title;
					int m_Interval;

					bool m_Focused;
					bool m_Iconify;

					Desc() :m_Interval(0), m_Focused(false), m_Iconify(false), m_Pos(0), m_Size(glm::ivec2(800, 600))
					{

					}
				}m_Desc;
				App(const App::Desc& desc) :m_Desc(desc) {}

			};
		}
	}
}
