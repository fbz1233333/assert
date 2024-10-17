#pragma once

#include "fxcc/graph/Type.h"
#include "fxcc/graph/Dictionary.h"
#include "fxcc/graph/Base.h"

namespace Ogl
{
	namespace Gut
	{

		struct MeshDesc2 :public Base
		{
			struct HD:public Base
			{

				VertexType m_VertexType;
				IndexType m_IndexType;;
				ModeType m_ModeType;

				int m_NumIndices8;
				int m_NumIndices16;
				int m_NumIndices32;

				int m_NumVerticesFixed;
				int m_NumVerticesSkinned;
				int m_NumVerticesFont;

				HD()
					:m_VertexType(_vertex_none_), m_IndexType(_index_none_), m_ModeType(_mode_none_),
					m_NumIndices8(0), m_NumIndices16(0), m_NumIndices32(0), m_NumVerticesFixed(0), m_NumVerticesFont(0), m_NumVerticesSkinned(0)
				{

				}
			} m_HD;

			void Calculate()
			{
				m_HD.m_NumIndices8 = m_Indices8.size();
				m_HD.m_NumIndices16 = m_Indices16.size();
				m_HD.m_NumIndices32 = m_Indices32.size();

				m_HD.m_NumVerticesFixed = m_VerticesFixed.size();
				m_HD.m_NumVerticesSkinned = m_VerticesSkinneds.size();
				m_HD.m_NumVerticesFont = m_VerticesFont.size();
			};
			void Resize()
			{
				m_Indices8.resize(m_HD.m_NumIndices8);
				m_Indices16.resize(m_HD.m_NumIndices16);
				m_Indices32.resize(m_HD.m_NumIndices32);

				m_VerticesFixed.resize(m_HD.m_NumVerticesFixed);
				m_VerticesSkinneds.resize(m_HD.m_NumVerticesSkinned);
				m_VerticesFont.resize(m_HD.m_NumVerticesFont);
			};
			std::vector<unsigned int> m_Indices32;
			std::vector<unsigned short> m_Indices16;
			std::vector<unsigned char> m_Indices8;

			std::vector<VertexFixed> m_VerticesFixed;
			std::vector<VertexSkinned> m_VerticesSkinneds;
			std::vector<VertexFont> m_VerticesFont;

			void Write(std::string path);
			void Write(std::ofstream& ofs);
			void Read(std::string path);
			void Read(std::ifstream& ifs);
		};

	}
}