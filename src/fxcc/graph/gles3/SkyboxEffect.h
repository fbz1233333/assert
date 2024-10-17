#pragma once

#include "fxcc/graph/types.h"
#include "ogl/math/types.h"
#include "fxcc/graph/EffectBase.h"

namespace Ogl
{
	namespace Gut
	{

		struct SkyboxEffect :public Ogl::Gut::EffectBase
		{

			std::shared_ptr<Ogl::Gut::Mesh> m_SkyboxMesh;
			std::shared_ptr<Ogl::Gut::Shader> m_Shader;

			std::string m_FragMain;

			SkyboxEffect();
			SkyboxEffect(const std::string& fragMain);
			void Init();
			void Begin();
			void End();
			void SetCamera(const Ogl::Math::Camera& camera, bool gamma=false);
			void RenderSkybox(Ogl::Gut::TextureCube* texture, bool gamma = false);
			void RenderSkybox(Ogl::Gut::TextureCube* texture, const Ogl::Math::Camera& camera, bool gamma=false);

			std::string GetFragCode();

			static std::string GetVertCode();
			static std::string GetFragTemp();
			static std::string GetDefaultFragCode();
		};
	};
}
