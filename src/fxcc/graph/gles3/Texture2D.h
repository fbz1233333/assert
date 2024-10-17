#pragma once

#include "fxcc/graph/Texture.h"
#include "fxcc/graph/Sampler.h"
#include "fxcc/graph/Image.h"
#include "fxcc/graph/Sampler.h"
#include "fxcc/graph/Type.h"
#include "fxcc/graph/Texture2DDesc.h"

namespace Ogl
{
    namespace Gut
    {
        struct Texture2D : public Texture
        {
            glm::ivec2 m_ImageSize = glm::ivec2(100, 100);
            Texture2DDesc m_Desc;

            Texture2D()
                : Texture(GL_TEXTURE_2D) {

                  };

            Texture2D(const Texture2DDesc &desc)
                : m_Desc(desc), Ogl::Gut::Texture(GL_TEXTURE_2D)
            {
                Init();
            }
            Texture2D(const std::string& path, int req = 0, bool hdr = false)
                :Ogl::Gut::Texture(GL_TEXTURE_2D)
            {

                Ogl::Gut::Texture2DDesc2 desc2;
                desc2.m_ImageDesc.m_hdr = hdr;
                desc2.m_ImageDesc.m_Path = path;
                desc2.m_ImageDesc.m_ReqComponent = req;
                
                m_Desc = Ogl::Gut::Texture2DDesc(desc2);

                Init();
            }
            
            void Init();

            void Init1();
            
            void Init2();

            void Init3();
            
            void Resize(int width, int height);

            static void UnBind();
        };
    };
};