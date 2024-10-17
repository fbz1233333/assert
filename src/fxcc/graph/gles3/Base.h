#pragma once

#include "fxcc/graph/pch.h"
#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>

namespace Ogl
{
	namespace Gut
	{

		struct Base
		{

			int m_BitFlag;

			int m_PickIndex;

			std::string m_Identity;

			Base() : m_BitFlag(0), m_Identity(generateUUID())
			{
			}

		private:
			std::string generateUUID()
			{
				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<> dis(0, 15); // 0-15 for hex digits

				std::stringstream ss;
				ss << std::hex; // Set to hexadecimal output

				for (int i = 0; i < 8; ++i)
				{
					ss << std::setw(1) << dis(gen);
				}
				ss << '-';
				for (int i = 0; i < 4; ++i)
				{
					ss << std::setw(1) << dis(gen);
				}
				ss << "-4"; // Version 4
				for (int i = 0; i < 3; ++i)
				{
					ss << std::setw(1) << dis(gen);
				}
				ss << "-";
				ss << std::setw(1) << (dis(gen) % 4 + 8); // Variant bits
				for (int i = 0; i < 3; ++i)
				{
					ss << std::setw(1) << dis(gen);
				}
				ss << '-';
				for (int i = 0; i < 12; ++i)
				{
					ss << std::setw(1) << dis(gen);
				}

				return ss.str();
			}
		};
	};
};