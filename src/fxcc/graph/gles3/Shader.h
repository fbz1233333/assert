#pragma once

#include "fxcc/graph/gles3/pch.h"
#include "fxcc/graph/gles3/Shader.h"

namespace fxcc
{
    namespace graph
    {
        namespace gles3
        {
            struct Shader
            {
                std::string m_FragCode;

                std::string m_VertCode;

                Shader(const std::string &vCode, const std::string &fCode);

                unsigned int m_Id;

                bool Init();

                void Use() const;

                void Create();
                
                void Release();
                
                void Link();

                void Delete() const;

                void Bind(const std::string &name, unsigned int binding);

                unsigned int GetUniformBlockIndex(const std::string &name);

                unsigned int GetLocation(const std::string &name) const;

                static void UnUse();

                void setBool(const std::string &name, bool value) const
                {
                    glUniform1i(GetLocation(name), (int)value);
                }
                void setInt(const std::string &name, int value) const
                {
                    glUniform1i(GetLocation(name), value);
                }
                void setFloat(const std::string &name, float value) const
                {
                    glUniform1f(GetLocation(name), value);
                }
                void SetFloatArray(const std::string &name, float *val, int num)
                {
                    for (int i = 0; i < num; i++)
                    {
                        std::string label = name + std::string("[") + std::to_string(i) + "]";
                        setFloat(label, val[i]);
                    }
                }

                void setVec2(const std::string &name, const float *value) const
                {
                    glUniform2fv(GetLocation(name), 1, &value[0]);
                }
                void setVec2(const std::string &name, float x, float y) const
                {
                    glUniform2f(GetLocation(name), x, y);
                }
                void setVec3(const std::string &name, const float *value) const
                {
                    glUniform3fv(GetLocation(name), 1, &value[0]);
                }
                void setVec3(const std::string &name, float x, float y, float z) const
                {
                    glUniform3f(GetLocation(name), x, y, z);
                }
                // ------------------------------------------------------------------------
                void setVec4(const std::string &name, const float *value, const int num = 1) const
                {
                    glUniform4fv(GetLocation(name), num, &value[0]);
                }
                void setVec4(const std::string &name, float x, float y, float z, float w)
                {
                    glUniform4f(GetLocation(name), x, y, z, w);
                }
                // ------------------------------------------------------------------------
                void setMat2(const std::string &name, const float *mat) const
                {
                    glUniformMatrix2fv(GetLocation(name), 1, GL_FALSE, &mat[0]);
                }
                void setMat3(const std::string &name, const float *mat) const
                {
                    glUniformMatrix3fv(GetLocation(name), 1, GL_FALSE, &mat[0]);
                }
                void setMat4(const std::string &name, const float *mat) const
                {
                    glUniformMatrix4fv(GetLocation(name), 1, GL_FALSE, &mat[0]);
                }

                void setVec2(const std::string &name, const glm::vec2 &v) const
                {
                    this->setVec2(name, &v.x);
                }

                void setVec3(const std::string &name, const glm::vec3 &v) const
                {
                    this->setVec3(name, &v.x);
                }

                void setVec4(const std::string &name, const glm::vec4 &v) const
                {
                    this->setVec4(name, &v.x);
                }

                void setMat2(const std::string &name, const glm::mat2 mat) const
                {
                    this->setMat2(name, &mat[0][0]);
                }
                void setMat3(const std::string &name, const glm::mat3 mat) const
                {
                    this->setMat3(name, &mat[0][0]);
                }
                void setMat4(const std::string &name, const glm::mat4 &mat) const
                {
                    this->setMat4(name, &mat[0][0]);
                }
                virtual ~Shader();
            };

        };
    };
};