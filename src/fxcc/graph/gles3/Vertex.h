#pragma once
#include "fxcc/graph/pch.h"
#include "ogl/math/GeometryData.h"
#include "fxcc/graph/InputLayout.h"

#include "fxcc/graph/Type.h"

namespace Ogl
{
	namespace Gut
	{

		struct VertexFixed {

			glm::vec3 pos;
			glm::vec3 normal;
			glm::vec2 tex;
			glm::vec3 tangent;
			glm::vec3 bigTangent;


			void Load(const GeometryData& geoData, int index)
			{
				pos = geoData.vertices[index];
				normal = geoData.normals[index];
				tex = geoData.texcoords[index];
				tangent = geoData.tangents[index];
				bigTangent = geoData.bigTangents[index];

			};
			static VertexType Type()
			{
				return VertexType::_vertex_fixed_;
			}

			static Ogl::Gut::InputLayout Layouts();

		};

		struct VertexSkinned {
			glm::vec3 pos;
			glm::vec3 normal;
			glm::vec2 tex;
			glm::vec3 tangent;
			glm::vec3 bigTangent;
			glm::ivec4 bones1;
			glm::vec4 weights1;
			glm::ivec4 bones2;
			glm::vec4 weights2;

			void Load(const Ogl::Gut::VertexFixed& source)
			{
				pos = source.pos;
				tex = source.tex;
				normal = source.normal;
				tangent = source.tangent;
				bigTangent = source.bigTangent;

			}
			bool AddBoneData(const int boneId, const int weightValue);

			static VertexType Type()
			{
				return VertexType::_vertex_skinned_;
			}
			static Ogl::Gut::InputLayout Layouts();

		};

		struct VertexFont {
			glm::vec3 pos;
			glm::vec2 tex;
			static VertexType Type()
			{
				return VertexType::_vertex_font_;
			}
			static Ogl::Gut::InputLayout Layouts();
		};
	};
}