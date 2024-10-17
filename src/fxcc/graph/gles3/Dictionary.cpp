#include "fxcc/graph/Dictionary.h"

using namespace Ogl::Gut;

std::vector<DataTypeDesc> Dictionary::m_DataTypeDescs =
	{
		{"None", GL_NONE},
		{"Float", GL_FLOAT},
		{"Unsigned Byte", GL_UNSIGNED_BYTE},
		{"Unsigned Short", GL_UNSIGNED_SHORT},
		{"Unsigned Int", GL_UNSIGNED_INT},
		{"Byte", GL_BYTE},
		{"Short", GL_SHORT},
		{"Int", GL_INT},
};

std::vector<AnimationDescTypeDesc>
	Dictionary::m_AnimationDescTypeDescs =
		{
			{"None"},
			{"Model File"}};

std::vector<RenderTargetDescTypeDesc> Dictionary::m_RenderTargetDescTypeDescs =
	{
		{"None"},
		{"desc1"},
		{"desc2"}};

std::vector<VertexTypeDesc> Ogl::Gut::Dictionary::m_VertexDescs =
	{
		{"None", 0, {}},
		{"VertexFixed", sizeof(VertexFixed), VertexFixed::Layouts()},
		{"VertexSkinned", sizeof(VertexSkinned), VertexSkinned::Layouts()},
		{"VertexFont", sizeof(VertexFont), VertexFont::Layouts()},
};

std::vector<IndexTypeDesc> Ogl::Gut::Dictionary::m_IndexDescs =
	{
		{"None", GL_NONE, 0},
		{"unsigned byte", GL_UNSIGNED_BYTE, 1},
		{"unsigned short", GL_UNSIGNED_SHORT, 2},
		{"unsigned int", GL_UNSIGNED_INT, 4},

};

std::vector<ModeTypeDesc> Ogl::Gut::Dictionary::m_ModeDescs = {

	{"None", 0},
	{"Triangle", GL_TRIANGLES},
	{"Triangle Fan", GL_TRIANGLE_FAN},
	{"Triangle Stripe", GL_TRIANGLE_STRIP},
	{"Lines", GL_LINES},
	{"Line Stripe", GL_LINE_STRIP},
	{"Line Loop", GL_LINE_LOOP}};

std::vector<Ogl::Gut::TextureTypeDesc> Ogl::Gut::Dictionary::m_TextureDescs = {

	{"None", GL_NONE},
	{"Texture2D", GL_TEXTURE_2D},
	{"TextureCube", GL_TEXTURE_CUBE_MAP},
	{"Texture2DArray", GL_TEXTURE_2D_ARRAY}

};

std::vector<MeshDescTypeDesc> Ogl::Gut::Dictionary::m_MeshDescTypeDescs =
	{
		{"None"},
		{"Origin Data"},
		{"Mesh Data"},
		{"Origin Data file"},
		{"Mesh Data File"},
		{"Model File"}};

std::vector<LightSourceTypeDesc> Ogl::Gut::Dictionary::m_LightSourceTypeDesc =
	{
		{"none"},
		{"directioon"},
		{"point"},
		{"spot"},
		{"ambient"},
		{"area"},
};

std::vector<Ogl::Gut::SamplerTypeDesc> Ogl::Gut::Dictionary::m_SamplerDescs =
	{
		{"texture none", Dictionary::GetSamplerLinearClamp()},
		{"texture 2d default", Dictionary::GetSamplerLinearClamp()},
		{"texture Cube default", Dictionary::GetSamplerLinearClamp()},
		{"texture 2d array default", Dictionary::GetSamplerLinearClamp()},

};

std::vector<Texture2DDescTypeDesc> Ogl::Gut::Dictionary::m_Texture2DDescTypeDesc =
	{
		{"None"},
		{"Origin Data"},
		{"Image Desc"},
		{"Origin Data File"},

};

std::vector<ShaderDescTypeDesc> Ogl::Gut::Dictionary::m_ShaderDescTypeDesc =
	{
		{"None"},
		{"Shader Code"},
		{"Shader File"}};

std::vector<TextureMaterialTypeDesc> Ogl::Gut::Dictionary::m_TextureMatTypeDesc =
	{
		{"_Texture_Mat_NONE"},
		{"_Texture_Mat_DIFFUSE"},
		{"_Texture_Mat_SPECULAR"},
		{"_Texture_Mat_AMBIENT"},
		{"_Texture_Mat_EMISSIVE"},
		{"_Texture_Mat_HEIGHT"},
		{"_Texture_Mat_NORMALS"},
		{"_Texture_Mat_SHININESS"},
		{"_Texture_Mat_OPACITY"},
		{"_Texture_Mat_DISPLACEMENT"},
		{"_Texture_Mat_LIGHTMAP"},
		{"_Texture_Mat_REFLECTION"},
		{"_Texture_Mat_BASE_COLOR"},
		{"_Texture_Mat_NORMAL_CAMERA"},
		{"_Texture_Mat_EMISSION_COLOR"},
		{"_Texture_Mat_METALNESS"},
		{"_Texture_Mat_DIFFUSE_ROUGHNESS"},
		{"_Texture_Mat_AMBIENT_OCCLUSION"},
		{"_Texture_Mat_UNKNOWN"},
		//{"_Texture_Mat_End"},

};

Ogl::Gut::SamplerDesc Ogl::Gut::Dictionary::GetSamplerLinearClamp()
{
	Ogl::Gut::SamplerDesc res;
	res.magFilter = GL_LINEAR;
	res.minFilter = GL_LINEAR;
	res.wrapR = GL_CLAMP_TO_EDGE;
	res.wrapS = GL_CLAMP_TO_EDGE;
	res.wrapT = GL_CLAMP_TO_EDGE;

	return res;
}

void Ogl::Gut::Dictionary::SetSampler(int target, int type)
{
	const auto &samp = m_SamplerDescs[type].m_SampDesc;
	samp.BindTexture(target);
}
