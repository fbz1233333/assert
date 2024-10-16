#pragma once

#include "fxcc/platform/glfw/interface.h"

namespace fxcc
{
    namespace platform
    {
        
        template<>
        struct App<fxcc::platform::glfw::Impl>
        {
        
            void Init();
       };




    };
};
