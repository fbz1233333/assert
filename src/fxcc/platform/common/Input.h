#pragma once


#include "fxcc/pch.h"


struct Input
{
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
	void KeyCallback(int key, int scancode, int action, int mode)
	{
		// Only use the scancode 
		ztclog::info("KeyCallback key %d scancode %d action %d mode %d", key, scancode, action, mode);
	};

	void CursorPos(int x, int y)
	{
		ztclog::info("Cursor %d %d", x,y);
	};

	void Scroll(int x, int y)
	{
		ztclog::info("Scroll %d %d", x,y );
	};

	void MouseCallBack(int key, int action, int mode)
	{
		ztclog::info("MouseCallback key %d action %d mode %d", key, action, mode);
	};

	void JoysticCallback(int joy, int event, const char* name)
	{
		// connected or disconnected
		if (name)
		{
			ztclog::info("Joystic link %d %d %s", joy, event, name);

		}
		else
		{
			ztclog::info("Joystic disconnected %d %d ", joy, event);

		}

	};

};