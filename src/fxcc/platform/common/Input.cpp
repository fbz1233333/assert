#include "fxcc/platform/common/Input.h"

std::vector<int> Input::GetJoystickNos()
{
	std::vector<int> nos;
	for (const auto& it : m_Joysticks)
	{
		nos.push_back(it.first);
	}
	return nos;
};

void Input::KeyCallback(KeyCode keyCode, ActionType action)
{
	ztclog::debug("KeyCallback scancode %d action %d ", keyCode, action);
	
	if (keyCode == KeyCode::B && action == ActionType::Down)
	{
		ztclog::debug("test() B down");
	}
	if (keyCode == KeyCode::Z && action == ActionType::Down)
	{
		ztclog::debug("test() Z down");
	}
	if (keyCode == KeyCode::LEFTSHIFT && action == ActionType::Down)
	{
		ztclog::debug("test() left shift down");
	};
	if (keyCode == KeyCode::LEFTCTRL && action == ActionType::Down)
	{
		ztclog::debug("test() left ctrl down");
	};
	if (keyCode == KeyCode::RIGHTSHIFT && action == ActionType::Down)
	{
		ztclog::debug("test() right shift");
	};
	if (keyCode == KeyCode::RIGHTCTRL && action == ActionType::Down)
	{
		ztclog::debug("test() right ctrl");
	};
};

void Input::MouseCallBack(MouseButton mouse, ActionType action)
{
	
	ztclog::info("MouseCallback key %d action %d", mouse, action);
	if (mouse == MouseButton::LEFT && action == ActionType::Down)
	{
		ztclog::info("test() left down");
	}
	if (mouse == MouseButton::RIGHT && action == ActionType::Up)
	{
		ztclog::info("test() right up");
	}

	if (mouse == MouseButton::MIDDLE && action == ActionType::Up)
	{
		ztclog::debug("test() middle up");
	}
	if (mouse == MouseButton::BUTTON1 && action == ActionType::Down)
	{
		ztclog::info("test() btn1 down");
	}

	if (mouse == MouseButton::BUTTON2 && action == ActionType::Down)
	{
		ztclog::info("test() btn2 down");
	}
};


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