#include "fxcc/graph/ChannelMap.h"

using namespace Ogl::Gut;

void ChannelMap::ProcessNode(BoneNode* boneNode, const Ogl::Gut::Animation* anim)
{
	auto it = anim->m_Channels.find(boneNode->m_NodeName);
	if (it != anim->m_Channels.end())
	{

		Data newData;
		newData.m_BoneNode = boneNode;
		newData.m_Channel = it->second.get();
		this->m_Datas.push_back(newData);
	}

	for (auto child : boneNode->children)
	{
		ProcessNode(child.get(), anim);
	}
}