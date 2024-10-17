#include "fxcc/graph/MeshDesc2.h"


void Ogl::Gut::MeshDesc2::Write(std::string path)
{
	std::ofstream ofs(path, std::ios::binary);

	Write(ofs);

	ofs.flush();
	ofs.close();
}

void Ogl::Gut::MeshDesc2::Write(std::ofstream& ofs)
{
	Calculate();
	ofs.write((const char*)&m_HD, sizeof(m_HD));

	if (m_Indices8.size())
		ofs.write((const char*)&m_Indices8[0], sizeof(unsigned char) * m_Indices8.size());
	if (m_Indices16.size())
		ofs.write((const char*)&m_Indices16[0], sizeof(unsigned short) * m_Indices16.size());
	if (m_Indices32.size())
		ofs.write((const char*)&m_Indices32[0], sizeof(unsigned int) * m_Indices32.size());
	if (m_VerticesFixed.size())
		ofs.write((const char*)&m_VerticesFixed[0], sizeof(VertexFixed) * m_VerticesFixed.size());
	if (m_VerticesSkinneds.size())
		ofs.write((const char*)&m_VerticesSkinneds[0], sizeof(VertexSkinned) * m_VerticesSkinneds.size());
	if (m_VerticesFont.size())
		ofs.write((const char*)&m_VerticesFont[0], sizeof(VertexFont) * m_VerticesFont.size());
}

void Ogl::Gut::MeshDesc2::Read(std::string path)
{
	std::ifstream ifs(path, std::ios::binary);
	Read(ifs);

	ifs.close();
}

void Ogl::Gut::MeshDesc2::Read(std::ifstream& ifs)
{
	ifs.read((char*)&m_HD, sizeof(m_HD));
	Resize();

	if (m_Indices8.size())
		ifs.read((char*)&m_Indices8[0], sizeof(unsigned char) * m_Indices8.size());
	if (m_Indices16.size())
		ifs.read((char*)&m_Indices16[0], sizeof(unsigned short) * m_Indices16.size());
	if (m_Indices32.size())
		ifs.read((char*)&m_Indices32[0], sizeof(unsigned int) * m_Indices32.size());
	if (m_VerticesFixed.size())
		ifs.read((char*)&m_VerticesFixed[0], sizeof(VertexFixed) * m_VerticesFixed.size());
	if (m_VerticesSkinneds.size())
		ifs.read((char*)&m_VerticesSkinneds[0], sizeof(VertexSkinned) * m_VerticesSkinneds.size());
	if (m_VerticesFont.size())
		ifs.read((char*)&m_VerticesFont[0], sizeof(VertexFont) * m_VerticesFont.size());
}
