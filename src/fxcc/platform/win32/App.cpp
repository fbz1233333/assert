#include "fxcc/platform/win32/App.h"
#include "fxcc/platform/win32/CallBacks.h"

#include <windows.h>
#include <xinput.h>
#include <thread>
#include <chrono>

#pragma comment(lib, "xinput.lib")

using namespace fxcc::platform;
using namespace fxcc::platform::win32;


win32::App::App(const common::App::Desc& desc)
    :common::App(desc), m_lpClassName(L"win32 app class"), m_hInstance(0), m_wnd(0)
{
}

int win32::App::Run()
{
    bool done = false;
    while (!done)
    {
        MSG msg;
        while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);


            if (msg.message == WM_QUIT)
                done = true;
        }
        OnJoystick();

        if (done)
            break;
    }

    OnDestory();
    return 0;
};

void win32::App::OnDestory()
{
    ::DestroyWindow(m_wnd);
    ::UnregisterClassW(m_lpClassName, m_hInstance);
};


bool win32::App::Init()
{
    if (!InitWindow())
    {
        ztclog::warn("failed int the window");
        return false;
    };

    return true;
}

bool fxcc::platform::win32::App::InitWindow()
{
    win32::CallBacks::Register(this);

    WNDCLASSEXW wc = { sizeof(wc), CS_CLASSDC, fxcc::platform::win32::CallBacks::WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, m_lpClassName, nullptr };
    ::RegisterClassExW(&wc);

    m_wnd = ::CreateWindowW(wc.lpszClassName, m_Desc.GetTitleW().c_str(), WS_OVERLAPPEDWINDOW,
        m_Desc.m_Pos.x, m_Desc.m_Pos.y, m_Desc.m_Size.x, m_Desc.m_Size.y, nullptr, nullptr, wc.hInstance, nullptr);

    // Show the window
    ::ShowWindow(m_wnd, SW_SHOWDEFAULT);
    ::UpdateWindow(m_wnd);

    return true;
}

LRESULT WINAPI fxcc::platform::win32::App::OnWndProj(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    //if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
    //    return true;

    switch (msg)
    {
    case WM_XBUTTONDOWN:
    case WM_XBUTTONUP:
    case WM_LBUTTONDOWN:
    case WM_LBUTTONUP:
    case WM_RBUTTONDOWN:
    case WM_RBUTTONUP:
    case WM_MOUSEMOVE:
    case WM_MOUSEWHEEL:
        HandleMouseInput(msg, wParam, lParam);
        break;
    case WM_SYSKEYDOWN:
    case WM_KEYDOWN:
    case WM_SYSKEYUP:
    case WM_KEYUP:
        HandleKeyInput(msg, wParam, lParam);
        break;

    case WM_SIZE:
        if (wParam == SIZE_MINIMIZED)
            return 0;
        m_Desc.m_Size.x = (UINT)LOWORD(lParam); // Queue resize
        m_Desc.m_Size.y = (UINT)HIWORD(lParam);
        return 0;
        //case WM_SYSCOMMAND:
        //    if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
        //        return 0;
        //    break;
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

void win32::App::OnJoystick()
{
    XINPUT_STATE state;

    ZeroMemory(&state, sizeof(XINPUT_STATE));

    int jId = 0;
    DWORD result = XInputGetState(0, &state);

    if (result == ERROR_SUCCESS)
    {

        BYTE leftTrigger = state.Gamepad.bLeftTrigger;

        if (state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {
            std::cout << "A Button Pressed!" << std::endl;
        }
        // -32767~32767
        std::cout << state.Gamepad.sThumbLX << std::endl;
    }
    else
    {
        std::cout << "Control not connected" << std::endl;
    }

}

void fxcc::platform::win32::App::HandleMouseInput(UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_XBUTTONDOWN:
    {
        if (GET_XBUTTON_WPARAM(wParam) == XBUTTON1) {
            m_Input.MouseCallBack(Mouse::Button::_btn_nearside_, 1);
        }
        else if (GET_XBUTTON_WPARAM(wParam) == XBUTTON2) {
            m_Input.MouseCallBack(Mouse::Button::_btn_farside_, 1);
        }
    }
    break;

    case WM_XBUTTONUP:
        if (GET_XBUTTON_WPARAM(wParam) == XBUTTON1) {
            //Button1 is the button near me
            m_Input.MouseCallBack(Mouse::Button::_btn_nearside_, 0);
        }
        else if (GET_XBUTTON_WPARAM(wParam) == XBUTTON2) {
            m_Input.MouseCallBack(Mouse::Button::_btn_farside_, 0);
        }
        break;
    case WM_LBUTTONDOWN:
    {
        m_Input.MouseCallBack(Mouse::Button::_btn_left_, 1);
    };
    break;
    case WM_LBUTTONUP:
    {
        m_Input.MouseCallBack(Mouse::Button::_btn_left_, 0);
    };
    break;
    case WM_RBUTTONDOWN:
    {
        m_Input.MouseCallBack(Mouse::Button::_btn_right_, 1);
    };
    break;
    case WM_RBUTTONUP:
    {
        m_Input.MouseCallBack(Mouse::Button::_btn_right_, 0);
    };
    break;
    case WM_MOUSEMOVE:
    {
        int xPos = LOWORD(lParam);
        int yPos = HIWORD(lParam);
        m_Input.CursorPos(xPos, yPos);
    }
    break;
    case WM_MOUSEWHEEL:
    {
        int zDelta = GET_WHEEL_DELTA_WPARAM(wParam);
        if (zDelta > 0)
            m_Input.Scroll(1, 0);
        else
            m_Input.Scroll(-1, 0);
    };
    break;
    default:
        break;

    }
}

void fxcc::platform::win32::App::HandleKeyInput(UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_SYSKEYDOWN:
    case WM_KEYDOWN:
    {
        int scancode = (lParam & 0x00FF0000) >> 16;
        m_Input.KeyCallback(scancode, 1);
    }
    break;
    case WM_SYSKEYUP:
    case WM_KEYUP:
    {
        int scancode = (lParam & 0x00FF0000) >> 16;
        m_Input.KeyCallback(scancode, 0);
    }
    break;
    default:
        break;
    }
}
