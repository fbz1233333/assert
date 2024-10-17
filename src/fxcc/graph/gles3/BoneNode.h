#pragma once

#include "fxcc/graph/Scene.h"
#include "fxcc/graph/Node.h"
#include "fxcc/graph/Bone.h"
#include "fxcc/graph/BoneNode.h"
#include "fxcc/graph/Effect3d.h"


namespace Ogl
{
	namespace Gut
	{
		struct BoneNode
		{
			std::string m_NodeName;
			glm::mat4 m_NodeOffset;
			glm::mat4 m_NodeTransfrom;
			glm::mat4 m_BoneOffset;
			glm::mat4 m_BoneFinal;
			int m_BoneIndex = -1;

			BoneNode(const Ogl::Gut::Node* node, const std::map<std::string, std::shared_ptr<Ogl::Gut::Bone>>& bones);

			void ProcessNode(glm::mat4 parentGut);
			void UpdateBuffer(Ogl::Gut::Effect3d::BoneData& target);

			std::vector<std::shared_ptr<BoneNode>> children;
		};

	};
};
