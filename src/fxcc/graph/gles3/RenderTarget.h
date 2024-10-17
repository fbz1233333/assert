#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/RenderBuffer.h"
#include "fxcc/graph/FrameBuffer.h"
#include "fxcc/graph/Texture2D.h"
#include "fxcc/graph/RenderTargetDesc.h"

namespace Ogl
{
    namespace Gut
    {

        struct RenderTarget:public Base
        {
            std::vector<unsigned int> m_Attachments;

            Ogl::Gut::RenderTargetDesc m_Desc;

            FrameBuffer m_FrameBuffer;
            
            RenderBuffer m_RenderBuffer;

            std::vector<std::shared_ptr<Ogl::Gut::Texture2D>> m_Textures;

            RenderTarget(const RenderTargetDesc& desc);

            void Init();

            void Init1();

            void Init2();

            void Begin();

            void Viewport();

            void End();

            void Framebuffersize(int w, int h);
        };
    };
};
