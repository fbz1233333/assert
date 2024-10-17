#pragma once

#include "fxcc/graph/pch.h"

namespace Ogl
{

    namespace Gut
    {
        struct RenderBuffer
        {

            unsigned int m_Id;

            void Create();
            void Bind();
            static void UnBind();
            ~RenderBuffer();

            RenderBuffer();

            RenderBuffer(unsigned int internalFormat, int width, int height);
            void Storage(unsigned int internalFormat, int width, int height);
        };
    };
};