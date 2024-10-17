#pragma once

#include "fxcc/platform/glfw/interface.h"
#include "fxcc/platform/core/AppDesc.h"

namespace fxcc
{
    namespace platform
    {

        template <>
        struct App<fxcc::platform::glfw::Impl>
        {
            core::AppDesc m_Desc;
            App<fxcc::platform::glfw::Impl>(const core::AppDesc &desc) : m_Desc(desc){
                Init();
            };
            virtual bool Init();
        };

    };
};
