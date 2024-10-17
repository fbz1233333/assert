#include "fxcc/graph/Keyboard.h"

using namespace Ogl::Gut;

Keyboard::Keyboard()
{
}


void Keyboard::OnKeyboard(int key, int scancode, int action, int mode)
{
	Event newE;
	newE.key = key;
	newE.scancode = scancode;
	newE.action = action;
	newE.mode = mode;
	this->events.push_back(newE);

	if (action == 0)
	{
		states[key] = false;
	}
	if (action == 1)
	{
		states[key] = true;
	}
	if (action == 2)
	{
	}

}

bool Keyboard::KeyPressingState(int c)
{
	if (c > sizeof(this->states))
	{
		return false;
	}
	return states[c];
}

bool Keyboard::KeyEvent_(int key, int mode, int action)
{
	for (const auto en : events)
	{
		if (en.action == action && en.mode == mode && en.key == key)
		{
			return true;
		}
	}
	return false;
}

bool Keyboard::KeyDown_(int key, int mode)
{
	return KeyEvent_(key, mode, 1);
}

bool Keyboard::KeyRelease_(int key, int mode)
{
	return KeyEvent_(key, mode, 0);
}

bool Keyboard::KeyPress_(int key, int mode)
{
	return KeyEvent_(key, mode, 2);
}

void Keyboard::OnClearEvent()
{
	this->events.clear();
}
