#include "fxcc/graph/Geometry.h"

namespace fxcc
{

    namespace graph
    {
        constexpr float PI = 3.1415926f;

        GeometryData CreateSphere(float radius, uint32_t levels, uint32_t slices)
        {

            GeometryData geoData;

            uint32_t vertexCount = 2 + (levels - 1) * (slices + 1);
            uint32_t indexCount = 6 * (levels - 1) * slices;
            geoData.ResizeVertices(vertexCount);
            geoData.indices32.resize(indexCount);

            uint32_t vIndex = 0, iIndex = 0;

            float phi = 0.0f, theta = 0.0f;
            float per_phi = PI / levels;
            float per_theta = 2 * PI / slices;
            float x, y, z;

            // 放入顶端点
            geoData.vertices[vIndex] = glm::vec3(0.0f, radius, 0.0f);
            geoData.normals[vIndex] = glm::vec3(0.0f, 1.0f, 0.0f);
            geoData.tangents[vIndex] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
            geoData.texcoords[vIndex++] = glm::vec2(0.0f, 0.0f);

            for (uint32_t i = 1; i < levels; ++i)
            {
                phi = per_phi * i;
                // 需要slices + 1个顶点是因为 起点和终点需为同一点，但纹理坐标值不一致
                for (uint32_t j = 0; j <= slices; ++j)
                {
                    theta = per_theta * j;
                    x = radius * sinf(phi) * cosf(theta);
                    y = radius * cosf(phi);
                    z = radius * sinf(phi) * sinf(theta);
                    // 计算出局部坐标、法向量、Tangent向量和纹理坐标
                    glm::vec3 pos = glm::vec3(x, y, z);

                    geoData.vertices[vIndex] = pos;
                    geoData.normals[vIndex] = glm::normalize(pos);
                    geoData.tangents[vIndex] = glm::vec3(-sinf(theta), 0.0f, cosf(theta));
                    geoData.texcoords[vIndex] = glm::vec2(theta / 2 / PI, phi / PI);

                    vIndex++;
                }
            }

            // 放入底端点
            geoData.vertices[vIndex] = glm::vec3(0.0f, -radius, 0.0f);
            geoData.normals[vIndex] = glm::vec3(0.0f, -1.0f, 0.0f);
            geoData.texcoords[vIndex] = glm::vec2(0.0f, 1.0f);
            geoData.tangents[vIndex] = glm::vec3(-1.0f, 0.0f, 0.0f);

            vIndex++;

            // 放入索引
            if (levels > 1)
            {
                for (uint32_t j = 1; j <= slices; ++j)
                {
                    geoData.indices32[iIndex++] = 0;
                    geoData.indices32[iIndex++] = j % (slices + 1) + 1;
                    geoData.indices32[iIndex++] = j;
                }
            }

            for (uint32_t i = 1; i < levels - 1; ++i)
            {
                for (uint32_t j = 1; j <= slices; ++j)
                {

                    geoData.indices32[iIndex++] = (i - 1) * (slices + 1) + j;
                    geoData.indices32[iIndex++] = (i - 1) * (slices + 1) + j % (slices + 1) + 1;
                    geoData.indices32[iIndex++] = i * (slices + 1) + j % (slices + 1) + 1;

                    geoData.indices32[iIndex++] = i * (slices + 1) + j % (slices + 1) + 1;
                    geoData.indices32[iIndex++] = i * (slices + 1) + j;
                    geoData.indices32[iIndex++] = (i - 1) * (slices + 1) + j;
                }
            }

            // 逐渐放入索引
            if (levels > 1)
            {
                for (uint32_t j = 1; j <= slices; ++j)
                {
                    geoData.indices32[iIndex++] = (levels - 2) * (slices + 1) + j;
                    geoData.indices32[iIndex++] = (levels - 2) * (slices + 1) + j % (slices + 1) + 1;
                    geoData.indices32[iIndex++] = (levels - 1) * (slices + 1) + 1;
                }
            }

            return geoData;
        }

