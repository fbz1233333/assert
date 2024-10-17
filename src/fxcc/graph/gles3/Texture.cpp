#include "fxcc/graph/Texture.h"

using namespace Ogl::Gut;


void Texture::Bind() const
{
	glBindTexture(GetTarget(), m_Id);

}

void Texture::Mipmap() const
{
	glGenerateMipmap(GetTarget());
}


void Texture::Create()
{
	glGenTextures(1, &m_Id);
}

void Ogl::Gut::Texture::Delete()
{
	glDeleteTextures(1, &m_Id);
}

void Texture::TexImage2D(int target, int level, const Image &image) const
{
	glTexImage2D(target, level, image.GetInternalFormat(), image.m_HD.m_Width, image.m_HD.m_Height, 0, image.GetFormat(), image.GetDataType(), image.GetData());
}

unsigned int Texture::GetTarget() const
{
	return m_Target;
}