#pragma once

#include "fxcc/pch.h"

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
	LSTICK,
	RSTICK,
	BACK,
	TURBO,
	CLEAR,
	START,
	CENTER,
	COUNT
};

enum ActionType
{
	Up = 0,
	Down = 1,
};