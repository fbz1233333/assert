#include "fxcc/graph/Texture2D.h"
#include "fxcc/graph/Dictionary.h"

void Ogl::Gut::Texture2D::Init()
{
	switch (m_Desc.m_Type)
	{
	case Texture2DDescType::_texture_2d_desc_origin_data_:
		Init1();
		break;
	case Texture2DDescType::_texture_2d_desc_imaga_desc_:
		Init2();
		break;
	case Texture2DDescType::_texture_2d_desc_origin_file_:
		Init3();
		break;
	default:
		// std::cout << "cannot create from the desc" << std::endl;
		break;
	}
};

void Ogl::Gut::Texture2D::Init1()
{
	Bind();
	const auto& desc = m_Desc.m_Desc1;

	TexImage2D(GL_TEXTURE_2D, 0, desc.m_Image);
	Dictionary::SetSampler(GL_TEXTURE_2D, desc.m_SamplerType);
	if (desc.m_Mipmap)
	{
		Mipmap();
	}
}

void Ogl::Gut::Texture2D::Init2()
{
	m_Desc.Parse2To1();
	Init1();
}


void Ogl::Gut::Texture2D::Init3()
{
	m_Desc.Parse3To1();
	Init1();
}

void Ogl::Gut::Texture2D::Resize(int width, int height) 
{
	auto& currentImage = m_Desc.m_Desc1.m_Image;
	bool mipmap = m_Desc.m_Desc1.m_Mipmap;

	if (currentImage.m_Data == nullptr)
	{
		currentImage.m_HD.m_Width = width;
		currentImage.m_HD.m_Height = height;

		Bind();
		TexImage2D(GL_TEXTURE_2D, 0, currentImage);

		if (mipmap)
		{
			Mipmap();
		}
	}
};
void Ogl::Gut::Texture2D::UnBind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
