#pragma once

#include "fxcc/platform/App.h"
#include "fxcc/platform/win32/interface.h"

namespace fxcc
{
    namespace platform
    {
        
        template<>
        struct App<fxcc::platform::win32::Impl>
        {}

    };
};
