#pragma once

#include "fxcc/graph/Type.h"
#include "fxcc/graph/Util.h"
#include "fxcc/graph/ShaderDesc1.h"
#include "fxcc/graph/ShaderDesc2.h"
#include "fxcc/graph/Base.h"

namespace Ogl
{
    namespace Gut
    {


        struct ShaderDesc:public Base
        {
            ShaderDesc1 m_Desc1;
            ShaderDesc2 m_Desc2;

            ShaderDescType m_Type;

            void Parse2To1()
            {
                m_Desc1.m_VertCode = Ogl::Gut::Util::readFile(m_Desc2.m_VertFile);
                m_Desc1.m_FragCode = Ogl::Gut::Util::readFile(m_Desc2.m_FragFile);
            }

        };
    };
};