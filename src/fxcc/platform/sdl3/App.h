#pragma once

#include "fxcc/platform/sdl3/pch.h"
#include "fxcc/platform/sdl3/Callbacks.h"

#include "fxcc/platform/common/App.h"

namespace fxcc
{
    namespace platform
    {

        namespace sdl3
        {

            struct App :public common::App
            {

                App(const common::App::Desc& desc);

                bool Init();

                int Run();

                virtual void OnDestory();

            private:
                SDL_Window* m_SDLwindow;

                SDL_GLContext m_GLcontext;

            };
        };
    };
};