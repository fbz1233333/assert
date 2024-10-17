#pragma once
#include "fxcc/graph/pch.h"
#include "fxcc/graph/Vertex.h"
#include "fxcc/graph/Type.h"

namespace Ogl
{
	namespace Gut
	{

		struct Dictionary
		{
			static std::vector<VertexTypeDesc> m_VertexDescs;
			static std::vector<IndexTypeDesc> m_IndexDescs;
			static std::vector<ModeTypeDesc> m_ModeDescs;
			static std::vector<TextureTypeDesc> m_TextureDescs;
			static std::vector<SamplerTypeDesc> m_SamplerDescs;
			static std::vector<LightSourceTypeDesc> m_LightSourceTypeDesc;
			static std::vector<MeshDescTypeDesc> m_MeshDescTypeDescs;
			static std::vector<Texture2DDescTypeDesc> m_Texture2DDescTypeDesc;
			static std::vector<ShaderDescTypeDesc> m_ShaderDescTypeDesc;
			static std::vector<TextureMaterialTypeDesc> m_TextureMatTypeDesc;
			static std::vector<RenderTargetDescTypeDesc> m_RenderTargetDescTypeDescs;
			static std::vector<AnimationDescTypeDesc> m_AnimationDescTypeDescs;
			static std::vector<DataTypeDesc> m_DataTypeDescs;
			
			static Texture2DDescTypeDesc GetTexture2DDescTypeDesc(int type)
			{
				return m_Texture2DDescTypeDesc[type];
			};

			static ShaderDescTypeDesc GetShaderTypeDesc(int type)
			{
				return m_ShaderDescTypeDesc[type];
			};

			static SamplerTypeDesc GetSamplerTypeDesc(int type)
			{
				return m_SamplerDescs[type];
			};

			static VertexTypeDesc GetVertiexDesc(int type)
			{
				return m_VertexDescs[type];
			}

			static IndexTypeDesc GetIndexDesc(int type)
			{
				return m_IndexDescs[type];
			}

			static ModeTypeDesc GetModeTypeDesc(int type)
			{
				return m_ModeDescs[type];
			}

			static TextureTypeDesc GetTextureDesc(int type)
			{
				return m_TextureDescs[type];
			}
			static Ogl::Gut::SamplerDesc GetSamplerLinearClamp();

			static void SetSampler(int target, int type);
		};
	}
}