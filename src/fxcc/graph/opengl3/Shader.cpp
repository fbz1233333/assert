#include "fxcc/graph/opengl3/Shader.h"
#include "fxcc/graph/opengl3/ShaderFile.h"
#include "Shader.h"

using namespace fxcc::graph::opengl3;

fxcc::graph::opengl3::Shader::Shader(const std::string &vCode, const std::string &fCode)
	: m_VertCode(vCode), m_FragCode(fCode)
{
	Init();
};

bool Shader::Init()
{
	Create();
	ShaderFile vertFile(m_VertCode, GL_VERTEX_SHADER);
	ShaderFile fragFile(m_FragCode, GL_FRAGMENT_SHADER);

	glAttachShader(m_Id, vertFile.m_Id);
	glAttachShader(m_Id, fragFile.m_Id);

	Link();

	// auto delete the shader file
	vertFile.Delete();
	fragFile.Delete();

	return true;
};

void Shader::Use() const
{
	glUseProgram(m_Id);
}

void Shader::Create()
{
	m_Id = glCreateProgram();
}

void Shader::Release()
{
	glDeleteProgram(this->m_Id);
}

void Shader::Link()
{
	glLinkProgram(m_Id);
};

void Shader::UnUse()
{
	glUseProgram(0);
}

void Shader::Delete() const
{
	glDeleteShader(m_Id);
}

void Shader::Bind(const std::string &name, unsigned int binding)
{
	glUniformBlockBinding(m_Id, GetUniformBlockIndex(name), binding);
}

unsigned int Shader::GetUniformBlockIndex(const std::string &name)
{
	return glGetUniformBlockIndex(m_Id, name.c_str());
}

Shader::~Shader()
{
	Delete();
}

unsigned int fxcc::graph::opengl3::Shader::GetLocation(const std::string &name) const
{
	return glGetUniformLocation(m_Id, name.c_str());
};