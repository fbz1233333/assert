#pragma once

#include "fxcc/platform/sdl2/pch.h"
#include "fxcc/platform/sdl2/Callbacks.h"

#include "fxcc/platform/common/App.h"

namespace fxcc
{
    namespace platform
    {
        namespace sdl2
        {
            struct App :public common::App
            {
                App(const common::App::Desc& desc);

                bool Init();

                int Run();

            private:

                SDL_Window* m_SDLwindow;

                SDL_GLContext m_GLcontext;
            };
        };
    };
};