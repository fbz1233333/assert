#pragma once

#include "fxcc/platform/App.h"
#include "fxcc/platform/sdl/interface.h"

namespace fxcc
{
    namespace platform
    {
        
        template<>
        struct App<fxcc::platform::sdl::Impl>
        {};

    };
};