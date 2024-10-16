#pragma once

#include "fxcc/graph/opengl3/interface.h"
#include "fxcc/graph/interface.h"

namespace fxcc
{
    namespace graph
    {
        template <>
        struct Mesh<opengl3::Impl>
        {
            unsigned int m_Id;

            void Init() 
            {
                
            };

            void DrawElements() {

            };

            void Release() {
            };
        };
    };

};
