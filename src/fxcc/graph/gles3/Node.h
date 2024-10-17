#pragma once

#include "fxcc/graph/pch.h"

namespace Ogl
{
    namespace Gut
    {
        struct Node
        {
            std::string m_Name;
            std::vector<std::shared_ptr<Node>> m_Childern;
            std::vector<unsigned int> m_Meshes;
            glm::mat4 m_Offset;
            
            Node(aiNode *node);
        };
    }
}