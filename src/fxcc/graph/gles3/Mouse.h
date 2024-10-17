#pragma once
#include "fxcc/graph/pch.h"

namespace Ogl
{
	namespace Gut
	{

		struct Mouse
		{
			enum Btn
			{
				_left = 0,
				_right,
				_middle,
				_side_back,
				_side_front

			};

			Mouse();

			glm::vec2 currentPos, scrollDelta;
			struct Event
			{
				int key, action, mode;
			};

			bool states[10];

			bool MousePressing(int i);
			std::vector<Event> events;

			std::vector<Event> Events() const;
			glm::vec2 CurrenPos() const;
			glm::vec2 ScrollDelta() const;

			void OnScroll(double x, double y);
			void OnCursorPos(double x, double y);
			void OnMouse(int key, int action, int mode);

			bool MouseEvent(int key, int mode, int action);

			bool MouseDown(int key, int mode);
			bool MouseRelease(int key, int mode);

			void OnClearEvent();
		};
	};
};