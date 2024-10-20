#pragma once

#include "fxcc/platform/common/App.h"
#include "fxcc/platform/win32/pch.h"


namespace fxcc
{
	namespace platform
	{
		namespace win32
		{
			struct App :public fxcc::platform::common::App
			{
				App(const common::App::Desc& desc);

				bool Init();

				bool InitWindow();

				int Run();

				virtual LRESULT WINAPI OnWndProj(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

				static win32::App* g_Inst;

			private:
				HWND m_wnd;

				LPCWSTR m_lpClassName;

				HINSTANCE m_hInstance;

			};
		}
	}
}