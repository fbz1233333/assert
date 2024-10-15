#pragma once

#include "fxcc/audio/pch.h"

namespace fxcc
{
    namespace audio
    {
        struct Source
        {
            virtual void Init() = 0;
            virtual void Release() = 0;
            virtual ~Source() = 0;
        };
    };
};