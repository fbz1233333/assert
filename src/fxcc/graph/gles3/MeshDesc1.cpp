#include "fxcc/graph/MeshDesc1.h"


void Ogl::Gut::MeshDesc1::Write(std::ofstream& ofs) const
{
	ofs.write((const char*)&m_HD, sizeof(m_HD));

	// write the vertcies data
	ofs.write((const char*)m_Vertices, m_HD.VertexStride() * m_HD.m_NumVertices);

	// write the index data
	ofs.write((const char*)m_Indices, m_HD.IndexStride() * m_HD.m_NumIndices);

}

void Ogl::Gut::MeshDesc1::Write(std::string path) const
{
	std::ofstream ofs(path, std::ios::binary);

	Write(ofs);
	ofs.flush();
	ofs.close();
}

void Ogl::Gut::MeshDesc1::Read(std::ifstream& ifs)
{

	ifs.read((char*)&m_HD, sizeof(m_HD));

	AllocData();

	// read the vertcies data
	ifs.read((char*)m_Vertices, m_HD.VertexStride() * m_HD.m_NumVertices);

	// read the index data
	ifs.read((char*)m_Indices, m_HD.IndexStride() * m_HD.m_NumIndices);

}

void Ogl::Gut::MeshDesc1::Read(std::string path)
{
	std::ifstream ifs(path, std::ios::binary);

	Read(ifs);
	ifs.close();
}