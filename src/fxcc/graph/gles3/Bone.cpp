#include "fxcc/graph/Bone.h"

Ogl::Gut::Bone::Bone(aiBone *bone)
{
    Load(bone->mName, m_Name);
    for (int i = 0; i < bone->mNumWeights; i++)
    {
        m_Weights.push_back(VertexWeight(&bone->mWeights[i]));
    }

    Load(bone->mOffsetMatrix, m_OffsetMatrix);
};