#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/Base.h"

namespace Ogl
{
    namespace Gut
    {
        // Load from bin data
        struct Texture2DDesc3 :public Base
        {
            std::string m_Path;
            Texture2DDesc3() = default;
            Texture2DDesc3(const std::string& p) :m_Path(p) {}
        };
    };
};