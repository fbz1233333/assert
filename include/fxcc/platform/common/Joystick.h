#pragma once

#include "fxcc/platform/common/pch.h"

struct Joystick
{
	std::string m_Name;

	std::vector<unsigned char> m_States;
	
	glm::ivec2 m_HatValue;

	float m_Axes[6];

	void SetHatValue(int x, int y)
	{
		m_HatValue.x = x;
		m_HatValue.y = y;

		if (x != 0 || y != 0)
			ztclog::debug("hat value %d %d", x, y);
	}

	void SetAxes(int index, float value)
	{
		m_Axes[index] = value;
	}
	/*void SetAxes(int count, const float* axes)
	{
		m_LeftAxis = glm::vec2(axes[0], axes[1]);
		m_RightAxis = glm::vec2(axes[2], axes[3]);
		m_TriggerAxis.x = axes[4];
		m_TriggerAxis.y= axes[5];
		
		if (glm::length(m_LeftAxis) > 0.05f)
		{
			ztclog::debug("l %f %f", axes[0], axes[1]);
		}
		if (glm::length(m_RightAxis) > 0.04f)
		{
			ztclog::debug("r %f %f", axes[2], axes[3]);
		}
		if (glm::length(m_TriggerAxis) != 0)
		{
			ztclog::debug("trigger %f %f", axes[4], axes[5]);
		}
	}*/

	static std::vector<unsigned char> GetKeyState(int count, const unsigned char* btns)
	{
		std::vector<unsigned char> res;

		res.resize(count);
		for (int i = 0; i < count; i++)
		{
			res[i] = btns[i];
		}
		return res;
	}
	void SetStates(int count, const unsigned char* btns)
	{
		m_States = GetKeyState(count, btns);
		for (int i = 0; i < m_States.size(); i++)
		{
			if (m_States[i])
			{
				ztclog::debug("pressed %d", i);
			}
		}

	}
	void KeyCallback(JoystickButton btn, ActionType action)
	{
		if (btn == JoystickButton::A)
		{
			ztclog::debug("test() joy btn a is down");
		}
		if (btn == JoystickButton::B)
		{
			ztclog::debug("test() joy btn b is down");
		}
		if (btn == JoystickButton::X)
		{
			ztclog::debug("test() joy btn x is down");
		}
		if (btn == JoystickButton::Y)
		{
			ztclog::debug("test() joy btn y is down");
		}
		if (btn == JoystickButton::LB)
		{
			ztclog::debug("test() joy LB is down");
		}
		if (btn == JoystickButton::RB)
		{
			ztclog::debug("test() joy RB is down");
		}
		if (btn == JoystickButton::LSTICK)
		{
			ztclog::debug("test() joy LSTICK a is down");
		}
		if (btn == JoystickButton::RSTICK)
		{
			ztclog::debug("test() joy RSTICK a is down");
		}
		if (btn == JoystickButton::START)
		{
			ztclog::debug("test() joy start is down");
		}
		if (btn == JoystickButton::BACK)
		{
			ztclog::debug("test() joy back is down");
		}
		if (btn == JoystickButton::CENTER)
		{
			ztclog::debug("test center back is down");
		}
	}
};
