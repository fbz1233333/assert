#include "fxcc/graph/Node.h"

Ogl::Gut::Node::Node(aiNode *node)
{
    Load(node->mName, m_Name);
    Load(node->mTransformation, m_Offset);

    for (int i = 0; i < node->mNumMeshes; i++)
    {
        m_Meshes.push_back(node->mMeshes[i]);
    }

    for (int i = 0; i < node->mNumChildren; i++)
    {
        m_Childern.push_back(std::make_shared<Node>(node->mChildren[i]));
    }
};