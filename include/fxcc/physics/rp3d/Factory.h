#pragma once

#include "fxcc/physics/Factory.h"

namespace fxcc
{
    namespace physics
    {
        namespace rp3d
        {
            struct Factory : public fxcc::physics::Factory
            {
                std::shared_ptr<World> CreateWorld() { return 0; }

                std::shared_ptr<World> CreateRigidbody() { return 0; }

                std::shared_ptr<World> CreateCollider() { return 0; }
            };
        }
    };
};
