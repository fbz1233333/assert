#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/Texture.h"

namespace Ogl
{

	namespace Gut
	{

		struct FrameBuffer
		{
			FrameBuffer();

			static bool CheckError();
			
			unsigned int m_Id;

			void BufferTextureLayer(unsigned int attachment, unsigned int texId, int level, int layer);

			void BufferTexture2D(unsigned int attachment, unsigned int texTarget, unsigned int ID, unsigned int mipLevel = 0);

			void BufferTextureLayer(unsigned int attachment, unsigned int tex, unsigned int mipLevel, unsigned int zOff);

			void FrameRenderBuffer(unsigned int attachment, unsigned int RBO);

			void ReadBuffer(unsigned int attachment);

			void DrawBuffer(unsigned int attachment);

			void DrawBuffers(unsigned int *attachments, int num);

			void Create();

			void Bind();

			void BufferTexture(unsigned int attachment, unsigned int texId, int level);

			void BufferTexture3D(unsigned int attachment, unsigned int texTarget, unsigned int tex, unsigned int mipLevel, unsigned int zOff);

			~FrameBuffer();

			static void UnBind();
		};

	};
};