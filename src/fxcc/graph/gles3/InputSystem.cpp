#include "fxcc/graph/InputSystem.h"
using namespace Ogl::Gut;

void InputSystem::Clear()
{
	mouse.OnClearEvent();
	keyboard.OnClearEvent();
	joystick.OnClearEvent();
}

void InputSystem::OnScroll(double x, double y)
{
	mouse.OnScroll(x, y);
}

void InputSystem::OnCursorPos(double x, double y)
{
	mouse.OnCursorPos(x, y);
}

void InputSystem::OnMouse(int key, int action, int mode)
{
	mouse.OnMouse(key, action, mode);
}

void InputSystem::OnJoystick(int key, int e)
{
	joystick.OnJoystick(key, e);
}

void InputSystem::OnKeyCallback(int key, int scancode, int action, int mode)
{
	keyboard.OnKeyboard(key, scancode, action, mode);
}
