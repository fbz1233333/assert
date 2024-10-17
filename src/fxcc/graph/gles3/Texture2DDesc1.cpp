#include "fxcc/graph/Texture2DDesc1.h"


void Ogl::Gut::Texture2DDesc1::Write(const std::string& path)
{
	std::ofstream ofs(path, std::ios::binary);

	Write(ofs);

	ofs.flush();
	ofs.close();
}

void Ogl::Gut::Texture2DDesc1::Write(std::ofstream& ofs)
{
	ofs.write((const char*)&m_Mipmap, sizeof(m_Mipmap));
	ofs.write((const char*)&m_SamplerType, sizeof(m_SamplerType));
	m_Image.Write(ofs);

}

void Ogl::Gut::Texture2DDesc1::Read(const std::string& path)
{
	std::ifstream ifs(path, std::ios::binary);
	Read(ifs);
	ifs.close();

};

void Ogl::Gut::Texture2DDesc1::Read(std::ifstream& ifs)
{
	ifs.read((char*)&m_Mipmap, sizeof(m_Mipmap));
	ifs.read((char*)&m_SamplerType, sizeof(m_SamplerType));
	m_Image.Read(ifs);
};
