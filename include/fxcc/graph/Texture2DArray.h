#pragma once

#include "fxcc/graph/pch.h"

namespace fxcc
{
    namespace graph
    {
        struct Textrue2dArray
        {
            virtual void Init();

            virtual void Release();
           
            virtual ~Textrue2dArray()
            {
                Release();
            }
        };
    };
};