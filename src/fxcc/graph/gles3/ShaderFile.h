#pragma once

#include "fxcc/graph/gles3/pch.h"

namespace fxcc
{
    namespace graph
    {
        namespace gles3
        {
            struct ShaderFile
            {
                unsigned int m_Id;
                
                std::string m_Code;

                unsigned int m_Type;

                ShaderFile(const std::string &code, unsigned int shaderType);

                bool Init();

                std::string GetTypeString();

                void Delete();

                int CheckShaderFile();
            };
        }
    }
};