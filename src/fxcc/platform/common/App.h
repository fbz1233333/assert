#pragma once

#include "fxcc/pch.h"
#include "fxcc/platform/common/Input.h"

#ifndef SDL_mouse_h_
#define SDL_BUTTON_LEFT     1
#define SDL_BUTTON_MIDDLE   2
#define SDL_BUTTON_RIGHT    3
#define SDL_BUTTON_X1       4
#define SDL_BUTTON_X2       5
#endif 

namespace fxcc
{
	namespace platform
	{
		namespace common
		{
			struct App
			{

				struct Desc
				{
					glm::ivec2 m_Pos;
					glm::ivec2 m_Size;
					std::string m_Title;
					float m_ScaleFactor;

					int m_Interval;

					bool m_Focused;
					bool m_Iconify;

					Desc() :m_Interval(0), m_Focused(false), m_Iconify(false), m_Pos(0), m_Size(glm::ivec2(800, 600)),m_ScaleFactor(1.0f)
					{

					}
					std::wstring GetTitleW()
					{
						std::wstring wtitle(m_Title.begin(), m_Title.end());
						return wtitle;
					}
					glm::ivec2 GetGflwPos()
					{
						return glm::ivec2(m_Pos.x * m_ScaleFactor, m_Pos.x * m_ScaleFactor);
					};
					glm::ivec2 GetGflwSize()
					{
						return glm::ivec2(m_Size.x * m_ScaleFactor, m_Size.y * m_ScaleFactor);
					}

				}m_Desc;

				Input m_Input;
				App(const App::Desc& desc) :m_Desc(desc) {}
				
	
		
				virtual void InitWindow() {
					ztclog::warn("init window with common app ");
				};

				virtual void InitGraph() {
					ztclog::warn("init graph with common app ");
				};

				virtual void PollEvents() {
					ztclog::warn("Poll Events with common app ");
				};

				virtual void OnFrameRender() {};

				virtual void OnTick() {};

				virtual void OnClearTick() {};

				virtual void OnImGui() {};
				
				virtual void OnSwapBuffers() {
					ztclog::warn("Swap buffers with common app ");
				};
				virtual void PrepareWindowHint()
				{
					ztclog::warn("Window hint with common app ");

				};

				void Run()
				{
					while (1)
					{
						PollEvents();

						OnFrameRender();

						OnTick();
						
						OnClearTick();

						OnImGui();

						OnSwapBuffers();
					}
				}
				
				virtual void DestroyGraph() {
					ztclog::warn("destory graph with common app ");

				};

				virtual void DestroyWindow() {
					ztclog::warn("destory window with common app ");
				};
			};
		}
	}
}
