#include "fxcc/graph/MeshX.h"
#include "fxcc/graph/Shader.h"
#include "fxcc/graph/BoneNode.h"
#include "ogl/phong/Effect.h"

using namespace Ogl::Gut;

Ogl::Gut::MeshX::MeshX(aiMesh* mesh)
{
    m_AABB = AABB(mesh->mAABB);
    m_MaterialIndex = mesh->mMaterialIndex;
    Load(mesh->mName, m_Name);

    for (int boneId = 0; boneId < mesh->mNumBones; boneId++)
    {

        auto newBone = std::make_shared<Bone>(mesh->mBones[boneId]);
        newBone->m_Index = boneId;
        m_Bones[newBone->m_Name] = newBone;

    }

    // Load Mesh data

    m_Vertices.clear();
    m_VerticesSkinned.clear();
    m_Indices.clear();

    for (int i = 0; i < mesh->mNumFaces; i++)
    {
        auto &face = mesh->mFaces[i];
        for (int j = 0; j < face.mNumIndices; j++)
        {
            this->m_Indices.push_back(face.mIndices[j]);
        }
    }
    
    int numVertices = mesh->mNumVertices;

    // Load Fixed Data
    this->m_Vertices.resize(numVertices);
    for (int i = 0; i < numVertices;i++)
    {
        auto &vertex = m_Vertices[i];
        // vertex.pos = mesh->mVertices[i];
        Load(mesh->mVertices[i], vertex.pos);
        Load(mesh->mNormals[i], vertex.normal);

        aiVector3D tex = mesh->mTextureCoords[0][i];
        vertex.tex.x = tex.x;
        vertex.tex.y = tex.y;

        Load(mesh->mTangents[i], vertex.tangent);
        Load(mesh->mBitangents[i], vertex.bigTangent);

    }

    if(mesh->HasBones())
    {
        m_VerticesSkinned.resize(numVertices);
        for (int i = 0; i < numVertices;i++)
        {
            m_VerticesSkinned[i].Load(m_Vertices[i]);
        }

        for (auto it : m_Bones)
        {
            std::string name = it.first;
            auto bone = it.second;

            int boneIndex = bone->m_Index;

            for (const auto &weight : bone->m_Weights)
            {
                int vertexId = weight.m_VertexId;
                float weightValue = weight.m_Weight;
                m_VerticesSkinned[vertexId].AddBoneData(boneIndex, weightValue);
            }
        }
    }

    // Create Opengl Mesh
    Ogl::Gut::MeshDesc1 meshDesc1;
    meshDesc1.Load<Ogl::Gut::VertexFixed>(m_Vertices, m_Indices);
    Ogl::Gut::MeshDesc meshDesc(meshDesc1);

    auto& m_FixedMesh = m_Meshes[VertexType::_vertex_fixed_];
    m_FixedMesh = std::make_shared<Ogl::Gut::Mesh>(meshDesc);
   
    if (HasBones())
    {
        Ogl::Gut::MeshDesc1 animMeshDesc1;
        animMeshDesc1.Load<Ogl::Gut::VertexSkinned>(m_VerticesSkinned, m_Indices);
        Ogl::Gut::MeshDesc animMeshDesc(animMeshDesc1);

        auto& m_SkinnedMesh = m_Meshes[VertexType::_vertex_skinned_];
        m_SkinnedMesh = std::make_shared<Ogl::Gut::Mesh>(animMeshDesc);
    }
    
    // CreateRenderMeshX(MeshX);
}

void Ogl::Gut::MeshX::SetMeshIndex(const std::string& path, int index)
{
    for (int type = VertexType::_vertex_fixed_; type <= VertexType::_vertex_skinned_; type++)
    {
        auto& mesh = m_Meshes[type];
        if (mesh)
        {
            mesh->m_Desc.m_Desc5.m_Path = path;
            mesh->m_Desc.m_Desc5.m_Index = index;
            mesh->m_Desc.m_Desc5.m_Type = (VertexType)type;
            mesh->m_Desc.m_Type = MeshDescType::_mesh_model_file_;
        }

    }

}


