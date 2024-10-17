#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/MeshX.h"
#include "fxcc/graph/Material.h"
#include "fxcc/graph/Animation.h"
#include "fxcc/graph/Node.h"
#include "fxcc/graph/Camera.h"
#include "fxcc/graph/Light.h"
#include "fxcc/graph/Node.h"

namespace Ogl
{
    namespace Gut
    {
        struct Scene
        {

            struct Desc
            {
                std::string m_Path;
                Desc(const std::string& p):m_Path(p)
                {

                }
                static unsigned int g_AssimpFlag;
            } m_Desc;

            std::string m_Name;
            std::string m_Path;
            std::string m_Dir;

            Ogl::Gut::AABB m_AABB;

            bool m_Avail;

            bool Avail()
            {
                return m_Avail;
            }

            std::shared_ptr<Node> m_RootNode;
            std::vector<std::shared_ptr<Ogl::Gut::MeshX>> m_Meshes;
            std::vector<std::shared_ptr<Ogl::Gut::Animation>> m_Animations;
            std::vector<std::shared_ptr<Ogl::Gut::Material>> m_Materials;
            std::vector<std::shared_ptr<Ogl::Gut::Camera>> m_Cameras;
            std::vector<std::shared_ptr<Ogl::Gut::Light>> m_Lights;

            Scene() = default;

            Scene(const Desc& desc);

            bool Init();

            bool Create(const aiScene* SceneX);

            void CalAABB(const Ogl::Gut::AABB& other);
        };
    };
};
