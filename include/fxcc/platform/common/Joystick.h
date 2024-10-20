#pragma once

#include "fxcc/pch.h"

struct Joystick
{
	std::string m_Name;

	std::vector<int> m_States;
	
	std::vector<float> m_Axes;

	void SetAxes(int count, const float* axes)
	{
		m_Axes.clear();
		m_Axes.resize(count);
		for (int i = 0; i < count; i++)
		{
			m_Axes[i] = axes[i];
			if (m_Axes[i] != -1 && m_Axes[i] != 0)
			{
				std::cout << m_Axes[i] << std::endl;
			}
		}

	}

	void SetStates(int count,const unsigned char* btns)
	{
		m_States.clear();
		m_States.resize(count);
		for (int i = 0; i < count; i++)
		{
			m_States[i] = btns[i];

			if (btns[i])
			{
				ztclog::debug("clicked %d", i);
			}
		}

	}

};
