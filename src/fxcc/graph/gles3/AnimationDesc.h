#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/Type.h"
#include "fxcc/graph/AnimationDesc1.h"
#include "fxcc/graph/Base.h"

namespace Ogl
{
	namespace Gut
	{

		struct AnimationDesc :public Base{
		
			AnimationDesc1 m_Desc1;
			AnimationDescType m_Type;
			
			AnimationDesc() 
				:m_Type(AnimationDescType::_None_)
			{

			}

			AnimationDesc(const AnimationDesc1& d1) 
				: m_Desc1(d1), m_Type(AnimationDescType::_Animation_Model_File_) 
			{
			};

		};
	};
};