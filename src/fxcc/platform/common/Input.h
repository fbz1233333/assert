#pragma once


#include "fxcc/pch.h"


struct Input
{

	void KeyCallback(int key, int scancode, int action, int mode)
	{
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

	void JoysticCallback(int joy, int event)
	{
		ztclog::info("Joystic call back %d %d", joy, event);

	};

};