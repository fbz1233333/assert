#pragma once

#include "fxcc/graph/gles3/interface.h"
#include "fxcc/graph/Mesh.h"

namespace fxcc
{
    namespace graph
    {
        template <>
        struct Mesh<gles3::Impl>
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
