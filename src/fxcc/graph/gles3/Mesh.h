#pragma once

#include "fxcc/graph/Mesh.h"
#include "fxcc/graph/gles3/pch.h"

namespace fxcc
{
    namespace graph
    {
        namespace gles3
        {
            struct Mesh : public fxcc::graph::Mesh
            {
                unsigned int m_Id;

                void Init() {}
                void DrawElements()
                {
                }
                void Release()
                {

                }
            };
        };
    };

};
