#pragma once

#include "fxcc/graph/BoneNode.h"
#include "fxcc/graph/Channel.h"

namespace Ogl
{
	namespace Gut
	{


		struct ChannelMap {

			struct Data
			{
				BoneNode* m_BoneNode;
				const Ogl::Gut::Channel* m_Channel;
				void Sync(double tick)
				{
					m_BoneNode->m_NodeTransfrom = m_Channel->GetSlerpTransform(tick);
				};

			};

			std::vector<Data> m_Datas;
			double m_AnimTotalTime = 0.f;
			double m_Duration = 0.0f;
			double m_TicksPersecond = 20.f;

			double m_CurrentTicks = 0.0f;

			ChannelMap(BoneNode* boneNode, const Ogl::Gut::Animation* anim)
				:m_AnimTotalTime(anim->m_TotalTime), m_Duration(anim->m_Duration), m_TicksPersecond(anim->m_TicksPerSecond)
			{
				ProcessNode(boneNode, anim);
			}
			void ProcessNode(BoneNode* boneNode, const Ogl::Gut::Animation* anim);

			void SetTicks(const double currentTicks)
			{
				this->m_CurrentTicks = currentTicks;
			}
			void SetAxis(float axis)
			{
				this->m_CurrentTicks = axis * m_Duration;
			}

			void SyncNodeTransform()
			{
				for (auto data : m_Datas)
				{
					data.Sync(m_CurrentTicks);

				}
			};
		};
	}
}