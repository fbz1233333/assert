#include "fxcc/graph/Mouse.h"

using namespace Ogl::Gut;

Mouse::Mouse()
{
}

bool Mouse::MousePressing(int i)
{
	if (i < sizeof(this->states))
	{
		return states[i];
	}
	return false;
}

std::vector<Mouse::Event> Mouse::Events() const
{
	return this->events;
}

glm::vec2 Mouse::CurrenPos() const
{
	return this->currentPos;
}

glm::vec2 Mouse::ScrollDelta() const
{
	return this->scrollDelta;
}

void Mouse::OnScroll(double x, double y)
{
	this->scrollDelta.x = x;
	this->scrollDelta.y = y;
}

void Mouse::OnCursorPos(double x, double y)
{
	currentPos.x = x;
	currentPos.y = y;
}

void Mouse::OnMouse(int key, int action, int mode)
{
	Mouse::Event newE;
	newE.key = key;
	newE.action = action;
	newE.mode = mode;
	this->events.emplace_back(newE);

	if (action == 0)
	{
		this->states[key] = false;

	}
	else if (action == 1)
	{
		this->states[key] = true;

	}

}

bool Mouse::MouseEvent(int key, int mode, int action)
{
	for (const auto& ev : events)
	{
		if (ev.key == key && ev.mode == mode && ev.action == action)
		{
			return true;
		}
	}
	return false;
}

bool Mouse::MouseDown(int key, int mode)
{
	return MouseEvent(key, mode, 1);
}

bool Mouse::MouseRelease(int key, int mode)
{
	return MouseEvent(key, mode, 0);
}

void Mouse::OnClearEvent()
{
	this->events.clear();
	this->scrollDelta = { 0.0f,0.0f };
}
