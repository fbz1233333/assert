#include "fxcc/graph/Light.h"

std::vector<std::string> Ogl::Gut::Light::g_sourceTypesStrs =
    {
        "UNDEFINED",
        "DIRECTIONAL",
        "POINT",
        "SPOT",
        "AMBIENT",
        "AREA",
};

Ogl::Gut::Light::Light(aiLight *light)
{
    Load(light->mName, m_Name);
    memcpy(&m_LightType, &light->mType, sizeof(light->mType));
    Load(light->mPosition, m_Position);
    Load(light->mDirection, m_Direction);
    Load(light->mUp, m_Up);

    m_AttenuationConstant = light->mAttenuationConstant;
    m_AttenuationLinear = light->mAttenuationLinear;
    m_AttenuationQuadratic = light->mAttenuationQuadratic;

    Load(light->mColorAmbient, m_ColorAmbient);
    Load(light->mColorDiffuse, m_ColorDiffuse);
    Load(light->mColorSpecular, m_ColorSpecular);

    m_AngleInnerCone = light->mAngleInnerCone;
    m_AngleOuterCone = light->mAngleOuterCone;

    Load(light->mSize, m_Size);
}