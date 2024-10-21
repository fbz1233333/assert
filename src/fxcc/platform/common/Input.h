#pragma once


#include "fxcc/pch.h"
#include "fxcc/platform/common/Joystick.h"
#include "fxcc/platform/common/Mouse.h"
#include "fxcc/platform/common/Keyboard.h"

enum class KeyCode {
	UNKNOWN = -1,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	NUM0,
	NUM1,
	NUM2,
	NUM3,
	NUM4,
	NUM5,
	NUM6,
	NUM7,
	NUM8,
	NUM9,
	ESC,
	ENTER,
	SPACE,
	BACKSPACE,
	LEFT,
	RIGHT,
	UP,
	DOWN,
	LEFTALT, 
	LEFTSHIFT, 
	LEFTCTRL, 
	RIGHTALT,
	RIGHTSHIFT,
	RIGHTCTRL,
	COUNT
};

enum class MouseButton {
	UNKNOWN = -1,
	LEFT,
	RIGHT,
	MIDDLE,
	BUTTON1,
	BUTTON2,
	COUNT
};
enum class JoystickButton {
	UNKNOWN = -1,
	A,
	B,
	X,
	Y,
	LB,
	RB,
	LT,
	RT,
	SELECT,
	START,
	COUNT
};

enum ActionType
{
	Up = 0,
	Down = 1, 
};

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
	};

	std::vector<int> GetJoystickNos();
	
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
	};

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