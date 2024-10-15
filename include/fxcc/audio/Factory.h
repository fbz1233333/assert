#pragma once

#include "fxcc/audio/pch.h"
#include "fxcc/audio/Source.h"
#include "fxcc/audio/Player.h"

namespace fxcc
{
    namespace audio
    {
        struct Factory
        {
            virtual std::shared_ptr<Player> CreatePlayer() = 0;

            virtual std::shared_ptr<Source> CreateSource() = 0;

        };
    };
};