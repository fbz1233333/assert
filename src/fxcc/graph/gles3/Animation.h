#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/Channel.h"
#include "fxcc/graph/AnimationDesc.h"
#include "fxcc/graph/Base.h"

namespace Ogl
{
    namespace Gut
    {

        struct Animation:public Base
        {
  
            AnimationDesc m_Desc;

            double m_Duration;

            double m_TicksPerSecond;

            double m_TotalTime;

            // the index when serialized into the bin data instead of the name(std::string)
            unsigned int m_NameIndex;

            std::unordered_map<std::string, std::shared_ptr<Ogl::Gut::Channel>> m_Channels;

            std::string m_Name;

            Animation(aiAnimation *anim);

            void SetIndex(const std::string &path, int index);

            bool HasChannel(const std::string &nodeName);
        };
    };
};