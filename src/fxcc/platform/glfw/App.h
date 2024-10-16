#pragma once

#include "fxcc/platform/App.h"
#include "fxcc/platform/glfw/pch.h"
#include "fxcc/platform/AppDesc.h"

namespace fxcc
{

    namespace platform
    {
        template <>
        struct App<glfw::Impl>
        {
            App();

            void Execute();
        };
    };
}
