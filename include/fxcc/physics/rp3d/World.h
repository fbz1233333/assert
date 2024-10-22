#pragma once

#include "fxcc/physics/rp3d/interface.h"

namespace fxcc
{
    namespace physics
    {
        namespace rp3d
        {
            struct World
            {
                reactphysics3d::PhysicsWorld *m_Impl;
                
            };
        };
    };
};