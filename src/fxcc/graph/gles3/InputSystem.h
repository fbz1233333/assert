#pragma once

#include "fxcc/graph/Mouse.h"
#include "fxcc/graph/Keyboard.h"
#include "fxcc/graph/Joystick.h"

namespace Ogl
{
	namespace Gut
	{


struct InputSystem
{
	Mouse mouse;
	Keyboard keyboard;
	Joystick joystick;
	InputSystem() = default;

	void Clear();
	void OnScroll(double x, double y);
	void OnCursorPos(double x, double y);
	void OnMouse(int key, int action,int mode);
	void OnJoystick(int key, int e);
	void OnKeyCallback(int key, int scancode, int action, int mode);
};

	}

}
