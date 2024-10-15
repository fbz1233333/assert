#pragma once

#include "fxcc/graph/Factory.h"

namespace fxcc
{
    namespace graph
    {
        namespace opengl3
        {
            struct Factory : public fxcc::graph::Factory
            {

                std::shared_ptr<Mesh> CreateMesh(const Mesh::Desc &desc) override
                {
                    return 0;
                }

                std::shared_ptr<Scene> CreateScene(const std::string &path) override
                {
                    return 0;
                }
            };
        }
    };
};
