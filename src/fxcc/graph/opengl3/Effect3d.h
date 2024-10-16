#pragma once

#include "fxcc/graph/Effect3d.h"
#include "fxcc/graph/opengl3/pch.h"

namespace fxcc
{
    namespace graph
    {
        template <>
        struct Effect3d<Opengl3Impl>
        {
            PipelineState m_PipeLineState;

            std::shared_ptr<Shader<Opengl3Impl>> m_Shader, m_AnimShader;

            void SetPassData(const PassData &passData) {

            };
            void Begin() {
            };

            void RenderMesh(const Mesh<Opengl3Impl> *mesh, const ObjData &objData) {}

            void RenderSkinnedMesh(const Mesh<Opengl3Impl> *mesh, const ObjData &objData) {};

            void End() {
            };
        };
    };
};