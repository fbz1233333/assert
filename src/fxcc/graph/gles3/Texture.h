#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/Sampler.h"
#include "fxcc/graph/Image.h"
#include "fxcc/graph/Base.h"

namespace Ogl
{

	namespace Gut
	{

		struct Texture3DDesc
		{
			unsigned int target = GL_TEXTURE_3D;
			int level = 0;
			int internalformat = GL_RGBA;
			int width;
			int height;
			int depth;
			unsigned int format = GL_RGBA;
			unsigned int type = GL_UNSIGNED_BYTE;
			void* pixels = 0;
		};


		struct Texture :public Base
		{
			unsigned int m_Id;
			unsigned int m_Target;

			Texture(const unsigned int target) :
				m_Target(target)
			{

				Create();
				Bind();
			}
	
			void TexImage2D(int target, int level,  const Ogl::Gut::Image& image) const;

			void Mipmap() const;

			void Create();
			
			void Delete();

			void Active(unsigned int index) const
			{
				ActiveIndex(index);
				Bind();
			}

			static void ActiveIndex(int index)
			{
				glActiveTexture(GL_TEXTURE0 + index);

			}
			void Bind() const;

			unsigned int GetTarget() const;
	
			virtual ~Texture()
			{
				Delete();
			};

		};

	};
};