#pragma once


#include "fxcc/graph/pch.h"
#include "fxcc/graph/Type.h"
#include "fxcc/graph/Base.h"
#include "fxcc/graph/Dictionary.h"


namespace Ogl
{
	namespace Gut
	{

		struct MeshDesc1:public Base
		{

			struct HD :public Base
			{
				VertexType m_VertexType;
				IndexType m_IndexType;
				ModeType m_ModeType;

				int m_NumVertices;
				int m_NumIndices;
				HD()
					:m_VertexType(VertexType::_vertex_none_), m_IndexType(IndexType::_index_none_), m_ModeType(ModeType::_mode_none_), m_NumIndices(0), m_NumVertices(0)
				{

				}

				int VertexStride() const
				{

					auto vertexMeshDesc = Dictionary::GetVertiexDesc(m_VertexType);
					return vertexMeshDesc.m_VertexStride;
				}
				int IndexStride() const
				{
					auto indexMeshDesc = Dictionary::GetIndexDesc(m_IndexType);
					return indexMeshDesc.m_IndexStride;
				}

			} m_HD;

			void Release()
			{
				std::cout << "release mesh data" << std::endl;
				if (m_Vertices)
				{
					std::cout << "delete the vertices data" << std::endl;
					delete[]((char*)m_Vertices);
					m_Vertices = 0;
				}
				if (m_Indices)
				{
					std::cout << "delete the indices data" << std::endl;
					delete[]((char*)m_Indices);
					m_Indices = 0;
				}
			}

			void AllocData()
			{
				Release();
				int vertexStride = m_HD.VertexStride();
				int vsz = vertexStride * m_HD.m_NumVertices;
				m_Vertices = new char[vsz];

				int indexStide = m_HD.IndexStride();

				int isz = indexStide * m_HD.m_NumIndices;
				m_Indices = new char[isz];
			}

			void* m_Vertices = nullptr;
			void* m_Indices = nullptr;

			template<typename V>
			void Load(const std::vector<V>& vertices, const std::vector<unsigned int>& indices)
			{
				m_HD.m_VertexType = V::Type();
				m_HD.m_IndexType = IndexType::_index_unsigned_int_;
				m_HD.m_ModeType = ModeType::_mode_Triangles_;

				m_HD.m_NumIndices = indices.size();
				m_HD.m_NumVertices = vertices.size();
				m_Vertices = (void*)&vertices[0];
				m_Indices = (void*)&indices[0];
			};

			void Write(std::ofstream& ofs) const;
			void Write(std::string path) const;

			void Read(std::ifstream& ifs);
			void Read(std::string path);


		};

	}
}