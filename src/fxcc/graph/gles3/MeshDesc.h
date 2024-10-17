#pragma once


#include "fxcc/graph/pch.h"
#include "fxcc/graph/MeshDesc1.h"
#include "fxcc/graph/MeshDesc2.h"
#include "fxcc/graph/MeshDesc3.h"
#include "fxcc/graph/MeshDesc4.h"
#include "fxcc/graph/MeshDesc5.h"
#include "fxcc/graph/Vertex.h"


namespace Ogl
{
	namespace Gut
	{


		struct MeshDesc :public  Ogl::Gut::Base
		{


			MeshDesc1 m_Desc1;
			MeshDesc2 m_Desc2;
			MeshDesc3 m_Desc3;
			MeshDesc4 m_Desc4;
			MeshDesc5 m_Desc5;

			MeshDescType m_Type;

			// imgui flag

			void Translate2To1();
			void Parse3To1();
			void Parse4To2();

			MeshDesc() = default;

			MeshDesc(const MeshDesc1& d1)
				: m_Desc1(d1), m_Type(MeshDescType::_mesh_origin_data_) {

			};

			MeshDesc(const MeshDesc2& d2)
				: m_Desc2(d2), m_Type(MeshDescType::_mesh_mesh_data_) {

			};
			MeshDesc(const MeshDesc3& d3)
				: m_Desc3(d3), m_Type(MeshDescType::_mesh_origin_file_) {
			};

			MeshDesc(const MeshDesc4& d4)
				: m_Desc4(d4), m_Type(MeshDescType::_mesh_mesh_data_file_)
			{
			}
			MeshDesc(const MeshDesc5& d5)
				:m_Desc5(d5), m_Type(MeshDescType::_mesh_model_file_)
			{

			}

			MeshDesc(const GeometryData& geoData);
		};
	};
};