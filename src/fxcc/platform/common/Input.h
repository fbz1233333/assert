#pragma once


#include "fxcc/platform/common/pch.h"
#include "fxcc/platform/common/Joystick.h"
#include "fxcc/platform/common/Mouse.h"
#include "fxcc/platform/common/Keyboard.h"


struct Input
{
	fxcc::platform::common::Mouse m_Mouse;
	fxcc::platform::common::Keyboard m_Keyboard;

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
	};

	std::vector<int> GetJoystickNos();
	
	void SetJoystickHat(const int jId, int x, int y)
	{
		if (m_Joysticks.find(jId) == m_Joysticks.end())
		{
			return;
		}
		m_Joysticks[jId].SetHatValue(x, y);

	}

	void SetJoystickAxes(const int jId, int index, const float value) 
	{
		if (m_Joysticks.find(jId) == m_Joysticks.end())
		{
			return;
		}
		m_Joysticks[jId].SetAxes(index, value);

	}
	
	void SetJoystickButton(const int jId, JoystickButton btn, ActionType action)
	{
		if (m_Joysticks.find(jId) == m_Joysticks.end())
		{
			return;
		}
		m_Joysticks[jId].KeyCallback(btn, action);

	};
	void StepJoystickTick(const int jId, const int count, unsigned char* btn)
	{
		if (m_Joysticks.find(jId) == m_Joysticks.end())
		{
			return;
		}
		m_Joysticks[jId].SetStates(count, btn);
	}

	void KeyCallback(KeyCode keyCode, ActionType action);


	void CursorPos(int x, int y)
	{
		ztclog::info("Cursor %d %d", x,y);
	};

	void Scroll(int x, int y)
	{
		ztclog::info("Scroll %d %d", x,y );
	};

	void MouseCallBack(MouseButton mouse, ActionType action);

	void JoysticCallback(int joy, int event, const char* name);


};