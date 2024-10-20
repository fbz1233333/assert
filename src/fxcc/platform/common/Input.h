#pragma once


#include "fxcc/pch.h"
#include "fxcc/platform//common/Joystick.h"
#include "fxcc/platform/common/Mouse.h"


struct Input
{
	std::map<int, Joystick> m_Joysticks;
	
	struct IO
	{
		bool KeyCtrl;
		bool KeyShift;
		bool KeyAlt;
		IO()
			:KeyCtrl(false), KeyShift(false), KeyAlt(false)
		{

		} 
	} m_IO;

	IO& GetIO()
	{
		return m_IO;
	}
	std::vector<int> GetJoystickNos()
	{
		std::vector<int> nos;
		for (const auto& it : m_Joysticks)
		{
			nos.push_back(it.first);
		}
		return nos;
	};
	
	void SetJoystickAxes(const int jId, int count, const float* axes) 
	{
		if (m_Joysticks.find(jId) == m_Joysticks.end())
		{
			return;
		}
		m_Joysticks[jId].SetAxes(count, axes);

	}
	void SetJoystickStates(const int jId, int count, const unsigned char* btns)
	{
		if (m_Joysticks.find(jId) == m_Joysticks.end())
		{
			return;
		}
		m_Joysticks[jId].SetStates(count, btns);

	}

	void KeyCallback(int scancode, int action)
	{
		// Only use the scancode 
		ztclog::info("KeyCallback scancode %d action %d ", scancode, action);

		if (scancode == 29 || scancode == 285)
		{
			m_IO.KeyCtrl = action;
		}
		if (scancode == 42 || scancode == 310)
		{
			m_IO.KeyShift = action;
		}
		if (scancode == 56 || scancode == 312)
		{
			m_IO.KeyAlt = action;
		}
	};

	void CursorPos(int x, int y)
	{
		ztclog::info("Cursor %d %d", x,y);
	};

	void Scroll(int x, int y)
	{
		ztclog::info("Scroll %d %d", x,y );
	};

	void MouseCallBack(int key, int action)
	{
		ztclog::info("MouseCallback key %d action %d", key, action);
	};

	void JoysticCallback(int joy, int event, const char* name);


};