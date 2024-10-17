#include "fxcc/graph/Channel.h"


Ogl::Gut::Channel::Channel(aiNodeAnim* channel)
{
    Load(channel->mNodeName, m_NodeName);
    // channel->mPositionKeys;
    for (int i = 0; i < channel->mNumPositionKeys; i++)
    {
        m_PositionKeys.push_back(std::make_shared<Ogl::Gut::PositionKey>(&channel->mPositionKeys[i]));
    }
    for (int i = 0; i < channel->mNumRotationKeys; i++)
    {
        m_RotationKeys.push_back(std::make_shared<Ogl::Gut::RotationKey>(&channel->mRotationKeys[i]));
    }
    for (int i = 0; i < channel->mNumScalingKeys; i++)
    {
        m_ScaleKeys.push_back(std::make_shared<Ogl::Gut::ScaleKey>(&channel->mScalingKeys[i]));
    }
}


glm::vec3 Ogl::Gut::Channel::GetPosition(double ct_time) const
{
    if (m_PositionKeys.size() == 0)
    {
        return glm::vec3(0.0f);
    }
    else if (m_PositionKeys.size() == 1)
    {
        return m_PositionKeys[0]->m_Value;
    }
    else
    {
        unsigned int index = GetPositionIndex(ct_time);
        const auto& left = m_PositionKeys[index];
        const auto& right = m_PositionKeys[index + 1];
        float axis = (ct_time - left->m_Time) / (right->m_Time- left->m_Time);

        return glm::mix(left->m_Value, right->m_Value, axis);
    }
}

glm::quat Ogl::Gut::Channel::GetRotation(double ct_time) const
{
    if (m_RotationKeys.size() == 0)
    {
        return glm::quat();
    }
    else if (m_RotationKeys.size() == 1)
    {
        return m_RotationKeys[0]->m_Value;
    }
    else
    {
        unsigned int index = GetRotationIndex(ct_time);

        auto left = m_RotationKeys[index];
        auto right = m_RotationKeys[index + 1];

        float axis = (ct_time - left->m_Time) / (right->m_Time - left->m_Time);
        return glm::slerp(left->m_Value, right->m_Value, axis);
    }
}

glm::vec3 Ogl::Gut::Channel::GetScale(double ct_time) const
{
    if (m_ScaleKeys.size() == 0)
    {
        return glm::vec3(1.0f);
    }
    else if (m_ScaleKeys.size() == 1)
    {
        return m_ScaleKeys[0]->m_Value;
    }
    else
    {
        unsigned int index = GetScaleIndex(ct_time);

        const auto left = m_ScaleKeys[index];
        const auto right = m_ScaleKeys[index + 1];
        float axis = (ct_time - left->m_Time) / (right->m_Time - left->m_Time);

        return glm::mix(left->m_Value, right->m_Value, axis);
    }
}

int Ogl::Gut::Channel::GetPositionIndex(double index) const
{
    for (int i = 0; i < m_PositionKeys.size() - 1; i++)
    {
        if (m_PositionKeys[i + 1]->m_Time > index)
        {
            return i;
        }
    }
    return 0;
}


int Ogl::Gut::Channel::GetScaleIndex(double index) const
{
    for (int i = 0; i < m_ScaleKeys.size() - 1; i++)
    {
        if (m_ScaleKeys[i + 1]->m_Time > index)
        {
            return i;
        }
    }
    return 0;
}

glm::mat4 Ogl::Gut::Channel::GetSlerpTransform(double index) const
{
    Ogl::Math::Transform transform;

    transform.position = GetPosition(index);
    transform.SetRotation(GetRotation(index));
    transform.SetScale(GetScale(index));
    return transform.GetWorld();
}


int Ogl::Gut::Channel::GetRotationIndex(double index) const
{
    for (int i = 0; i < m_RotationKeys.size() - 1; i++)
    {
        if (m_RotationKeys[i + 1]->m_Time > index)
        {
            return i;
        }
    }
    return 0;
}
