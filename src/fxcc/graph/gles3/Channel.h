#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/PositionKey.h"
#include "fxcc/graph/RotationKey.h"
#include "fxcc/graph/ScaleKey.h"

#include "ogl/math/Transform.h"

namespace Ogl
{
    namespace Gut
    {
        struct Channel
        {
            std::string m_NodeName;

            struct Desc
            {
                std::string m_Path;
                int m_AnimIndex;
                std::string m_NodeName;
            } m_Desc;
            struct Header
            {
                unsigned int m_NumPositionKeys, m_NumRotationKeys, m_NumScaleKeys;
            } m_Header;

            void Resize()
            {
                if (m_Header.m_NumPositionKeys > 0)
                {
                    m_PositionKeys.resize(m_Header.m_NumPositionKeys);
                }
                if (m_Header.m_NumRotationKeys > 0)
                {
                    m_RotationKeys.resize(m_Header.m_NumRotationKeys);
                }
                if (m_Header.m_NumScaleKeys > 0)
                {
                    m_ScaleKeys.resize(m_Header.m_NumScaleKeys);
                }
            };

            void Calculate() {
                m_Header.m_NumPositionKeys = m_PositionKeys.size();
                m_Header.m_NumRotationKeys = m_RotationKeys.size();
                m_Header.m_NumScaleKeys = m_ScaleKeys.size();
            };

            std::vector<std::shared_ptr<Ogl::Gut::PositionKey>> m_PositionKeys;
            std::vector<std::shared_ptr<Ogl::Gut::RotationKey>> m_RotationKeys;
            std::vector<std::shared_ptr<Ogl::Gut::ScaleKey>> m_ScaleKeys;

            Channel(aiNodeAnim* channel);

            void Write(std::ofstream &ofs)
            {
                Calculate();
                ofs.write((const char *)&m_Header, sizeof(m_Header));
                if (m_Header.m_NumPositionKeys)
                    ofs.write((const char *)&m_PositionKeys[0], sizeof(PositionKey) * m_PositionKeys.size());
                if (m_Header.m_NumRotationKeys)
                    ofs.write((const char *)&m_RotationKeys[0], sizeof(RotationKey) * m_RotationKeys.size());
                if (m_Header.m_NumScaleKeys)
                    ofs.write((const char *)&m_ScaleKeys[0], sizeof(ScaleKey) * m_ScaleKeys.size());
            }
            void Read(std::ifstream& ifs)
            {
                ifs.read((char *)&m_Header, sizeof(m_Header));
                Resize();

                if (m_Header.m_NumPositionKeys)
                    ifs.read((char *)&m_PositionKeys[0], sizeof(PositionKey) * m_PositionKeys.size());
                if (m_Header.m_NumRotationKeys)
                    ifs.read((char *)&m_RotationKeys[0], sizeof(RotationKey) * m_RotationKeys.size());
                if (m_Header.m_NumScaleKeys)
                    ifs.read((char *)&m_ScaleKeys[0], sizeof(ScaleKey) * m_ScaleKeys.size());
            }
            void Read(std::string path)
            {
                std::ifstream ifs(path, std::ios::binary);
                Read(ifs);
                ifs.close();
            };

            void Write(std::string path)
            {
                std::ofstream ofs(path, std::ios::binary);

                ofs.flush();
                ofs.close();
            }

            glm::vec3 GetPosition(double ct_time) const;
            glm::quat GetRotation(double ct_time) const;
            glm::vec3 GetScale(double ct_time) const;

            int GetPositionIndex(double index) const;
            int GetRotationIndex(double index) const;
            int GetScaleIndex(double index) const;

            glm::mat4 GetSlerpTransform(double index) const;
        };
    }
};