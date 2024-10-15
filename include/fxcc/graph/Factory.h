#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/Mesh.h"
#include "fxcc/graph/Scene.h"
#include "fxcc/graph/Texture2D.h"
#include "fxcc/graph/TextureCube.h"
#include "fxcc/graph/Texture2DArray.h"
#include "fxcc/graph/Effect2d.h"

namespace fxcc
{
    namespace graph
    {
        struct Factory
        {
            virtual std::shared_ptr<Mesh> CreateMesh(const Mesh::Desc& desc);

            virtual std::shared_ptr<Scene> CreateScene(const std::string &path);
        };
    };
};