#include "fxcc/graph/Material.h"

Ogl::Gut::Material::Material(aiMaterial *mat, const std::string &dir)
    : m_Dir(dir)
{
    // printf("load Material");
    Load(mat->GetName(), m_Name);

    LoadTextures(mat, aiTextureType_NONE);
    LoadTextures(mat, aiTextureType_DIFFUSE);
    LoadTextures(mat, aiTextureType_SPECULAR);
    LoadTextures(mat, aiTextureType_AMBIENT);
    LoadTextures(mat, aiTextureType_EMISSIVE);
    LoadTextures(mat, aiTextureType_HEIGHT);
    LoadTextures(mat, aiTextureType_NORMALS);
    LoadTextures(mat, aiTextureType_SHININESS);
    LoadTextures(mat, aiTextureType_OPACITY);
    LoadTextures(mat, aiTextureType_DISPLACEMENT);
    LoadTextures(mat, aiTextureType_LIGHTMAP);
    LoadTextures(mat, aiTextureType_REFLECTION);
    LoadTextures(mat, aiTextureType_BASE_COLOR);
    LoadTextures(mat, aiTextureType_NORMAL_CAMERA);
    LoadTextures(mat, aiTextureType_EMISSION_COLOR);
    LoadTextures(mat, aiTextureType_METALNESS);
    LoadTextures(mat, aiTextureType_DIFFUSE_ROUGHNESS);
    LoadTextures(mat, aiTextureType_AMBIENT_OCCLUSION);
    LoadTextures(mat, aiTextureType_UNKNOWN);

    for (unsigned int i = 0; i < mat->mNumProperties;i++)
    {
        m_Properties.push_back(std::make_shared<Ogl::Gut::Property>(mat->mProperties[i]));
    }
}

void Ogl::Gut::Material::LoadTextures(aiMaterial *mat, aiTextureType type)
{
    unsigned int num = mat->GetTextureCount(type);

    if (num > 0)
    {
        for (int i = 0; i < num; i++)
        {
            aiString str;
            mat->GetTexture(type, i, &str);

            std::string fileName;
            Load(str, fileName);

            std::string texturePath = m_Dir + "/" + fileName;

            std::shared_ptr<Ogl::Gut::Texture2D> texture=std::make_shared<Ogl::Gut::Texture2D>(texturePath, 4, false);
       
            m_Textures[type].push_back(texture);
        }
    }
}

//bool Ogl::Gut::Material::HasTexture(const std::string& type)
//{
//
//    auto it = m_Textures.find(type);
//
//    return it!=m_Textures.end();
//}