        GeometryData CreateBox(float width, float height, float depth)
        {

            GeometryData geoData;
            geoData.ResizeVertices(24);

            float w2 = width / 2, h2 = height / 2, d2 = depth / 2;

            // 右面(+X面)
            geoData.vertices[0] = glm::vec3(w2, -h2, -d2);
            geoData.vertices[1] = glm::vec3(w2, h2, -d2);
            geoData.vertices[2] = glm::vec3(w2, h2, d2);
            geoData.vertices[3] = glm::vec3(w2, -h2, d2);
            // 左面(-X面)
            geoData.vertices[4] = glm::vec3(-w2, -h2, d2);
            geoData.vertices[5] = glm::vec3(-w2, h2, d2);
            geoData.vertices[6] = glm::vec3(-w2, h2, -d2);
            geoData.vertices[7] = glm::vec3(-w2, -h2, -d2);
            // 顶面(+Y面)
            geoData.vertices[8] = glm::vec3(-w2, h2, -d2);
            geoData.vertices[9] = glm::vec3(-w2, h2, d2);
            geoData.vertices[10] = glm::vec3(w2, h2, d2);
            geoData.vertices[11] = glm::vec3(w2, h2, -d2);
            // 底面(-Y面)
            geoData.vertices[12] = glm::vec3(w2, -h2, -d2);
            geoData.vertices[13] = glm::vec3(w2, -h2, d2);
            geoData.vertices[14] = glm::vec3(-w2, -h2, d2);
            geoData.vertices[15] = glm::vec3(-w2, -h2, -d2);
            // 背面(+Z面)
            geoData.vertices[16] = glm::vec3(w2, -h2, d2);
            geoData.vertices[17] = glm::vec3(w2, h2, d2);
            geoData.vertices[18] = glm::vec3(-w2, h2, d2);
            geoData.vertices[19] = glm::vec3(-w2, -h2, d2);
            // 正面(-Z面)
            geoData.vertices[20] = glm::vec3(-w2, -h2, -d2);
            geoData.vertices[21] = glm::vec3(-w2, h2, -d2);
            geoData.vertices[22] = glm::vec3(w2, h2, -d2);
            geoData.vertices[23] = glm::vec3(w2, -h2, -d2);

            for (size_t i = 0; i < 4; ++i)
            {
                // 右面(+X面)
                geoData.normals[i] = glm::vec3(1.0f, 0.0f, 0.0f);
                geoData.tangents[i] = glm::vec3(0.0f, 0.0f, 1.0f);
                // 左面(-X面)
                geoData.normals[i + 4] = glm::vec3(-1.0f, 0.0f, 0.0f);
                geoData.tangents[i + 4] = glm::vec3(0.0f, 0.0f, -1.0f);
                // 顶面(+Y面)
                geoData.normals[i + 8] = glm::vec3(0.0f, 1.0f, 0.0f);
                geoData.tangents[i + 8] = glm::vec3(1.0f, 0.0f, 0.0f);
                // 底面(-Y面)
                geoData.normals[i + 12] = glm::vec3(0.0f, -1.0f, 0.0f);
                geoData.tangents[i + 12] = glm::vec3(-1.0f, 0.0f, 0.0f);
                // 背面(+Z面)
                geoData.normals[i + 16] = glm::vec3(0.0f, 0.0f, 1.0f);
                geoData.tangents[i + 16] = glm::vec3(-1.0f, 0.0f, 0.0f);
                // 正面(-Z面)
                geoData.normals[i + 20] = glm::vec3(0.0f, 0.0f, -1.0f);
                geoData.tangents[i + 20] = glm::vec3(1.0f, 0.0f, 0.0f);
            }

            for (size_t i = 0; i < 6; ++i)
            {
                geoData.texcoords[i * 4] = glm::vec2(0.0f, 1.0f);
                geoData.texcoords[i * 4 + 1] = glm::vec2(0.0f, 0.0f);
                geoData.texcoords[i * 4 + 2] = glm::vec2(1.0f, 0.0f);
                geoData.texcoords[i * 4 + 3] = glm::vec2(1.0f, 1.0f);
            }

            geoData.indices32 = {
                0, 1, 2, 2, 3, 0,       // 右面(+X面)
                4, 5, 6, 6, 7, 4,       // 左面(-X面)
                8, 9, 10, 10, 11, 8,    // 顶面(+Y面)
                12, 13, 14, 14, 15, 12, // 底面(-Y面)
                16, 17, 18, 18, 19, 16, // 背面(+Z面)
                20, 21, 22, 22, 23, 20  // 正面(-Z面)
            };

            for (int i = 0; i < geoData.vertices.size(); i++)
            {
                geoData.bigTangents[i] = glm::cross(geoData.normals[i], geoData.tangents[i]);
            }

            return geoData;
        }

