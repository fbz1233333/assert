#pragma once

#include "fxcc/platform/core/pch.h"
#include "fxcc/platform/core/AppDesc.h"
namespace fxcc{

    namespace platform
    {

        template<typename T>
        struct App;

        template <typename T>
        struct Factory
        {
            std::shared_ptr<App<T>> CreateApp(const core::AppDesc& desc)
            {
                return std::make_shared<App<T>>(desc);
            }
        };
    };
};