//bool Ogl::Gut::MeshX::CreateRenderMeshX(aiMeshX* MeshX)
//{
//
//    Ogl::Math::SkinnedMeshXData m_SkinnedMeshXData;
//
//    Ogl::Math::MeshXData m_MeshXData;
//
//    if (mesh->mNumVertices > 0)
//    {
//        std::vector<unsigned int>& m_Indices = m_MeshXData.indices32;
//
//        for (int i = 0; i < mesh->mNumFaces; i++)
//        {
//            auto face = mesh->mFaces[i];
//            for (int j = 0; j < face.mNumIndices; j++)
//            {
//                m_Indices.push_back(face.mIndices[j]);
//            }
//        }
//
//        //m_mesh->RegisterIndexBuffer<unsigned int>(m_Indices);
//        m_MeshXData.ResizeVertices(mesh->mNumVertices);
//        memcpy(&m_MeshXData.vertices[0], mesh->mVertices, sizeof(glm::vec3) * mesh->mNumVertices);
//        memcpy(&m_MeshXData.normals[0], mesh->mNormals, sizeof(glm::vec3) * mesh->mNumVertices);
//       
//        for (int i = 0; i < mesh->mNumVertices; i++)
//        {
//            glm::vec2& texCoord = m_MeshXData.texcoords[i];
//            texCoord.x = mesh->mTextureCoords[0][i].x;
//            texCoord.y = mesh->mTextureCoords[0][i].y;
//        }
//        if (mesh->HasTangentsAndBitangents())
//        {
//            memcpy(&m_MeshXData.tangents[0], mesh->mTangents, sizeof(glm::vec3) * mesh->mNumVertices);
//            memcpy(&m_MeshXData.bigTangents[0], mesh->mBitangents, sizeof(glm::vec3) * mesh->mNumVertices);
//        }
//        m_MeshX = std::make_shared<Ogl::Gut::MeshX>(m_MeshXData);
//
//    }
//    if (HasBones())
//    {
//        std::cout << "has bones" << std::endl;
//
//        m_SkinnedMeshXData.Resize(mesh->mNumVertices);
//          
//        for (auto it : m_Bones)
//        {
//            std::string name = it.first;
//            auto bone = it.second;
//        
//            int boneIndex = bone->m_Index;
//
//            for (const auto& weight : bone->m_Weights)
//            {
//                int vertexId = weight.m_VertexId;
//                float weightValue = weight.m_Weight;
//                m_SkinnedMeshXData.AddBoneWeight(vertexId, boneIndex, weightValue);
//            }
//        }
//
//        m_mesh->Bind();
//        m_mesh->LoadSkinnedMeshXData(m_SkinnedMeshXData);
//
//    }
//
//    m_mesh->UnBind();
//
//    {
//        Ogl::Gut::Image desc(800, 600, 4, false, false);
//        //desc.m_NumTextures= 1;
//        m_MeshXRT = std::make_shared<Ogl::Gut::RenderTarget>(desc, 1);
//        m_SkinnedMeshXRT = std::make_shared<Ogl::Gut::RenderTarget>(desc, 1);
//    }
//
//    return true;
//}


//bool Ogl::Gut::MeshX::CreateSnapshot(const Ogl::Gut::Node* rootNode)
//{
//    std::shared_ptr<Ogl::Phong::Effect> effect = std::make_shared<Ogl::Phong::Effect>();
//    effect->m_RasterizerDesc.cullFace = false;
//
//    Ogl::Phong::LightEffect lightEffect;
//    lightEffect.numDirlights = 1;
//
//    Ogl::Phong::Material material;
//
//    int width = 800;
//    int height = 600;
//    float aspect = (float)width / (float)height;
//    Ogl::Math::Camera camera;
//    Ogl::Math::Transform transform;
//
//
//    float distanceAxis = 3.0f;
//
//    float halfExtendsLength = glm::length(m_AABB.m_HalfExtends);
//
//    camera.SetPosition(m_AABB.m_Center + halfExtendsLength  * distanceAxis* glm::vec3(0.f, 0.0f, 1.f));
//    camera.LookAt(m_AABB.m_Center);
//
//
//    m_MeshXRT->Begin();
//
//    glClearColor(.2f, 0.2f,0.2f, 0.2f);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    effect->Begin();
//    effect->SetCamera(camera);
//    effect->SetLightEffect(lightEffect);
//    effect->RenderMeshX(m_MeshX.get(), transform, material);
//    effect->End();
//
//    m_MeshXRT->End();
//
//    if (HasBones())
//    {
//        std::shared_ptr<Ogl::Gut::BoneNode> boneNode = std::make_shared<Ogl::Gut::BoneNode>(rootNode, this->m_Bones);
//        Ogl::Gut::Effect3d::BoneData boneData;
//
//        m_SkinnedMeshXRT->Begin();
//
//        glClearColor(.2f, 0.2f, 0.2f, 0.2f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        effect->Begin();
//        effect->SetCamera(camera);
//        effect->SetLightEffect(lightEffect);
//
//        boneNode->ProcessNode(glm::mat4(1.0f));
//        boneNode->UpdateBuffer(boneData);
//
//        effect->RenderSkinnedMeshX(m_MeshX.get(), transform, boneData, material);
//        effect->End();
//
//        m_SkinnedMeshXRT->End();
//
//    }
//
//
//    return true;
//}

bool Ogl::Gut::MeshX::HasBones() const
{
    return this->m_Bones.size() > 0;
}
