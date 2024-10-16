#pragma once

#include "fxcc/graph/pch.h"

namespace fxcc
{
    namespace graph
    {

        struct GeometryData
        {
            std::vector<glm::vec3> vertices;
            std::vector<glm::vec3> normals;
            std::vector<glm::vec2> texcoords;
            std::vector<glm::vec3> tangents;
            std::vector<glm::vec3> bigTangents;

            std::vector<uint32_t> indices32;

            struct Header
            {
                int numVertcies;
                int numNormals;
                int numTexCoords;
                int numTangents;
                int numBigTangents;
            };

            Header GetHeader()
            {
                Header res;
                res.numVertcies = vertices.size();
                res.numNormals = normals.size();
                res.numTexCoords = texcoords.size();
                res.numTangents = tangents.size();
                res.numBigTangents = bigTangents.size();
                return res;
            }

            bool ResizeHeader(const Header &header);

            void ResizeVertices(unsigned int numVertices)
            {
                vertices.resize(numVertices);
                normals.resize(numVertices);
                texcoords.resize(numVertices);
                tangents.resize(numVertices);
                bigTangents.resize(numVertices);
            }

            void Resize32(unsigned int numVertices, unsigned int numIndices)
            {
                ResizeVertices(numVertices);
                indices32.resize(numIndices);
            }

            static GeometryData SubMeshData32(const std::vector<GeometryData> &meshDatas)
            {
                GeometryData res;
                for (const auto &meshData : meshDatas)
                {
                    // calculate current vertices num
                    int indexOffset = res.vertices.size();

                    res.vertices.insert(res.vertices.end(), meshData.vertices.begin(), meshData.vertices.end());
                    res.normals.insert(res.normals.end(), meshData.normals.begin(), meshData.normals.end());
                    res.texcoords.insert(res.texcoords.end(), meshData.texcoords.begin(), meshData.texcoords.end());
                    res.tangents.insert(res.tangents.end(), meshData.tangents.begin(), meshData.tangents.end());
                    res.bigTangents.insert(res.bigTangents.end(), meshData.bigTangents.begin(), meshData.bigTangents.end());

                    auto &indices = res.indices32;
                    const auto &targetIndices = meshData.indices32;

                    for (auto &index : targetIndices)
                    {
                        indices.push_back(index + indexOffset);
                    }
                }
                return res;
            }

            void Write(std::ofstream &ofs);
        };
    }
};
