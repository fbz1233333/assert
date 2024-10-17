#include "fxcc/graph/Scene.h"

using namespace Ogl::Gut;

unsigned int Ogl::Gut::Scene::Desc::g_AssimpFlag =
aiProcess_GenSmoothNormals |
aiProcess_FlipUVs |
aiProcess_CalcTangentSpace |
aiProcess_GenBoundingBoxes |
aiProcess_Triangulate |
aiProcess_ImproveCacheLocality |
aiProcess_SortByPType
// | aiProcess_PopulateArmatureData 
;

Scene::Scene(const Desc& desc)
    : m_Desc(desc), m_Avail(false),m_Path(desc.m_Path)
{

    Init();
};

bool Ogl::Gut::Scene::Init()
{
    m_Name = (fs::path(m_Desc.m_Path).filename().string());

    fs::path _p(m_Desc.m_Path);
    if (_p.has_parent_path())
    {
        m_Dir = _p.parent_path().string();
    }

    static Assimp::Importer importer;

    importer.SetPropertyInteger(AI_CONFIG_PP_SBP_REMOVE, aiPrimitiveType_LINE | aiPrimitiveType_POINT);

    const aiScene* scene = importer.ReadFile(
        m_Desc.m_Path,
        Ogl::Gut::Scene::Desc::g_AssimpFlag
    );

    if (scene == nullptr)
    {
        std::cout << "cannot load model from path " << m_Desc.m_Path << std::endl;
        return false;
    }
    if (scene->mRootNode == nullptr)
    {
        std::cout << "Cannot load root Node " << m_Desc.m_Path << std::endl;
        return false;
    }

    bool res = Create(scene);

    importer.FreeScene();

    return res;
}

bool Ogl::Gut::Scene::Create(const aiScene* scene)
{

    m_RootNode = std::make_shared<Node>(scene->mRootNode);

    for (int i = 0; i < scene->mNumMeshes; i++)
    {

        auto newMesh = std::make_shared<MeshX>(scene->mMeshes[i]);
        //std::cout << "get char load mesh " << newMesh->m_Name << std::endl;

        //newMesh->CreateSnapshot(this->m_RootNode.get());
        CalAABB(newMesh->m_AABB);

        newMesh->SetMeshIndex(m_Path, i);

        m_Meshes.push_back(newMesh);
    };

    //if (!CreateSnapshot())
    //{
    //    std::cout << "Failed create Scene snap Shot" << std::endl;
    //}

    for (int i = 0; i < scene->mNumAnimations; i++)
    {
        auto inst = std::make_shared<Ogl::Gut::Animation>(scene->mAnimations[i]);
        inst->SetIndex(m_Path, i);
        m_Animations.push_back(inst);
    }

    for (int i = 0; i < scene->mNumCameras; i++)
    {
        m_Cameras.push_back(std::make_shared<Ogl::Gut::Camera>(scene->mCameras[i]));
    }

    for (int i = 0; i < scene->mNumLights; i++)
    {
        m_Lights.push_back(std::make_shared<Ogl::Gut::Light>(scene->mLights[i]));
    }

    for (int i = 0; i < scene->mNumMaterials; i++)
    {
        m_Materials.push_back(std::make_shared<Ogl::Gut::Material>(scene->mMaterials[i], m_Dir));
    }

    m_Avail = true;

    return true;
}

//bool Ogl::Gut::Scene::CreateSnapshot()
//{
//    Ref<Ogl::Phong::Effect> effect = std::make_shared<Ogl::Phong::Effect>();
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
//    camera.SetPosition(m_AABB.m_Center + halfExtendsLength * distanceAxis * glm::vec3(0.f, 0.0f, 1.f));
//    camera.LookAt(m_AABB.m_Center);
//
//
//
//    m_MeshesRenderTarget->Begin();
//
//    glClearColor(.2f, 0.2f, 0.2f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    effect->Begin();
//    effect->SetCamera(camera);
//    effect->SetLightEffect(lightEffect);
//
//    for (const auto& mesh : m_Meshes)
//    {
//        effect->RenderMesh(mesh->m_Mesh.get(), transform, material);
//
//    }
//    effect->End();
//
//    m_MeshesRenderTarget->End();
//
//    return true;
//}

void Ogl::Gut::Scene::CalAABB(const Ogl::Gut::AABB& other)
{
    auto& SceneMin = this->m_AABB.m_Min;
    auto& SceneMax = this->m_AABB.m_Max;

    const auto& meshMin = other.m_Min;
    const auto& meshMax = other.m_Max;

    SceneMin.x = std::min(SceneMin.x, meshMin.x);
    SceneMin.y = std::min(SceneMin.y, meshMin.y);
    SceneMin.z = std::min(SceneMin.z, meshMin.z);

    SceneMax.x = std::max(SceneMax.x, meshMax.x);
    SceneMax.y = std::max(SceneMax.y, meshMax.y);
    SceneMax.z = std::max(SceneMax.z, meshMax.z);

    m_AABB.CalCenterHalfExt();
}
