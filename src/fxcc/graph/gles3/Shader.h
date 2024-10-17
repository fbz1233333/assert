#pragma once

#include "fxcc/graph/pch.h"
#include "fxcc/graph/Util.h"
#include "fxcc/graph/ShaderDesc.h"
#include "fxcc/graph/Base.h"

namespace Ogl
{
    namespace Gut
    {

        struct ShaderCode
        {
            unsigned int id = 0;
            bool CreateFrom(const char *code, int type);
            void Release();
            std::string GetShaderType(int type);

            bool checkCompileErrors(unsigned int shader, std::string type);
        };

        struct ShaderFile : public ShaderCode
        {
            bool CreateFromFile(std::string path, int type);
        };

        struct Shader :public Base
        {
            ShaderDesc m_Desc;
            
        
            Shader();
            Shader(const ShaderDesc &desc);
            Shader(const std::string& vCode, const std::string& fCode);

            unsigned int ID = 0;

            void Init();

            void Init1();

            void Init2();

            void Use() const;
            void Create();
            void Release();
            void Link();


            static void UnUse() ;
            void Delete() const;

            void Bind(const std::string &name, unsigned int binding);

            unsigned int GetUniformBlockIndex(const std::string &name);

            unsigned int GetLocation(const std::string &name) const
            {
                unsigned int res = glGetUniformLocation(ID, name.c_str());

                return res;
            }

            void setBool(const std::string &name, bool value) const
            {
                glUniform1i(GetLocation(name), (int)value);
            }
            // ------------------------------------------------------------------------
            void setInt(const std::string &name, int value) const
            {
                glUniform1i(GetLocation(name), value);
            }
            // ------------------------------------------------------------------------
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
            // ------------------------------------------------------------------------
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
            // ------------------------------------------------------------------------
            void setMat3(const std::string &name, const float *mat) const
            {
                glUniformMatrix3fv(GetLocation(name), 1, GL_FALSE, &mat[0]);
            }
            // ------------------------------------------------------------------------
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
            // ------------------------------------------------------------------------
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

        //struct ShaderVertexFramentDesc
        //{
        //    const char *vcode;
        //    const char *fcode;
        //};

        //struct ShaderVertexFragment : public Shader
        //{
        //};

        //struct ShaderVertexGeometryFragment : public Shader
        //{
        //};

    };
};