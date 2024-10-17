#include "fxcc/graph/SkyboxEffect.h"
#include "ogl/math/Geometry.h"
#include "mustache.hpp"

Ogl::Gut::SkyboxEffect::SkyboxEffect()
    :m_FragMain(GetDefaultFragCode())
{
    Init();
}

Ogl::Gut::SkyboxEffect::SkyboxEffect(const std::string& fragMain)
    :m_FragMain(fragMain)
{

    Init();

}

void Ogl::Gut::SkyboxEffect::Init()
{
    m_Shader = std::make_shared<Ogl::Gut::Shader>(GetVertCode().c_str(), GetFragCode().c_str());
    m_SkyboxMesh = std::make_shared<Ogl::Gut::Mesh>(Geometry::CreateBox());
    m_RasterizerDesc.enableCullFace = false;
}


void Ogl::Gut::SkyboxEffect::Begin()
{
    Ogl::Gut::EffectBase::Begin();
    m_Shader->Use();
    m_Shader->setInt("skybox", 0);

    glDepthMask(false);

}

void Ogl::Gut::SkyboxEffect::End()
{
    glDepthMask(true);

}



void Ogl::Gut::SkyboxEffect::SetCamera(const Ogl::Math::Camera& camera, bool gamma)
{
    //m_PassBuffer->Upload<PassData>(passData);

    m_Shader->setMat4("projection", camera.GetProjection());
    m_Shader->setMat4("view", camera.GetViewMatrixNoTranslation());
    m_Shader->setBool("gamma", gamma);

}

void Ogl::Gut::SkyboxEffect::RenderSkybox(Ogl::Gut::TextureCube* texture, bool gamma)
{
    texture->Active(0);

    m_SkyboxMesh->Bind();
    m_SkyboxMesh->DrawElementsAuto();

}

void Ogl::Gut::SkyboxEffect::RenderSkybox(Ogl::Gut::TextureCube* texture, const Ogl::Math::Camera& camera, bool gamma)
{
    SetCamera(camera, gamma);
    //envColor = envColor / (envColor + vec3(1.0));
    //envColor = pow(envColor, vec3(1.0 / 2.2));
    RenderSkybox(texture, gamma);
}

std::string Ogl::Gut::SkyboxEffect::GetFragCode()
{
    kainjow::mustache::mustache m1(GetFragTemp());

    kainjow::mustache::data d1;
    d1.set("fragMain", m_FragMain);

    return m1.render(d1);
}

std::string Ogl::Gut::SkyboxEffect::GetVertCode()
{
    const std::string vCode = R"(
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

out vec3 localPos;


uniform mat4 projection;
uniform mat4 view;

void main()
{
    localPos = aPos;
    vec4 clipPos = projection * view * vec4(aPos, 1.0);

    gl_Position=clipPos;
}


)";
    return vCode;
}

std::string Ogl::Gut::SkyboxEffect::GetFragTemp()
{
    const std::string fCode = R"(

#version 330 core

in vec3 localPos;
uniform bool gamma;

{{fragMain}}
)";
    return fCode;
}

std::string Ogl::Gut::SkyboxEffect::GetDefaultFragCode()
{
    std::string res = R"(
out vec4 FragColor;

uniform samplerCube skybox;

void main()
{    
    vec3 color_rgb = texture(skybox, localPos).rgb;
    //envColor = envColor / (envColor + vec3(1.0));
    //envColor = pow(envColor, vec3(1.0 / 2.2));

    if(gamma)
    {
        color_rgb=color_rgb/ (color_rgb+vec3(1.0f));
        color_rgb =pow(color_rgb, vec3(1.0f/2.0f));
    }
    FragColor=vec4(color_rgb,1.0f);
}
)";

    return res;
}
