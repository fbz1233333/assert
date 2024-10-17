#include "fxcc/graph/Effect3d.h"
#include "ogl/math/Geometry.h"

Ogl::Gut::Effect3d::PassData::PassData(const Ogl::Math::Camera& camera)
{
	this->Load(camera);
}

void Ogl::Gut::Effect3d::PassData::Load(const Ogl::Math::Camera& camera)
{
	proj = camera.GetProjection();
	view = camera.GetViewMatrix();
	projView = proj * view;
	viewPos = camera.position;
}

Ogl::Gut::Effect3d::ObjData::ObjData(const glm::mat4 &model)
{
	world = model;
	worldInv = glm::inverse(world);
	worldInvTranspose = glm::transpose(worldInv);
}

Ogl::Gut::Effect3d::ObjData::ObjData(const Ogl::Math::Transform &transform)
{
	Load(transform);
}

void Ogl::Gut::Effect3d::ObjData::Load(const Ogl::Math::Transform& transform)
{
	world = transform.GetWorld();
	worldInv = glm::inverse(world);
	worldInvTranspose = glm::transpose(worldInv);

}



Ogl::Gut::Effect3d::Effect3d(const std::string& fragMain)
	:m_FragMain(fragMain)
{
	m_PassBuffer = std::make_shared<Ogl::Gut::UniformBuffer>(sizeof(PassData));
	m_ObjBuffer = std::make_shared<Ogl::Gut::UniformBuffer>(sizeof(ObjData));
	m_BoneBuffer = std::make_shared<Ogl::Gut::UniformBuffer>(sizeof(BoneData));

	std::string vertCode = Effect3d::GetVertCode().c_str();
	std::string vertAnimCode = Effect3d::GetVertAnimCode().c_str();
	std::string fragCode = GetFragCode();

	//std::cout << vertCode << std::endl;
	//std::cout << vertAnimCode << std::endl;
	//std::cout << fragCode << std::endl;

	m_Shader = std::make_shared<Ogl::Gut::Shader>(vertCode.c_str(), fragCode.c_str());
	m_AnimShader = std::make_shared<Ogl::Gut::Shader>(vertAnimCode.c_str(), fragCode.c_str());


}

void Ogl::Gut::Effect3d::Begin()
{
	m_PassBuffer->Binding(0);
	m_ObjBuffer->Binding(1);
	m_BoneBuffer->Binding(2);

	m_Shader->Use();
	m_Shader->Bind("PassBuffer", 0);
	m_Shader->Bind("ObjBuffer", 1);

	m_AnimShader->Use();
	m_AnimShader->Bind("PassBuffer", 0);
	m_AnimShader->Bind("ObjBuffer", 1);
	m_AnimShader->Bind("BoneBuffer", 2);

	Ogl::Gut::EffectBase::Begin();
}

void Ogl::Gut::Effect3d::SetPassData(const PassData& passData)
{
	m_PassBuffer->Upload<PassData>(passData);
}

void Ogl::Gut::Effect3d::SetObjData(const ObjData& objData)
{
	m_ObjBuffer->Upload<ObjData>(objData);

}

void Ogl::Gut::Effect3d::SetCamera(const Ogl::Math::Camera& camera)
{
	m_PassBuffer->Upload<PassData>(PassData(camera));
}

void Ogl::Gut::Effect3d::SetTransform(const Ogl::Math::Transform& transform)
{
	m_ObjBuffer->Upload<ObjData>(ObjData(transform));
}


void Ogl::Gut::Effect3d::RenderMesh(const Ogl::Gut::Mesh* mesh, const Ogl::Math::Transform& transform)
{
	m_Shader->Use();
	m_ObjBuffer->Upload<ObjData>(ObjData(transform));
	mesh->Bind();
	mesh->DrawElementsAuto();
}

void Ogl::Gut::Effect3d::RenderMesh(const Ogl::Gut::Mesh* mesh, const Ogl::Gut::MeshOffset& meshOffset, const Ogl::Math::Transform& transform)
{
	m_Shader->Use();
	m_ObjBuffer->Upload<ObjData>(ObjData(transform));
	mesh->Bind();
	mesh->DrawElemenstOffset(meshOffset);
}

