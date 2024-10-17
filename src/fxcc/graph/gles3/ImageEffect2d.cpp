#include "fxcc/graph/ImageEffect2d.h"

Ogl::Gut::ImageEffect2d::ImageEffect2d()
    :Ogl::Gut::Effect2d(ImageEffect2d::FragCode())
{
}

void Ogl::Gut::ImageEffect2d::Begin()
{
    Ogl::Gut::Effect2d::Begin();


    m_Shader->Use();
    m_Shader->setInt("imageMap", 0);
}

void Ogl::Gut::ImageEffect2d::RenderQuad(const Ogl::Gut::Texture2D* texture)
{
    texture->Active(0);
    DebugQuad();
}

std::string Ogl::Gut::ImageEffect2d::FragCode()
{
    return R"(

uniform sampler2D imageMap;

out vec4 FragColor;

void main()
{
    FragColor=texture(imageMap, TexCoord);
}
)";
}
