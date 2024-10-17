#include "fxcc/graph/Sampler.h"

using namespace Ogl::Gut;

SamplerDesc::SamplerDesc()
{
	memset((char *)this, 0, sizeof(*this));
}

void SamplerDesc::BindTexture(int target) const
{

#ifdef WIN32
	if (useBorderColor)
	{
		glTexParameterfv(target, GL_TEXTURE_BORDER_COLOR, borderColor);
	}
#endif // DEBUG

	if (minFilter != 0)
	{
		glTexParameteri(target, GL_TEXTURE_MIN_FILTER, minFilter);
	}
	if (magFilter != 0)
	{
		glTexParameteri(target, GL_TEXTURE_MAG_FILTER, magFilter);
	}
	if (wrapS != 0)
	{
		glTexParameteri(target, GL_TEXTURE_WRAP_S, wrapS);
	}
	if (wrapT != 0)
	{
		glTexParameteri(target, GL_TEXTURE_WRAP_T, wrapT);
	}
	if (wrapR != 0)
	{
		glTexParameteri(target, GL_TEXTURE_WRAP_R, wrapR);
	}
	// if (lodBias != 0.0f)
	// {
	// 	glTexParameterf(target, GL_TEXTURE_LOad, lodBias);
	// }
	if (minLod != 0)
	{
		glTexParameteri(target, GL_TEXTURE_MIN_LOD, minLod);
	}
	if (maxLod != 0)
	{
		glTexParameteri(target, GL_TEXTURE_MAX_LOD, maxLod);
	}
	if (baseLevel != 0)
	{
		glTexParameteri(target, GL_TEXTURE_BASE_LEVEL, baseLevel);
	}
	if (maxLevel != 0)
	{
		glTexParameteri(target, GL_TEXTURE_MAX_LEVEL, maxLevel);
	}
	if (compareMode != 0)
	{
		glTexParameteri(target, GL_TEXTURE_COMPARE_MODE, compareMode);
	}
	if (compareFunc != 0)
	{
		glTexParameteri(target, GL_TEXTURE_COMPARE_FUNC, compareFunc);
	}
	if (swizzleR != 0)
	{
		glTexParameteri(target, GL_TEXTURE_SWIZZLE_R, swizzleR);
	}
	if (swizzleG != 0)
	{
		glTexParameteri(target, GL_TEXTURE_SWIZZLE_G, swizzleG);
	}
	if (swizzleB != 0)
	{
		glTexParameteri(target, GL_TEXTURE_SWIZZLE_B, swizzleB);
	}
	if (swizzleA != 0)
	{
		glTexParameteri(target, GL_TEXTURE_SWIZZLE_A, swizzleA);
	}
}

bool Ogl::Gut::Sampler::CreateFromDesc(const SamplerDesc &desc)
{
	glGenSamplers(1, &ID);
	glSamplerParameteri(ID, GL_TEXTURE_MIN_FILTER, desc.minFilter);
	glSamplerParameteri(ID, GL_TEXTURE_MAG_FILTER, desc.magFilter);
	glSamplerParameteri(ID, GL_TEXTURE_WRAP_S, desc.wrapS);
	glSamplerParameteri(ID, GL_TEXTURE_WRAP_R, desc.wrapR);
	glSamplerParameteri(ID, GL_TEXTURE_WRAP_T, desc.wrapT);

	return true;
}

void Ogl::Gut::Sampler::Bind(unsigned int tex)
{
	glBindSampler(tex, this->ID);
}