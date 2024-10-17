#include "fxcc/graph/Mesh.h"
#include "fxcc/graph/AssertManager.h"


void Ogl::Gut::Mesh::Init()
{
	switch (m_Desc.m_Type)
	{

	case MeshDescType::_mesh_origin_data_:
		Init1();
		break;
	case MeshDescType::_mesh_mesh_data_:
		Init2();
		break;
	case MeshDescType::_mesh_origin_file_:
		Init3();
		break;
	case MeshDescType::_mesh_mesh_data_file_:
		Init4();
		break;
	case MeshDescType::_mesh_model_file_:
		//Init5();
		std::cout << "should create by the assert manager" << std::endl;
		break;

	default:
		std::cout << "failed create mesh" << std::endl;
		break;
	}
}

void Ogl::Gut::Mesh::DrawElementsAuto() const
{
	VertexArray::DrawElements(m_Mode, m_NumIndices, m_IndexType, 0);
}

//void Ogl::Gut::Mesh::Init5()
//{
//	auto assertManager = AssertManager::Inst();
//	auto desc = m_Desc.m_Desc5;
//	if (assertManager->TryLoadScene(desc.m_Path))
//	{
//		auto scene = assertManager->GetScene(desc.m_Path);
//		auto meshSource = scene->m_Meshes[desc.m_Index];
//
//		if (assertManager->HasMesh(desc.m_Path, desc.m_Index))
//		{
//			*this = *scene->m_Meshes[desc.m_Index]->m_Meshes[desc.m_Type];
//
//		}
//	}
//}
