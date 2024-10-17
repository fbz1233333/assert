#include "fxcc/graph/Effect2d.h"
#include "ogl/math/GeometryData.h"

Ogl::Gut::Effect2d::Effect2d(const std::string& fCode)
	:m_FragMain(fCode)
{
	std::string vertCode = GetVertCode();
	std::string fragCode = GetFragCode();

	m_Shader = std::make_shared<Ogl::Gut::Shader>(vertCode.c_str(), fragCode.c_str());
	m_QuadMesh = std::make_shared<Ogl::Gut::Mesh>(Geometry::CreateQuad());
	m_2DShowMesh = std::make_shared<Ogl::Gut::Mesh>(Geometry::Create2DTexture());

	
}

void Ogl::Gut::Effect2d::Begin()
{
	m_Shader->Use();
}

void Ogl::Gut::Effect2d::RenderMesh(const Ogl::Gut::Mesh* mesh)
{
	mesh->Bind();
	mesh->DrawElementsAuto();
}

void Ogl::Gut::Effect2d::DebugQuad()
{
	RenderMesh(m_QuadMesh.get());
}

void Ogl::Gut::Effect2d::Debug2DShowMesh()
{
	RenderMesh(m_2DShowMesh.get());
}

void Ogl::Gut::Effect2d::End()
{
	Ogl::Gut::Shader::UnUse();
}

std::string Ogl::Gut::Effect2d::GetVertCode()
{
	const char* vCode = R"(

#version 330 core

layout(location=0) in vec3 aPos;
layout(location=1) in vec3 aNormal;
layout(location=2) in vec2 aTexCoord;

out vec3 FragPos;
out vec3 Normal;
out vec2 TexCoord;

void CalVertexOut()
{
	FragPos=aPos;
	TexCoord=aTexCoord;
	Normal=aNormal;

};
void main()
{
	CalVertexOut();
	gl_Position=vec4(aPos,1.0f);	
};
)";
	return vCode;
}

std::string Ogl::Gut::Effect2d::GetFragTemp()
{
	const char* fCode = R"(

#version 330 core


in vec2 TexCoord;
in vec3 FragPos ;
in vec3 Normal;


{{FragMain}}

)";

	return fCode;
}


std::string Ogl::Gut::Effect2d::GetFragCode()
{
	kainjow::mustache::mustache m1 = GetFragTemp();

	kainjow::mustache::data d1;
	d1.set("FragMain", this->m_FragMain);

	return m1.render(d1);

}
