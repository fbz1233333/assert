#include "fxcc/graph/gles3/ShaderFile.h"
#include "ShaderFile.h"

using namespace fxcc::graph::gles3;

ShaderFile::ShaderFile(const std::string &code, unsigned int shaderType)
    : m_Code(code), m_Type(shaderType)
{
    Init();
};

void ShaderFile::Delete()
{
    glDeleteShader(m_Id);
};

bool fxcc::graph::gles3::ShaderFile::Init()
{
    // Create();
    const char *code = m_Code.c_str();

    this->m_Id = glCreateShader(m_Type);
    glShaderSource(m_Id, 1, &code, NULL);
    glCompileShader(m_Id);

    if (!CheckShaderFile())
    {
        ztclog::info("Failed create shader file %s", GetTypeString().c_str());
        return false;
    }

    return true;
}

std::string fxcc::graph::gles3::ShaderFile::GetTypeString()
{
    static std::map<int, std::string> stringMap =
        {{GL_VERTEX_SHADER, "vertex Shader"},
         {GL_FRAGMENT_SHADER, "Fragment Shader"}};

    if (stringMap.find(m_Type) != stringMap.end())
    {
        return stringMap[m_Type];
    }
    return "PROGRAM";
}

int fxcc::graph::gles3::ShaderFile::CheckShaderFile()
{
    std::string type = GetTypeString();

    GLint success;
    GLchar infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(m_Id, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(m_Id, 1024, NULL, infoLog);
            ztclog::info("ERROR::SHADER_COMPILATION_ERROR of type: %s \n %s", type.c_str(), infoLog);
        }
    }
    else
    {
        glGetProgramiv(m_Id, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(m_Id, 1024, NULL, infoLog);
            ztclog::info("ERROR::PROGRAM_LINKING_ERROR of type: %s \n %s", type.c_str(), infoLog);
        }
    }
    return success;
}
