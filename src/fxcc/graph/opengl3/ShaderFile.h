#pragma once

#include "fxcc/graph/opengl3/pch.h"

namespace fxcc
{
    namespace graph
    {
        namespace opengl3
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