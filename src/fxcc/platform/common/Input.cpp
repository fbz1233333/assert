#include "fxcc/platform/common/Input.h"

void Input::JoysticCallback(int joy, int event, const char* name)
{
	if (name)
	{
		ztclog::debug("Joystic link %d %d %s", joy, event, name);
		auto& joystick = m_Joysticks[joy];
		joystick.m_Name = name;
	}
	else
	{
		ztclog::debug("Joystic disconnected %d %d ", joy, event);
		auto it = m_Joysticks.find(joy);
		if (it != m_Joysticks.end())
		{
			m_Joysticks.erase(it);
		};
	}

};