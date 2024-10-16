
#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/GeometryData.h"

namespace fxcc
{

    namespace graph
    {
        // 创建球体网格数据，levels和slices越大，精度越高。
        GeometryData CreateSphere(float radius = 1.0f, uint32_t levels = 20, uint32_t slices = 20);

        // 创建立方体网格数据
        GeometryData CreateBox(float width = 2.0f, float height = 2.0f, float depth = 2.0f);

        // 创建圆柱体网格数据，slices越大，精度越高。
        GeometryData CreateCylinder(float radius = 1.0f, float height = 2.0f, uint32_t slices = 20, uint32_t stacks = 10, float texU = 1.0f, float texV = 1.0f);

        // 创建圆锥体网格数据，slices越大，精度越高。
        GeometryData CreateCone(float radius = 1.0f, float height = 2.0f, uint32_t slices = 20);

        // 创建一个平面
        GeometryData CreatePlane(const glm::vec2 &planeSize, const glm::vec2 &maxTexCoord = {1.0f, 1.0f});
        GeometryData CreatePlane(float width = 10.0f, float depth = 10.0f, float texU = 1.0f, float texV = 1.0f);

        // 创建一个网格
        GeometryData CreateGrid(const glm::vec2 &gridSize, const glm::ivec2 &slices, const glm::vec2 &maxTexCoord, const std::function<float(float, float)> &heightFunc = [](float x, float z)
                                                                                                                   { return 0.0f; },
                                const std::function<glm::vec3(float, float)> &normalFunc = [](float x, float z)
                                { return glm::vec3(0.0f, 1.0f, 0.0f); },
                                const std::function<glm::vec4(float, float)> &colorFunc = [](float x, float z)
                                { return glm::vec4(1.0f, 1.0f, 1.0f, 1.0f); });
        // Create quad
        GeometryData CreateQuad();
        GeometryData Create2DTexture();
    }

}