        GeometryData CreateCylinder(float radius, float height, uint32_t slices, uint32_t stacks, float texU, float texV)
        {

            GeometryData geoData;
            uint32_t vertexCount = (slices + 1) * (stacks + 3) + 2;
            uint32_t indexCount = 6 * slices * (stacks + 1);

            geoData.ResizeVertices(vertexCount);

            geoData.indices32.resize(indexCount);

            float h2 = height / 2;
            float theta = 0.0f;
            float per_theta = 2 * PI / slices;
            float stackHeight = height / stacks;
            //
            // 侧面部分
            //
            {
                // 自底向上铺设侧面端点
                size_t vIndex = 0;
                for (size_t i = 0; i < stacks + 1; ++i)
                {
                    float y = -h2 + i * stackHeight;
                    // 当前层顶点
                    for (size_t j = 0; j <= slices; ++j)
                    {
                        theta = j * per_theta;
                        float u = theta / 2 / PI;
                        float v = 1.0f - (float)i / stacks;

                        geoData.vertices[vIndex] = glm::vec3(radius * cosf(theta), y, radius * sinf(theta)), glm::vec3(cosf(theta), 0.0f, sinf(theta));
                        geoData.normals[vIndex] = glm::vec3(cosf(theta), 0.0f, sinf(theta));
                        geoData.tangents[vIndex] = glm::vec3(-sinf(theta), 0.0f, cosf(theta));
                        geoData.texcoords[vIndex] = glm::vec2(u * texU, v * texV);

                        vIndex++;
                    }
                }

                // 放入索引
                size_t iIndex = 0;
                for (uint32_t i = 0; i < stacks; ++i)
                {
                    for (uint32_t j = 0; j < slices; ++j)
                    {
                        geoData.indices32[iIndex++] = i * (slices + 1) + j;
                        geoData.indices32[iIndex++] = (i + 1) * (slices + 1) + j;
                        geoData.indices32[iIndex++] = (i + 1) * (slices + 1) + j + 1;

                        geoData.indices32[iIndex++] = i * (slices + 1) + j;
                        geoData.indices32[iIndex++] = (i + 1) * (slices + 1) + j + 1;
                        geoData.indices32[iIndex++] = i * (slices + 1) + j + 1;
                    }
                }
            }

            //
            // 顶盖底盖部分
            //
            {
                size_t vIndex = (slices + 1) * (stacks + 1), iIndex = 6 * slices * stacks;
                uint32_t offset = static_cast<uint32_t>(vIndex);

                // 放入顶端圆心
                geoData.vertices[vIndex] = glm::vec3(0.0f, h2, 0.0f);
                geoData.normals[vIndex] = glm::vec3(0.0f, 1.0f, 0.0f);
                geoData.tangents[vIndex] = glm::vec3(1.0f, 0.0f, 0.0f);
                geoData.texcoords[vIndex] = glm::vec2(0.5f, 0.5f);

                vIndex++;
                // 放入顶端圆上各点
                for (uint32_t i = 0; i <= slices; ++i)
                {
                    theta = i * per_theta;
                    float u = cosf(theta) * radius / height + 0.5f;
                    float v = sinf(theta) * radius / height + 0.5f;
                    geoData.vertices[vIndex] = glm::vec3(radius * cosf(theta), h2, radius * sinf(theta));
                    geoData.normals[vIndex] = glm::vec3(0.0f, 1.0f, 0.0f);
                    geoData.tangents[vIndex] = glm::vec3(1.0f, 0.0f, 0.0f);
                    geoData.texcoords[vIndex] = glm::vec2(u, v);
                    vIndex++;
                }

                // 放入底端圆心
                geoData.vertices[vIndex] = glm::vec3(0.0f, -h2, 0.0f);
                geoData.normals[vIndex] = glm::vec3(0.0f, -1.0f, 0.0f);
                geoData.tangents[vIndex] = glm::vec3(-1.0f, 0.0f, 0.0f);
                geoData.texcoords[vIndex] = glm::vec2(0.5f, 0.5f);
                vIndex++;

                // 放入底部圆上各点
                for (uint32_t i = 0; i <= slices; ++i)
                {
                    theta = i * per_theta;
                    float u = cosf(theta) * radius / height + 0.5f;
                    float v = sinf(theta) * radius / height + 0.5f;
                    geoData.vertices[vIndex] = glm::vec3(radius * cosf(theta), -h2, radius * sinf(theta));
                    geoData.normals[vIndex] = glm::vec3(0.0f, -1.0f, 0.0f);
                    geoData.tangents[vIndex] = glm::vec3(-1.0f, 0.0f, 0.0f);
                    geoData.texcoords[vIndex] = glm::vec2(u, v);
                    vIndex++;
                }

                // 放入顶部三角形索引
                for (uint32_t i = 1; i <= slices; ++i)
                {
                    geoData.indices32[iIndex++] = offset;
                    geoData.indices32[iIndex++] = offset + i % (slices + 1) + 1;
                    geoData.indices32[iIndex++] = offset + i;
                }

                // 放入底部三角形索引
                offset += slices + 2;
                for (uint32_t i = 1; i <= slices; ++i)
                {
                    geoData.indices32[iIndex++] = offset;
                    geoData.indices32[iIndex++] = offset + i;
                    geoData.indices32[iIndex++] = offset + i % (slices + 1) + 1;
                }
            }

            for (int i = 0; i < geoData.vertices.size(); i++)
            {
                geoData.bigTangents[i] = glm::cross(geoData.normals[i], geoData.tangents[i]);
            }

            return geoData;
        }

