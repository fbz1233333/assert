#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/RenderStatus.h"
#include "fxcc/graph/UniformBuffer.h"
#include "fxcc/graph/Shader.h"
#include "fxcc/graph/Mesh.h"
#include "fxcc/graph/EffectBase.h"

#include "ogl/math/Camera.h"
#include "mustache.hpp"
#include <map>

#define MAX_BONES 256


namespace Ogl
{
	namespace Gut
	{
		struct Effect3d :public Ogl::Gut::EffectBase
		{

			std::shared_ptr<Ogl::Gut::UniformBuffer> m_PassBuffer, m_ObjBuffer, m_BoneBuffer;
			std::shared_ptr<Ogl::Gut::Shader> m_Shader,m_AnimShader;

			glm::vec4 m_BackColor = glm::vec4(0.0f);
			int m_ClearFlag = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT;
		
			struct PassData 
			{
				glm::mat4 proj;
				glm::mat4 view;
				glm::mat4 projView;
				glm::vec3 viewPos;
				float pad = 0.0f;
				
				PassData() = default;
				PassData(const Ogl::Math::Camera& camera);
				void Load(const Ogl::Math::Camera& camera);

			};

			
			struct ObjData
			{
				glm::mat4 world;
				glm::mat4 worldInv;
				glm::mat4 worldInvTranspose;
				glm::vec3 pad;
				float borderNormalAxis = 0.f;

				ObjData() = default;
				ObjData(const glm::mat4 &model);
				ObjData(const Ogl::Math::Transform& transform);
				void Load(const Ogl::Math::Transform& transform);
			};

			struct BoneData {

				glm::mat4 bones[MAX_BONES];
			};



			Effect3d(const std::string& fragMain);

			void Begin();
			void SetPassData(const PassData& passData);
			void SetObjData(const ObjData& objData);

			void SetCamera(const Ogl::Math::Camera& camera);
			void SetTransform(const Ogl::Math::Transform& transform);
			void RenderMesh(const Ogl::Gut::Mesh* mesh, const Ogl::Math::Transform& transform);
			void RenderMesh(const Ogl::Gut::Mesh* mesh, const Ogl::Gut::MeshOffset& meshOffset, const Ogl::Math::Transform& transform);
			void RenderSkinnedMesh(const Ogl::Gut::Mesh* mesh, const Ogl::Math::Transform& transform, const BoneData& boneData);
			void End();

			std::string m_FragMain = "void main(){}";
			std::string GetFragCode();

			static const std::string GetVertTemp();
			static const std::string GetVertCode();
			static const std::string GetVertAnimCode();
			static const std::string GetFragCodeTemp();
			static const std::string GetUniformPart3d();

			
		};
	};

};