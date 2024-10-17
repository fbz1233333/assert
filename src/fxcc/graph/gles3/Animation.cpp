#include "fxcc/graph/Animation.h"

Ogl::Gut::Animation::Animation(aiAnimation *anim)
{
    Load(anim->mName, m_Name);
    m_Duration = anim->mDuration;
    m_TicksPerSecond = anim->mTicksPerSecond;
    m_TotalTime = m_Duration / m_TicksPerSecond;

    for (int i = 0; i < anim->mNumChannels; i++)
    {
        std::shared_ptr<Ogl::Gut::Channel> newChannel = std::make_shared<Ogl::Gut::Channel>(anim->mChannels[i]);
        m_Channels[newChannel->m_NodeName] = newChannel;
    }
};

void Ogl::Gut::Animation::SetIndex(const std::string &path, int index)
{
    auto &desc = m_Desc.m_Desc1;
    desc.m_Path = path;
    desc.m_Index = index;
    m_Desc.m_Type = AnimationDescType::_Animation_Model_File_;
};

bool Ogl::Gut::Animation::HasChannel(const std::string &nodeName)
{
    return m_Channels.find(nodeName) != m_Channels.end();
    
};