#include "fxcc/graph/BoneNode.h"

using namespace Ogl::Gut;

BoneNode::BoneNode(const Ogl::Gut::Node* node, const std::map<std::string, std::shared_ptr<Ogl::Gut::Bone>>& bones)
{
	m_NodeName = node->m_Name;
	m_NodeOffset = node->m_Offset;
	m_NodeTransfrom = node->m_Offset;

	const auto& it = bones.find(m_NodeName);
	if (it != bones.end())
	{
		this->m_BoneOffset = it->second->m_OffsetMatrix;
		this->m_BoneIndex = it->second->m_Index;
		this->m_NodeTransfrom = this->m_NodeOffset;

	}

	for (const auto& child : node->m_Childern)
	{
		this->children.push_back(std::make_shared<BoneNode>(child.get(), bones));
	}

}

void BoneNode::ProcessNode(glm::mat4 parentGut)
{


	glm::mat4 globalGut = parentGut * m_NodeTransfrom;

	if (this->m_BoneIndex != -1)
	{
		this->m_BoneFinal = globalGut * this->m_BoneOffset;

	}
	for (auto& child : children)
	{
		child->ProcessNode(globalGut);
	}
}

void BoneNode::UpdateBuffer(Ogl::Gut::Effect3d::BoneData& target)
{
	//&& boneIndex < sizeof(BoneData) / sizeof(glm::mat4)
	if (this->m_BoneIndex != -1)
	{
		target.bones[this->m_BoneIndex] = this->m_BoneFinal;
	}
	for (auto& child : children)
	{
		child->UpdateBuffer(target);
	}
}

