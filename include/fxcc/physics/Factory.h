#pragma once

#include "fxcc/physics/pch.h"
#include "fxcc/physics/World.h"
#include "fxcc/physics/Rigidbody.h"
#include "fxcc/physics/Collider.h"

namespace fxcc
{
    namespace physics
    {
        struct Factory
        {

            virtual std::shared_ptr<World> CreateWorld() = 0;

            virtual std::shared_ptr<World> CreateRigidbody() = 0;

            virtual std::shared_ptr<World> CreateCollider() = 0;
        };
    };
};