void Ogl::Gut::Effect3d::RenderSkinnedMesh(const Ogl::Gut::Mesh* mesh, const Ogl::Math::Transform& transform, const BoneData& boneData)
{
	m_AnimShader->Use();
	m_ObjBuffer->Upload<ObjData>(ObjData(transform));
	m_BoneBuffer->Upload<BoneData>(boneData);
	mesh->Bind();
	mesh->DrawElementsAuto();

}


void Ogl::Gut::Effect3d::End()
{
	Ogl::Gut::Shader::UnUse();

}

const std::string Ogl::Gut::Effect3d::GetVertAnimCode()
{

	kainjow::mustache::mustache m1(GetVertTemp());

	kainjow::mustache::data d1;
	d1.set("uniformPart", GetUniformPart3d());
	d1.set("defines", "#define _SKINNED_VERT_");

	return m1.render(d1);
}


const std::string Ogl::Gut::Effect3d::GetVertCode()
{
	kainjow::mustache::mustache m1(GetVertTemp());

	kainjow::mustache::data d1;
	d1.set("uniformPart", GetUniformPart3d());
	d1.set("defines", "");
	return m1.render(d1);
}






const std::string Ogl::Gut::Effect3d::GetVertTemp()
{

	std::string res = R"(
#version 330 core

{{defines}}
layout(location=0) in vec3 aPos;
layout(location=1) in vec3 aNormal;
layout(location=2) in vec2 aTexCoord;
layout(location=3) in vec3 aTangent;
layout(location=4) in vec3 aBigTangent;

#ifdef _SKINNED_VERT_
layout(location=5) in ivec4 aBones1;
layout(location=6) in vec4 aWeights1;
layout(location=7) in ivec4 aBones2;
layout(location=8) in vec4 aWeights2;

#endif

out vec3 localPos;
out vec4 FragPosAlpha;
out vec3 FragPos;
out vec2 TexCoord;
out vec3 Normal;

{{uniformPart}}

#ifdef _SKINNED_VERT_

mat4 CalBoneGut() {
	mat4 bMat = mat4(0.0f);

	bMat += boneData[aBones1[0]] * aWeights1[0];
	bMat += boneData[aBones1[1]] * aWeights1[1];
	bMat += boneData[aBones1[2]] * aWeights1[2];
	bMat += boneData[aBones1[3]] * aWeights1[3];
	bMat += boneData[aBones2[0]] * aWeights2[0];
	bMat += boneData[aBones2[1]] * aWeights2[1];
	bMat += boneData[aBones2[2]] * aWeights2[2];
	bMat += boneData[aBones2[3]] * aWeights2[3];
	return bMat;
};
#endif

void CalVertexOut()
{
#ifdef _SKINNED_VERT_

	mat4 boneMat=CalBoneGut();
	mat4 FragMat=world * boneMat;
#else
	mat4 FragMat=world ;
	
#endif
	localPos=aPos;
	FragPosAlpha=FragMat * vec4(aPos,1.0f);
	Normal=transpose(inverse(mat3(FragMat)))* aNormal;
	Normal=normalize(Normal);

	FragPos=FragPosAlpha.xyz ;
	TexCoord=aTexCoord.xy;


};

void main()
{
	CalVertexOut();
	gl_Position= projView* vec4(FragPos, 1.0f);

};
	
)";

	return res;
}

const std::string Ogl::Gut::Effect3d::GetFragCodeTemp() {

	return R"(
#version 330 core

in vec3 localPos;
in vec4 FragPosAlpha;
in vec3 FragPos;
in vec2 TexCoord;
in vec3 Normal;


{{uniformPart}}

{{FragPart}}
)";
}


std::string Ogl::Gut::Effect3d::GetFragCode()
{
	kainjow::mustache::mustache m1 = GetFragCodeTemp();

	kainjow::mustache::data d1;
	d1.set("FragPart", this->m_FragMain);
	d1.set("uniformPart", GetUniformPart3d());

	return m1.render(d1);
}

const std::string Ogl::Gut::Effect3d::GetUniformPart3d()
{
	return  R"(



layout(std140) uniform PassBuffer
{
	mat4 proj;
	mat4 view;
	mat4 projView;
	vec3 viewPos;
	float pad;

};

layout(std140) uniform ObjBuffer
{
	mat4 world;
	mat4 worldInv;
	mat4 worldInvTranspose;
	vec3 objBufferPad;
	float borderNormalAxis;

};

#define MAX_NUM_BONES 256

layout(std140) uniform BoneBuffer
{
	mat4 boneData[MAX_NUM_BONES];
};



)";
}