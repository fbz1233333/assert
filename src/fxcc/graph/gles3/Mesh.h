#pragma once
#include "fxcc/graph/MeshOffset.h"
#include "fxcc/graph/VertexArray.h"
#include "fxcc/graph/IndexBuffer.h"
#include "fxcc/graph/VertexBuffer.h"
#include "fxcc/graph/InputLayout.h"
#include "fxcc/graph/Vertex.h"
#include "fxcc/graph/Dictionary.h"
#include "fxcc/graph/MeshDesc.h"

#include "ogl/math/GeometryData.h"

namespace Ogl
{
	namespace Gut
	{

		struct Mesh : Ogl::Gut::VertexArray
		{

			IndexBuffer m_IndexBuffer;
			VertexBuffer m_VertexBuffer;

			MeshDesc m_Desc;

			int m_Mode;
			int m_IndexType;
			int m_NumIndices;

			void Init();

			void Init1()
			{
				auto desc = m_Desc.m_Desc1;
				auto vertexDesc = Dictionary::GetVertiexDesc(desc.m_HD.m_VertexType);
				auto indexDesc = Dictionary::GetIndexDesc(desc.m_HD.m_IndexType);
				auto modeDesc = Dictionary::GetModeTypeDesc(desc.m_HD.m_ModeType);

				int indexStride = indexDesc.m_IndexStride;
				int vertexStride = vertexDesc.m_VertexStride;

				Bind();
				m_IndexBuffer.Bind();
				m_IndexBuffer.BufferData(indexStride * desc.m_HD.m_NumIndices, desc.m_Indices);

				m_VertexBuffer.Bind();
				m_VertexBuffer.BufferData(vertexStride * desc.m_HD.m_NumVertices, desc.m_Vertices);

				vertexDesc.m_InputLayout.Use();
				UnBind();

				// Bind
				m_Mode = modeDesc.m_Target;
				m_IndexType = indexDesc.m_Target;
				m_NumIndices = desc.m_HD.m_NumIndices;
			}
			void Init2()
			{
				m_Desc.Translate2To1();
				Init1();
			}
			void Init3()
			{
				m_Desc.Parse3To1();
				Init1();
			}
			void Init4()
			{
				m_Desc.Parse4To2();
				Init2();
			}

			//void Init5();
			Mesh() = default;

			Mesh(const GeometryData &geoData)
				: VertexArray()
			{
				m_Desc = MeshDesc(geoData);
				Init();
			}
			Mesh(const MeshDesc1 &desc1)
				: VertexArray()
			{
				m_Desc = MeshDesc(desc1);
				Init();
			};

			Mesh(const MeshDesc2 &desc2)
				: VertexArray()
			{
				m_Desc = MeshDesc(desc2);
				Init();
			}
			Mesh(const MeshDesc3 &desc3)
				: VertexArray()
			{
				m_Desc = MeshDesc(desc3);
				Init();
			}

			Mesh(const MeshDesc4 &d4) : VertexArray()
			{
				m_Desc = MeshDesc(d4);
				Init();
			}

			Mesh(const MeshDesc &desc)
				: m_Desc(desc), VertexArray()
			{
				Init();
			}
			void DrawElementsAuto() const;

			void DrawElemenstOffset(const MeshOffset &offset) const
			{
				VertexArray::DrawElements(m_Mode, offset.numIndices, m_IndexType, reinterpret_cast<void *>(offset.indexOffset));
			}
		};
	};
};