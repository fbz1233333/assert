#include "fxcc/platform/sdl2/App.h"

using namespace fxcc::platform::sdl2;
using namespace fxcc::platform;

sdl2::App::App(const common::App::Desc& desc)
    :common::App(desc), m_SDLwindow(0)
{

};

bool sdl2::App::Init()
{
    // int SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        ztclog::warn("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }

    const char* glsl_version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);


    //SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    //SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    //SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    Uint32 window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN;
    SDL_Window* m_SDLwindow;
    m_SDLwindow = SDL_CreateWindow(m_Desc.m_Title.c_str(),
        m_Desc.m_Pos.x, m_Desc.m_Pos.y, 
        m_Desc.m_Size.x, m_Desc.m_Size.y, window_flags);

    if (!m_SDLwindow) {
        ztclog::warn("Failed to create m_SDLwindow: %s", SDL_GetError());
        SDL_Quit();
        return false;
    }

    SDL_SetWindowPosition(m_SDLwindow, m_Desc.m_Pos.x, m_Desc.m_Pos.y);
    m_GLcontext = SDL_GL_CreateContext(m_SDLwindow);
    SDL_GL_MakeCurrent(m_SDLwindow, m_GLcontext);
    SDL_GL_SetSwapInterval(m_Desc.m_Interval); // Enable vsync
    SDL_ShowWindow(m_SDLwindow);

    return true;
};

int sdl2::App::Run()
{
    std::map<int, int> sdlMouseMap =
    {
        {SDL_BUTTON_LEFT, Mouse::Button::_btn_left_},
        {SDL_BUTTON_RIGHT, Mouse::Button::_btn_right_},
        {SDL_BUTTON_MIDDLE, Mouse::Button::_btn_middle_},
        {SDL_BUTTON_X1, Mouse::Button::_btn_nearside_},
        {SDL_BUTTON_X2, Mouse::Button::_btn_farside_}
    };

    bool running = true;
    SDL_Event ev;

    while (running) {
        while (SDL_PollEvent(&ev) != 0) {

            switch (ev.type)
            {
            case SDL_QUIT:
            {
                running = false;
            }
            break;
            case SDL_KEYDOWN:
            {
                int scancode = ev.key.keysym.scancode;
                m_Input.KeyCallback(scancode, 1);
            }
            break;
            case SDL_KEYUP:
            {
                int scancode = ev.key.keysym.scancode;
                m_Input.KeyCallback(scancode, 0);
            }
            break;
            case SDL_MOUSEBUTTONDOWN:
                m_Input.MouseCallBack(sdlMouseMap[ev.button.button], 1);
                break;
            case SDL_MOUSEBUTTONUP: 
                m_Input.MouseCallBack(sdlMouseMap[ev.button.button], 0);
                break;
            case SDL_MOUSEMOTION:
            {
                int x, y;
                x = ev.motion.x;
                y = ev.motion.y;
                m_Input.CursorPos(x, y);
            }
        
                break;
            case SDL_MOUSEWHEEL:
            {
                m_Input.Scroll(ev.wheel.x, ev.wheel.y);
            }
                break;

            default:
                break;

            }
        }
    };

    OnDestory();
    return 0;
}

void sdl2::App::OnDestory()
{
    SDL_DestroyWindow(m_SDLwindow);
    SDL_Quit();

}