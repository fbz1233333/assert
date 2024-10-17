#include "fxcc/graph/MeshDesc.h"

using namespace Ogl::Gut;

Ogl::Gut::MeshDesc::MeshDesc(const GeometryData& geoData)
{

	std::vector<VertexFixed> vertices;
	vertices.resize(geoData.vertices.size());

	for (int i = 0; i < geoData.vertices.size(); i++)
	{
		vertices[i].Load(geoData, i);
	}

	Ogl::Gut::MeshDesc2& desc = m_Desc2;
	desc.m_HD.m_IndexType = Ogl::Gut::IndexType::_index_unsigned_int_;
	desc.m_HD.m_VertexType = Ogl::Gut::VertexType::_vertex_fixed_;
	desc.m_HD.m_ModeType = Ogl::Gut::ModeType::_mode_Triangles_;

	desc.m_VerticesFixed = vertices;
	desc.m_Indices32 = geoData.indices32;

	m_Type = MeshDescType::_mesh_mesh_data_;


}

void Ogl::Gut::MeshDesc::Translate2To1()
{
	m_Desc1.m_HD.m_IndexType = m_Desc2.m_HD.m_IndexType;
	m_Desc1.m_HD.m_VertexType = m_Desc2.m_HD.m_VertexType;
	m_Desc1.m_HD.m_ModeType = m_Desc2.m_HD.m_ModeType;

	switch (m_Desc2.m_HD.m_IndexType)
	{

	case IndexType::_index_unsigned_byte_:
	{
		auto& indices = m_Desc2.m_Indices8;

		m_Desc1.m_Indices = &indices[0];
		m_Desc1.m_HD.m_NumIndices = indices.size();

	}
	break;

	case IndexType::_index_unsigned_short_:
	{
		auto& indices = m_Desc2.m_Indices16;

		m_Desc1.m_Indices = &indices[0];
		m_Desc1.m_HD.m_NumIndices = indices.size();

	}
	break;

	case IndexType::_index_unsigned_int_:
	{
		auto& indices = m_Desc2.m_Indices32;

		m_Desc1.m_Indices = &indices[0];
		m_Desc1.m_HD.m_NumIndices = indices.size();

	}
	break;

	default:
		std::cout << "cannot translate 2 to 1 indices" << std::endl;
		break;
	}

	switch (m_Desc2.m_HD.m_VertexType)
	{
	case VertexType::_vertex_fixed_:
	{
		auto& vertices = m_Desc2.m_VerticesFixed;

		m_Desc1.m_Vertices = &vertices[0];
		m_Desc1.m_HD.m_NumVertices = vertices.size();

	}; break;

	case VertexType::_vertex_skinned_:
	{
		auto& vertices = m_Desc2.m_VerticesSkinneds;

		m_Desc1.m_Vertices = &vertices[0];
		m_Desc1.m_HD.m_NumVertices = vertices.size();

	}; break;

	case VertexType::_vertex_font_:
	{
		auto& vertices = m_Desc2.m_VerticesFont;

		m_Desc1.m_Vertices = &vertices[0];
		m_Desc1.m_HD.m_NumVertices = vertices.size();

	}; break;
	default:

		std::cout << "cannot translate desc2 to desc1" << std::endl;
		break;
	}
}

void Ogl::Gut::MeshDesc::Parse3To1()
{
	m_Desc1.Read(m_Desc3.m_Path);
}

void Ogl::Gut::MeshDesc::Parse4To2()
{
	m_Desc2.Read(m_Desc4.m_Path);
}