        GeometryData CreateCone(float radius, float height, uint32_t slices)
        {

            GeometryData geoData;

            uint32_t vertexCount = 3 * slices + 1;
            uint32_t indexCount = 6 * slices;

            geoData.ResizeVertices(vertexCount);

            geoData.indices32.resize(indexCount);

            float h2 = height / 2;
            float theta = 0.0f;
            float per_theta = 2 * PI / slices;
            float len = sqrtf(height * height + radius * radius);

            //
            // 圆锥侧面
            //
            {
                size_t iIndex = 0;
                size_t vIndex = 0;

                // 放入圆锥尖端顶点(每个顶点位置相同，但包含不同的法向量和切线向量)
                for (uint32_t i = 0; i < slices; ++i)
                {
                    theta = i * per_theta + per_theta / 2;
                    geoData.vertices[vIndex] = glm::vec3(0.0f, h2, 0.0f);
                    geoData.normals[vIndex] = glm::vec3(radius * cosf(theta) / len, height / len, radius * sinf(theta) / len);
                    geoData.tangents[vIndex] = glm::vec3(-sinf(theta), 0.0f, cosf(theta));
                    geoData.texcoords[vIndex] = glm::vec2(0.5f, 0.5f);
                    vIndex++;
                }

                // 放入圆锥侧面底部顶点
                for (uint32_t i = 0; i < slices; ++i)
                {
                    theta = i * per_theta;
                    geoData.vertices[vIndex] = glm::vec3(radius * cosf(theta), -h2, radius * sinf(theta));
                    geoData.normals[vIndex] = glm::vec3(radius * cosf(theta) / len, height / len, radius * sinf(theta) / len);
                    geoData.tangents[vIndex] = glm::vec3(-sinf(theta), 0.0f, cosf(theta));
                    geoData.texcoords[vIndex++] = glm::vec2(cosf(theta) / 2 + 0.5f, sinf(theta) / 2 + 0.5f);
                }

                // 放入索引
                for (uint32_t i = 0; i < slices; ++i)
                {
                    geoData.indices32[iIndex++] = i;
                    geoData.indices32[iIndex++] = slices + (i + 1) % slices;
                    geoData.indices32[iIndex++] = slices + i % slices;
                }
            }

            //
            // 圆锥底面
            //
            {
                size_t iIndex = 3 * (size_t)slices;
                size_t vIndex = 2 * (size_t)slices;

                // 放入圆锥底面顶点
                for (uint32_t i = 0; i < slices; ++i)
                {
                    theta = i * per_theta;

                    geoData.vertices[vIndex] = glm::vec3(radius * cosf(theta), -h2, radius * sinf(theta)),
                    geoData.normals[vIndex] = glm::vec3(0.0f, -1.0f, 0.0f);
                    geoData.tangents[vIndex] = glm::vec3(-1.0f, 0.0f, 0.0f);
                    geoData.texcoords[vIndex++] = glm::vec2(cosf(theta) / 2 + 0.5f, sinf(theta) / 2 + 0.5f);
                }
                // 放入圆锥底面圆心
                geoData.vertices[vIndex] = glm::vec3(0.0f, -h2, 0.0f),
                geoData.normals[vIndex] = glm::vec3(0.0f, -1.0f, 0.0f);
                geoData.texcoords[vIndex++] = glm::vec2(0.5f, 0.5f);

                // 放入索引
                uint32_t offset = 2 * slices;
                for (uint32_t i = 0; i < slices; ++i)
                {
                    geoData.indices32[iIndex++] = offset + slices;
                    geoData.indices32[iIndex++] = offset + i % slices;
                    geoData.indices32[iIndex++] = offset + (i + 1) % slices;
                }
            }

            for (int i = 0; i < geoData.vertices.size(); i++)
            {
                geoData.bigTangents[i] = glm::cross(geoData.normals[i], geoData.tangents[i]);
            }

            return geoData;
        }

