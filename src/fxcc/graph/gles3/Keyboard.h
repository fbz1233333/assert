#pragma once

#include "fxcc/graph/Input.h"

#define MAX_KEY 1024

namespace Ogl
{
	namespace Gut
	{

		struct Keyboard
		{
			Keyboard();

			enum KeyCode
			{
				SPACE = GLFW_KEY_SPACE,
				APOSTROPHE = GLFW_KEY_APOSTROPHE,
				COMMA = GLFW_KEY_COMMA,
				MINUS = GLFW_KEY_MINUS,
				PERIOD = GLFW_KEY_PERIOD,
				SLASH = GLFW_KEY_SLASH,
				_0 = GLFW_KEY_0,
				_1 = GLFW_KEY_1,
				_2 = GLFW_KEY_2,
				_3 = GLFW_KEY_3,
				_4 = GLFW_KEY_4,
				_5 = GLFW_KEY_5,
				_6 = GLFW_KEY_6,
				_7 = GLFW_KEY_7,
				_8 = GLFW_KEY_8,
				_9 = GLFW_KEY_9,
				SEMICOLON = GLFW_KEY_SEMICOLON,
				EQUAL = GLFW_KEY_EQUAL,
				_A = GLFW_KEY_A,
				_B = GLFW_KEY_B,
				_C = GLFW_KEY_C,
				_D = GLFW_KEY_D,
				_E = GLFW_KEY_E,
				_F = GLFW_KEY_F,
				_G = GLFW_KEY_G,
				_H = GLFW_KEY_H,
				_I = GLFW_KEY_I,
				_J = GLFW_KEY_J,
				_K = GLFW_KEY_K,
				_L = GLFW_KEY_L,
				_M = GLFW_KEY_M,
				_N = GLFW_KEY_N,
				_O = GLFW_KEY_O,
				_P = GLFW_KEY_P,
				_Q = GLFW_KEY_Q,
				_R = GLFW_KEY_R,
				_S = GLFW_KEY_S,
				_T = GLFW_KEY_T,
				_U = GLFW_KEY_U,
				_V = GLFW_KEY_V,
				_W = GLFW_KEY_W,
				_X = GLFW_KEY_X,
				_Y = GLFW_KEY_Y,
				_Z = GLFW_KEY_Z,
				LEFT_BRACKET = GLFW_KEY_LEFT_BRACKET,
				BACKSLASH = GLFW_KEY_BACKSLASH,
				RIGHT_BRACKET = GLFW_KEY_RIGHT_BRACKET,
				GRAVE_ACCENT = GLFW_KEY_GRAVE_ACCENT,
				WORLD_1 = GLFW_KEY_WORLD_1,
				WORLD_2 = GLFW_KEY_WORLD_2,
				ESCAPE = GLFW_KEY_ESCAPE,
				ENTER = GLFW_KEY_ENTER,
				TAB = GLFW_KEY_TAB,
				BACKSPACE = GLFW_KEY_BACKSPACE,
				INSERT = GLFW_KEY_INSERT,
				DEL = GLFW_KEY_DELETE,
				RIGHT = GLFW_KEY_RIGHT,
				LEFT = GLFW_KEY_LEFT,
				DOWN = GLFW_KEY_DOWN,
				UP = GLFW_KEY_UP,
				PAGE_UP = GLFW_KEY_PAGE_UP,
				PAGE_DOWN = GLFW_KEY_PAGE_DOWN,
				HOME = GLFW_KEY_HOME,
				END = GLFW_KEY_END,
				CAPS_LOCK = GLFW_KEY_CAPS_LOCK,
				SCROLL_LOCK = GLFW_KEY_SCROLL_LOCK,
				NUM_LOCK = GLFW_KEY_NUM_LOCK,
				PRINT_SCREEN = GLFW_KEY_PRINT_SCREEN,
				PAUSE = GLFW_KEY_PAUSE,
				F1 = GLFW_KEY_F1,
				F2 = GLFW_KEY_F2,
				F3 = GLFW_KEY_F3,
				F4 = GLFW_KEY_F4,
				F5 = GLFW_KEY_F5,
				F6 = GLFW_KEY_F6,
				F7 = GLFW_KEY_F7,
				F8 = GLFW_KEY_F8,
				F9 = GLFW_KEY_F9,
				F10 = GLFW_KEY_F10,
				F11 = GLFW_KEY_F11,
				F12 = GLFW_KEY_F12,
				F13 = GLFW_KEY_F13,
				F14 = GLFW_KEY_F14,
				F15 = GLFW_KEY_F15,
				F16 = GLFW_KEY_F16,
				F17 = GLFW_KEY_F17,
				F18 = GLFW_KEY_F18,
				F19 = GLFW_KEY_F19,
				F20 = GLFW_KEY_F20,
				F21 = GLFW_KEY_F21,
				F22 = GLFW_KEY_F22,
				F23 = GLFW_KEY_F23,
				F24 = GLFW_KEY_F24,
				F25 = GLFW_KEY_F25,
				KP_0 = GLFW_KEY_KP_0,
				KP_1 = GLFW_KEY_KP_1,
				KP_2 = GLFW_KEY_KP_2,
				KP_3 = GLFW_KEY_KP_3,
				KP_4 = GLFW_KEY_KP_4,
				KP_5 = GLFW_KEY_KP_5,
				KP_6 = GLFW_KEY_KP_6,
				KP_7 = GLFW_KEY_KP_7,
				KP_8 = GLFW_KEY_KP_8,
				KP_9 = GLFW_KEY_KP_9,
				KP_DECIMAL = GLFW_KEY_KP_DECIMAL,
				KP_DIVIDE = GLFW_KEY_KP_DIVIDE,
				KP_MULTIPLY = GLFW_KEY_KP_MULTIPLY,
				KP_SUBTRACT = GLFW_KEY_KP_SUBTRACT,
				KP_ADD = GLFW_KEY_KP_ADD,
				KP_ENTER = GLFW_KEY_KP_ENTER,
				KP_EQUAL = GLFW_KEY_KP_EQUAL,
				LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT,
				RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT,
				LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL,
				RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL,
				LEFT_ALT = GLFW_KEY_LEFT_ALT,
				RIGHT_ALT = GLFW_KEY_RIGHT_ALT,
				// LEFT_SUPER		=GLFW_KEY_LEFT_SUPER,
				// RIGHT_SUPER	=GLFW_KEY_RIGHT_SUPER,
				MENU = GLFW_KEY_MENU,
			};

			struct Event
			{
				int key;
				int scancode;
				int action;
				int mode;
			};

			bool states[MAX_KEY];
			KeyMode mCurrentMode;

			std::vector<Event> events;
			void OnKeyboard(int key, int scancode, int action, int mode);
			bool KeyPressingState(int c);

			bool KeyEvent_(int key, int mode, int action);
			bool KeyDown_(int key, int mode = 0);
			bool KeyRelease_(int key, int mode = 0);
			bool KeyPress_(int key, int mode = 0);

			void OnClearEvent();


		};



	}
}