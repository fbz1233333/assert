#include "fxcc/graph/Image.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize2.h"

using namespace fxcc::graph;

void Image::Write(const std::string& path) const
{
	std::ofstream ofs(path, std::ios::binary);

	Write(ofs);
	ofs.flush();
	ofs.close();

}

void Image::Write(std::ofstream& ofs) const
{
	ofs.write((const char*)&m_HD, sizeof(m_HD));
	ofs.write((const char*)m_Data, m_HD.DataSize());

}

void Image::Read(const std::string& path)
{
	std::ifstream ifs(path, std::ios::binary);
	Read(ifs);
	ifs.close();
}

void Image::Read(std::ifstream& ifs)
{
	ifs.read((char*)&m_HD, sizeof(m_HD));
	
	AllocData();
	ifs.read((char*)m_Data, m_HD.DataSize());
	
}

void Image::WriteBMP(const std::string& path) const
{
	stbi_write_bmp(path.c_str(), m_HD.m_Width, m_HD.m_Height, m_HD.m_NrComponent, m_Data);
}

// int Image::GetDataType() const
// {
// 	return m_HD.m_Hdr ? GL_FLOAT : GL_UNSIGNED_BYTE;
// }

// int Image::GetFormat() const
// {
// 	static std::vector<int> fmts =
// 		{
// 			GL_NONE,
// 			GL_RED,
// 			GL_RG,
// 			GL_RGB,
// 			GL_RGBA,
// 		};

// 	return fmts[m_HD.m_NrComponent];
// };

// int Image::GetInternalFormat() const
// {
// 	static std::vector<int> internalFmts =
// 		{
// 			GL_NONE,
// 			GL_R8,
// 			GL_RG8,
// 			GL_RGB8,
// 			GL_RGBA8,
// 		};

// 	static std::vector<int> internalFmtsHdr =
// 		{
// 			GL_NONE,
// 			GL_R16F,
// 			GL_RG16F,
// 			GL_RGB16F,
// 			GL_RGBA16F,
// 		};
// 	if (m_HD.m_Hdr)
// 	{
// 		return internalFmtsHdr[m_HD.m_NrComponent];
// 	}
// 	else
// 	{
// 		return internalFmts[m_HD.m_NrComponent];
// 	}

// 	return 0;
// }

void *Image::GetData() const
{
	return m_Data;
}

void Image::Free()
{
	if(m_Data)
	{
		free(m_Data);
		m_Data = 0;

	}else
	{
		std::cout << "failed free null data" << std::endl;
	}
}

void Image::Resize(int w, int h)
{
	m_HD.m_Width = w;
	m_HD.m_Height = h;
}

Image::Image(const Desc &desc)
	: m_Desc(desc)
{
	m_Avail = Init();
}

bool Image::Init()
{
	auto desc = m_Desc;
	m_HD.m_Hdr = desc.m_hdr;
	if (desc.m_hdr)
	{
		m_Data = stbi_loadf(desc.m_Path.c_str(), &m_HD.m_Width, &m_HD.m_Height, &m_HD.m_NrComponent, desc.m_ReqComponent);
	}
	else
	{
		m_Data = stbi_load(desc.m_Path.c_str(), &m_HD.m_Width, &m_HD.m_Height, &m_HD.m_NrComponent, desc.m_ReqComponent);
	};

	if (desc.m_ReqComponent > 0 && desc.m_ReqComponent <= 4)
	{
		m_HD.m_NrComponent = desc.m_ReqComponent;
	};
	return true;
}