        GeometryData CreatePlane(const glm::vec2 &planeSize, const glm::vec2 &maxTexCoord)
        {
            return CreatePlane(planeSize.x, planeSize.y, maxTexCoord.x, maxTexCoord.y);
        }

        GeometryData CreatePlane(float width, float depth, float texU, float texV)
        {

            GeometryData geoData;

            geoData.ResizeVertices(4);

            uint32_t vIndex = 0;
            geoData.vertices[vIndex] = glm::vec3(-width / 2, 0.0f, -depth / 2);
            geoData.normals[vIndex] = glm::vec3(0.0f, 1.0f, 0.0f);
            geoData.tangents[vIndex] = glm::vec3(1.0f, 0.0f, 0.0f);
            geoData.texcoords[vIndex++] = glm::vec2(0.0f, texV);

            geoData.vertices[vIndex] = glm::vec3(-width / 2, 0.0f, depth / 2);
            geoData.normals[vIndex] = glm::vec3(0.0f, 1.0f, 0.0f);
            geoData.tangents[vIndex] = glm::vec3(1.0f, 0.0f, 0.0f);
            geoData.texcoords[vIndex++] = glm::vec2(0.0f, 0.0f);

            geoData.vertices[vIndex] = glm::vec3(width / 2, 0.0f, depth / 2);
            geoData.normals[vIndex] = glm::vec3(0.0f, 1.0f, 0.0f);
            geoData.tangents[vIndex] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
            geoData.texcoords[vIndex++] = glm::vec2(texU, 0.0f);

            geoData.vertices[vIndex] = glm::vec3(width / 2, 0.0f, -depth / 2);
            geoData.normals[vIndex] = glm::vec3(0.0f, 1.0f, 0.0f);
            geoData.tangents[vIndex] = glm::vec3(1.0f, 0.0f, 0.0f);
            geoData.texcoords[vIndex++] = glm::vec2(texU, texV);

            geoData.indices32 = {0, 1, 2, 2, 3, 0};

            for (int i = 0; i < geoData.vertices.size(); i++)
            {
                geoData.bigTangents[i] = glm::cross(geoData.normals[i], geoData.tangents[i]);
            }

            return geoData;
        }

