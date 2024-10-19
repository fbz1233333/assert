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
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
    };

    SDL_DestroyWindow(m_SDLwindow);
    SDL_Quit();

    return 0;
}