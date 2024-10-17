#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/Base.h"

namespace Ogl
{

	namespace Gut
	{
		struct SamplerDesc :public Base
		{

			unsigned int minFilter;
			unsigned int magFilter;
			unsigned int wrapS;
			unsigned int wrapT;
			unsigned int wrapR;
			// float lodBias;
			unsigned int minLod;
			unsigned int maxLod;
			unsigned int baseLevel;
			unsigned int maxLevel;
			unsigned int compareMode;
			unsigned int compareFunc;
			unsigned int swizzleR;
			unsigned int swizzleG;
			unsigned int swizzleB;
			unsigned int swizzleA;

			bool useBorderColor;
			float borderColor[4];

			SamplerDesc();
			void BindTexture(int target) const;
		};

		struct Sampler
		{
			unsigned int ID;

			bool CreateFromDesc(const SamplerDesc &desc);
			void Bind(unsigned int tex);
		};
	};
};