        GeometryData CreateGrid(const glm::vec2 &gridSize, const glm::ivec2 &slices, const glm::vec2 &maxTexCoord,
                                const std::function<float(float, float)> &heightFunc,
                                const std::function<glm::vec3(float, float)> &normalFunc,
                                const std::function<glm::vec4(float, float)> &colorFunc)
        {

            GeometryData geoData;
            uint32_t vertexCount = (slices.x + 1) * (slices.y + 1);
            uint32_t indexCount = 6 * slices.x * slices.y;

            geoData.ResizeVertices(vertexCount);

            geoData.indices32.resize(indexCount);

            uint32_t vIndex = 0;
            uint32_t iIndex = 0;

            float sliceWidth = gridSize.x / slices.x;
            float sliceDepth = gridSize.y / slices.y;
            float leftBottomX = -gridSize.x / 2;
            float leftBottomZ = -gridSize.y / 2;
            float posX, posZ;
            float sliceTexWidth = maxTexCoord.x / slices.x;
            float sliceTexDepth = maxTexCoord.y / slices.y;

            glm::vec3 normal;
            glm::vec3 tangent;
            // 创建网格顶点
            //  __ __
            // | /| /|
            // |/_|/_|
            // | /| /|
            // |/_|/_|
            for (uint32_t z = 0; z <= slices.y; ++z)
            {
                posZ = leftBottomZ + z * sliceDepth;
                for (uint32_t x = 0; x <= slices.x; ++x)
                {
                    posX = leftBottomX + x * sliceWidth;
                    // 计算法向量并归一化
                    normal = normalFunc(posX, posZ);
                    normal = glm::normalize(normal);
                    // XMStoreFloat3(&normal, XMVector3Normalize(XMLoadFloat3(&normal)));
                    //  计算法平面与z=posZ平面构成的直线单位切向量，维持w分量为1.0f
                    // XMStoreFloat4(&tangent, XMVector3Normalize(XMVectorSet(normal.y, -normal.x, 0.0f, 0.0f)) + g_XMIdentityR3);
                    tangent = glm::normalize(glm::vec3(normal.y, -normal.x, 0.0f));

                    geoData.vertices[vIndex] = glm::vec3(posX, heightFunc(posX, posZ), posZ);
                    geoData.normals[vIndex] = normal;
                    geoData.tangents[vIndex] = tangent;
                    geoData.texcoords[vIndex++] = glm::vec2(x * sliceTexWidth, maxTexCoord.y - z * sliceTexDepth);
                }
            }
            // 放入索引
            for (uint32_t i = 0; i < slices.y; ++i)
            {
                for (uint32_t j = 0; j < slices.x; ++j)
                {
                    {
                        geoData.indices32[iIndex++] = i * (slices.x + 1) + j;
                        geoData.indices32[iIndex++] = (i + 1) * (slices.x + 1) + j;
                        geoData.indices32[iIndex++] = (i + 1) * (slices.x + 1) + j + 1;

                        geoData.indices32[iIndex++] = (i + 1) * (slices.x + 1) + j + 1;
                        geoData.indices32[iIndex++] = i * (slices.x + 1) + j + 1;
                        geoData.indices32[iIndex++] = i * (slices.x + 1) + j;
                    }
                }
            }
            for (int i = 0; i < geoData.vertices.size(); i++)
            {
                geoData.bigTangents[i] = glm::cross(geoData.normals[i], geoData.tangents[i]);
            }

            return geoData;
        }

        GeometryData CreateQuad()
        {
            GeometryData geoData;

            geoData.vertices = {
                {-1.0f, -1.0f, 0.0f},
                {-1.0f, 1.0f, 0.0f},
                {1.0f, 1.0f, 0.0f},
                {1.0f, -1.0f, 0.0f},
            };

            geoData.texcoords = {
                {0.0f, 1.0f},
                {0.0f, 0.0f},
                {1.0f, 0.0f},
                {1.0f, 1.0f}};

            geoData.normals = {
                {0.0f, 0.0f, -1.0f},
                {0.0f, 0.0f, -1.0f},
                {0.0f, 0.0f, -1.0f},
                {0.0f, 0.0f, -1.0f}};

            geoData.tangents = {
                {1.0f, 0.0f, 0.0f},
                {1.0f, 0.0f, 0.0f},
                {1.0f, 0.0f, 0.0f},
                {1.0f, 0.0f, 0.0f}};

            geoData.indices32 = {
                0, 1, 2,
                2, 3, 0};

            geoData.bigTangents.resize(geoData.vertices.size());
            for (int i = 0; i < geoData.vertices.size(); i++)
            {
                geoData.bigTangents[i] = glm::cross(geoData.normals[i], geoData.tangents[i]);
            }

            return geoData;
        }

        GeometryData Create2DTexture()
        {
            GeometryData geoData;

            geoData.vertices = {
                {-1.0f, 1.0f, 0.0f},
                {-1.0f, -1.0f, 0.0f},
                {1.0f, -1.0f, 0.0f},
                {1.0f, 1.0f, 0.0f}};

            geoData.texcoords = {
                {1.0f, 0.0f},
                {1.0f, 1.0f},
                {0.0f, 1.0f},
                {0.0f, 0.0f}};

            geoData.normals = {
                {0.0f, 0.0f, 1.0f},
                {0.0f, 0.0f, 1.0f},
                {0.0f, 0.0f, 1.0f},
                {0.0f, 0.0f, 1.0f}};

            geoData.tangents = {
                {1.0f, 0.0f, 0.0f},
                {1.0f, 0.0f, 0.0f},
                {1.0f, 0.0f, 0.0f},
                {1.0f, 0.0f, 0.0f}};

            // geoData.indices32 = {
            //     0, 1, 2,
            //     2, 3, 0
            // };

            geoData.indices32 = {
                0, 1, 2,
                2, 3, 0};

            geoData.bigTangents.resize(geoData.vertices.size());
            for (int i = 0; i < geoData.vertices.size(); i++)
            {
                geoData.bigTangents[i] = glm::cross(geoData.normals[i], geoData.tangents[i]);
            }

            return geoData;
        };
    };
};
