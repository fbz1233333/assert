#include "fxcc/graph/Vertex.h"

fxcc::graph::InputLayout fxcc::graph::VertexFixed::Layouts()
{
	std::vector<fxcc::graph::VertexAttr> layouts = {
			   { 0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFixed), (void*)offsetof(VertexFixed, pos) },
			   { 1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFixed), (void*)offsetof(VertexFixed, normal) },
			   { 2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFixed), (void*)offsetof(VertexFixed, tex) },
			   { 3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFixed), (void*)offsetof(VertexFixed, tangent) },
			   { 4, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFixed), (void*)offsetof(VertexFixed, bigTangent) }
	};

	return layouts;
}

fxcc::graph::InputLayout fxcc::graph::VertexSkinned::Layouts()
{
	std::vector<fxcc::graph::VertexAttr> layouts = {
		{ 0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexSkinned), (void*)offsetof(VertexSkinned, pos) },
		{ 1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexSkinned), (void*)offsetof(VertexSkinned, normal) },
		{ 2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexSkinned), (void*)offsetof(VertexSkinned, tex) },
		{ 3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexSkinned), (void*)offsetof(VertexSkinned, tangent) },
		{ 4, 3, GL_FLOAT, GL_FALSE, sizeof(VertexSkinned), (void*)offsetof(VertexSkinned, bigTangent) },
		{ 5, 4, GL_INT,   GL_FALSE, sizeof(VertexSkinned), (void*)offsetof(VertexSkinned, bones1) },
		{ 6, 4, GL_FLOAT, GL_FALSE, sizeof(VertexSkinned), (void*)offsetof(VertexSkinned, weights1) },
		{ 7, 4, GL_INT,   GL_FALSE, sizeof(VertexSkinned), (void*)offsetof(VertexSkinned, bones2) },
		{ 8, 4, GL_FLOAT, GL_FALSE, sizeof(VertexSkinned), (void*)offsetof(VertexSkinned, weights2) }
	};
	return layouts;
}

fxcc::graph::InputLayout fxcc::graph::VertexFont::Layouts()
{
	std::vector<fxcc::graph::VertexAttr> layouts = {
		{ 0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFont), (void*)offsetof(VertexFont, pos) },
		{ 1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFont), (void*)offsetof(VertexFont, tex) },
	};
	return layouts;
}




bool fxcc::graph::VertexSkinned::AddBoneData(const int boneId, const int weightValue)
{
	if (weightValue == 0.0f)
	{
		return false;
	}
	if (boneId < 0)
	{
		return false;
	}

	for (int i = 0; i < 4; i++)
	{
		if (weights1[i] == 0.0f)
		{
			weights1[i] = weightValue;
			bones1[i] = boneId;
			return true;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (weights2[i] == 0.0f)
		{
			weights2[i] = weightValue;
			bones2[i] = boneId;
			return true;
		}
	}
	return false;
}

