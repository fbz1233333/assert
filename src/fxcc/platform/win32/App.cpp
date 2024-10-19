#include "fxcc/platform/win32/App.h"
#include "fxcc/platform/win32/CallBacks.h"

using namespace fxcc::platform;
using namespace fxcc::platform::win32;

win32::App* win32::App::g_Inst = 0;

win32::App::App(const common::App::Desc& desc)
    :common::App(desc), m_lpClassName(L"win32 app class")
{
    g_Inst = this;
}

int win32::App::Run()
{
    bool done = false;
    while (!done)
    {
        // Poll and handle messages (inputs, window resize, etc.)
        // See the WndProc() function below for our to dispatch events to the Win32 backend.
        MSG msg;
        while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                done = true;
        }
        if (done)
            break;
    }


    ::DestroyWindow(m_wnd);
    ::UnregisterClassW(m_lpClassName, m_hInstance);

    return 0;
}

bool win32::App::Init()
{
    WNDCLASSEXW wc = { sizeof(wc), CS_CLASSDC, fxcc::platform::win32::CallBacks::WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, m_lpClassName, nullptr };
    ::RegisterClassExW(&wc);
    HWND hwnd = ::CreateWindowW(wc.lpszClassName, m_Desc.GetTitleW().c_str(), WS_OVERLAPPEDWINDOW, 
        m_Desc.m_Pos.x, m_Desc.m_Pos.y, m_Desc.m_Size.x, m_Desc.m_Size.y, nullptr, nullptr, wc.hInstance, nullptr);

    // Show the window
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);


    return true;
}

LRESULT WINAPI fxcc::platform::win32::App::OnWndProj(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    //if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
    //    return true;

    switch (msg)
    {
    case WM_SIZE:
        if (wParam == SIZE_MINIMIZED)
            return 0;
        m_Desc.m_Size.x = (UINT)LOWORD(lParam); // Queue resize
        m_Desc.m_Size.y = (UINT)HIWORD(lParam);
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    case WM_DPICHANGED:
        //if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_DpiEnableScaleViewports)
        //{
        //    //const int dpi = HIWORD(wParam);
        //    //printf("WM_DPICHANGED to %d (%.0f%%)\n", dpi, (float)dpi / 96.0f * 100.0f);
        //    const RECT* suggested_rect = (RECT*)lParam;
        //    ::SetWindowPos(hWnd, nullptr, suggested_rect->left, suggested_rect->top, suggested_rect->right - suggested_rect->left, suggested_rect->bottom - suggested_rect->top, SWP_NOZORDER | SWP_NOACTIVATE);
        //}
        break;
    }
    return ::DefWindowProcW(hWnd, msg, wParam, lParam);
}
