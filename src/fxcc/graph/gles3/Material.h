#pragma once
#include "fxcc/graph/pch.h"
#include "fxcc/graph/Type.h"
#include "fxcc/graph/Texture2D.h"
#include "fxcc/graph/Property.h"

namespace Ogl
{
    namespace Gut
    {
        struct Material:public Base
        {
            struct Desc : public Base
            {
                std::string m_Path;
                int m_Index;
            } m_Desc;

            std::string m_Dir;

            std::string m_Name;

            std::vector<std::shared_ptr<Ogl::Gut::Property>> m_Properties;

            Material(aiMaterial* material, const std::string& dir);

            std::vector<std::shared_ptr<Ogl::Gut::Texture2D>> m_Textures[TextureMaterialType::_material_end_];
        
            void LoadTextures(aiMaterial* mat, aiTextureType type);
        
        };
    };
};