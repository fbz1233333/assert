#pragma once
#include "fxcc/graph/pch.h"
#include "fxcc/graph/Mesh.h"
#include "fxcc/graph/AABB.h"
#include "fxcc/graph/Bone.h"
#include "fxcc/graph/Vertex.h"


namespace Ogl
{
	namespace Gut
	{

		struct MeshX {

			std::string m_Name;

			int m_MaterialIndex = -1;
			
			Ogl::Gut::AABB m_AABB;
			
			std::unordered_map<std::string, std::shared_ptr<Ogl::Gut::Bone>> m_Bones;

			// Mesh data
			std::vector<Ogl::Gut::VertexFixed> m_Vertices;

			std::vector<Ogl::Gut::VertexSkinned> m_VerticesSkinned;

			std::vector<unsigned int> m_Indices;

			std::shared_ptr<Ogl::Gut::Mesh> m_Meshes[VertexType::_vertex_end_];

			MeshX(aiMesh* mesh);

			void SetMeshIndex(const std::string& path, int index);

			bool HasBones() const;
		};
	};
};