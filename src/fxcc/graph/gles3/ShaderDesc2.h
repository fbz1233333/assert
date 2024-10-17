#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/Base.h"

namespace Ogl
{
	namespace Gut
	{ 
        struct ShaderDesc2 :public Base
        {
            std::string m_VertFile;
            std::string m_FragFile;
        };
    }
}
