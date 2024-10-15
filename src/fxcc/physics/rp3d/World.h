#pragma once

#include "fxcc/physics/rp3d/pch.h"

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