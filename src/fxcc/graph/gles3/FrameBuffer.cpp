#include "fxcc/graph/FrameBuffer.h"

using namespace Ogl::Gut;

FrameBuffer::FrameBuffer() 
{
	Create();
};

void FrameBuffer::BufferTextureLayer(unsigned int attachment, unsigned int texId, int level, int layer)
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_Id);
	glFramebufferTextureLayer(GL_FRAMEBUFFER, attachment, texId, level, layer);
}

bool FrameBuffer::CheckError()
{
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		std::cerr << "Framebuffer is not complete!" << std::endl;
		return true;
	}
	return false;
}

void FrameBuffer::BufferTexture2D(unsigned int attachment, unsigned int texTarget, unsigned int ID, unsigned int mipLevel)
{
	glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, texTarget, ID, mipLevel);
}

void FrameBuffer::BufferTextureLayer(unsigned int attachment, unsigned int tex, unsigned int mipLevel, unsigned int zOff)
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_Id);
	glFramebufferTextureLayer(GL_FRAMEBUFFER, attachment, tex, mipLevel, zOff);
}

void FrameBuffer::FrameRenderBuffer(unsigned int attachment, unsigned int RBO)
{
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, attachment, GL_RENDERBUFFER, RBO);
}

void FrameBuffer::ReadBuffer(unsigned int attachment)
{
	glReadBuffer(attachment);
}

void Ogl::Gut::FrameBuffer::DrawBuffer(unsigned int attachment)
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_Id);
	std::vector<unsigned int> attachemets ;
	attachemets.push_back(attachment);
	// glDrawBuffers(&attachments[0] ,attachemets.size());
	DrawBuffers(&attachemets[0], attachemets.size());
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
};

void FrameBuffer::DrawBuffers(unsigned int* attachments, int num)
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_Id);
	glDrawBuffers(num, attachments);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FrameBuffer::Create()
{
	glGenFramebuffers(1, &m_Id);
}

void FrameBuffer::Bind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, this->m_Id);
}

void FrameBuffer::BufferTexture(unsigned int attachment, unsigned int texId, int level)
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_Id);
	// glFramebufferTexture(GL_FRAMEBUFFER, attachment, texId, level);
}

void FrameBuffer::BufferTexture3D(unsigned int attachment, unsigned int texTarget, unsigned int tex, unsigned int mipLevel, unsigned int zOff)
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_Id);
	// glFramebufferTexture3D(GL_FRAMEBUFFER, attachment, texTarget, tex, mipLevel, zOff);
}

FrameBuffer::~FrameBuffer()
{
	glDeleteFramebuffers(1, &m_Id);
}

void FrameBuffer::UnBind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}