#include "fxcc/platform/sdl3/App.h"

using namespace fxcc::platform::sdl3;
using namespace fxcc::platform;

sdl3::App::App(const common::App::Desc& desc)
	:common::App(desc), m_SDLwindow(0)
{

}

bool sdl3::App::Init()
{
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD))
    {
        printf("Error: SDL_Init(): %s\n", SDL_GetError());
        return -1;
    }

    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    // Create m_SDLwindow with graphics context
    //SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    //SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    //SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);


    glm::ivec2 wndPos = m_Desc.GetGflwPos();
    glm::ivec2 wndSize = m_Desc.GetGflwSize();

    Uint32 m_SDLwindow_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN;
    m_SDLwindow = SDL_CreateWindow(m_Desc.m_Title.c_str(),  wndSize.x, wndSize.y, m_SDLwindow_flags);

    if (m_SDLwindow == nullptr)
    {
        ztclog::warn("Error: SDL_CreateWindow(): %s\n", SDL_GetError());
        return false;
    }


    SDL_SetWindowPosition(m_SDLwindow, wndPos.x, wndPos.y);
    m_GLcontext= SDL_GL_CreateContext(m_SDLwindow);
    SDL_GL_MakeCurrent(m_SDLwindow, m_GLcontext);
    SDL_GL_SetSwapInterval(m_Desc.m_Interval); // Enable vsync
    SDL_ShowWindow(m_SDLwindow);

	return true;
}

int sdl3::App::Run()
{
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
    }
	return 0;
}