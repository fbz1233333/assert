#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/Util.h"
#include "fxcc/graph/Base.h"

namespace Ogl
{
    namespace Gut
    {

        struct ShaderDesc1 :public Base
        {
            std::string m_VertCode;
            std::string m_FragCode;
            void Write(std::string vPath, std::string fPath)
            {
                Util::Write(vPath, m_VertCode);
                Util::Write(fPath, m_FragCode);

            }
        };
    }
}