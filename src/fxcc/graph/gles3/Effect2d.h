#pragma once

#include "fxcc/graph/UniformBuffer.h"
#include "fxcc/graph/Shader.h"
#include "fxcc/graph/Mesh.h"
#include "ogl/math/Transform.h"
#include "ogl/math/Geometry.h"
#include "fxcc/graph/EffectBase.h"

#include "mustache.hpp"


namespace Ogl
{
	namespace Gut
	{
		struct Effect2d :public Ogl::Gut::EffectBase
		{

			std::shared_ptr<Ogl::Gut::Shader>  m_Shader;
			std::shared_ptr<Ogl::Gut::Mesh> m_QuadMesh, m_2DShowMesh;

			Effect2d(const std::string& fCode);
			std::string m_FragMain;

			void Begin();

			void RenderMesh(const Ogl::Gut::Mesh* mesh);
			void DebugQuad();
			void Debug2DShowMesh();
			void End();

			std::string GetFragCode();
			static std::string GetVertCode();
			static std::string GetFragTemp();
		};
	};
};