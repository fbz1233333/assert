#pragma once

#include "fxcc/graph/pch.h"

namespace fxcc
{
    namespace graph
    {
        struct Mesh
        {
            struct Desc
            {
                

            } m_Desc;
            
            virtual void DrawElements() = 0;

            virtual void Init() = 0;

            virtual void Release() = 0;

            virtual ~Mesh()
            {
                Release();
            }
        };
    };
};