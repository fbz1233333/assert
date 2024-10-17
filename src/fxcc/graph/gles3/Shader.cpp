#include "fxcc/graph/Shader.h"

using namespace Ogl::Gut;

Shader::Shader(const ShaderDesc &desc) : m_Desc(desc)
{
	Create();
	Init();
};


Ogl::Gut::Shader::Shader(const std::string &vCode, const std::string &fCode) {
	
	m_Desc.m_Desc1.m_VertCode = vCode;
	m_Desc.m_Desc1.m_FragCode = fCode;
	m_Desc.m_Type = ShaderDescType::_shader_desc_text_;

	Create();
	Init();
};

bool ShaderCode::checkCompileErrors(unsigned int shader, std::string type)
{
	GLint success;
	GLchar infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			wtclog::info("ERROR::SHADER_COMPILATION_ERROR of type: %s \n %s", type.c_str(), infoLog);
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			wtclog::info("ERROR::PROGRAM_LINKING_ERROR of type: %s \n %s", type.c_str(), infoLog);
		}
	}
	return success;
};

std::string ShaderCode::GetShaderType(int type)
{
	switch (type)
	{
	case GL_VERTEX_SHADER:
		return "Vertex";
	case GL_FRAGMENT_SHADER:
		return "Fragment";
	default:
		break;
	}
	return "Unknown";
}

bool ShaderFile::CreateFromFile(std::string path, int type)
{
	bool gr = true;

	std::ifstream ifs(path, std::ios::in);

	if (!ifs.is_open())
	{
		wtclog::info("cannot open file from %s \n", path.c_str());
		return false;
	}

	wtclog::info("Loading the file %s", path.c_str());

	std::string text = std::string((std::istreambuf_iterator<char>(ifs)),
								   (std::istreambuf_iterator<char>()));

	gr = CreateFrom(text.c_str(), type);
	ifs.close();
	return gr;
}


Ogl::Gut::Shader::Shader()
{
	Create();
}

void Ogl::Gut::Shader::Init()
{

	switch (m_Desc.m_Type)
	{
	case ShaderDescType::_shader_desc_text_:
		Init1();
		break;
	case ShaderDescType::_shader_desc_file_:
		Init2();
		break;
	default:
		std::cout << "cannot create shader from desc" << std::endl;
		break;
	}
};

void Ogl::Gut::Shader::Init1()
{
	const auto &desc = m_Desc.m_Desc1;

	ShaderFile vFile;
	ShaderFile fFile;

	vFile.CreateFrom(desc.m_VertCode.c_str(), GL_VERTEX_SHADER);
	fFile.CreateFrom(desc.m_FragCode.c_str(), GL_FRAGMENT_SHADER);

	glAttachShader(this->ID, vFile.id);
	glAttachShader(this->ID, fFile.id);

	glLinkProgram(ID);
}

void Ogl::Gut::Shader::Init2() {

	m_Desc.Parse2To1();
	Init1();
};

bool ShaderCode::CreateFrom(const char *code, int type)
{
	this->id = glCreateShader(type);
	glShaderSource(id, 1, &code, NULL);
	glCompileShader(id);
	if (!checkCompileErrors(id, GetShaderType(type)))
	{
		return false;
	}
	return true;
}

void ShaderCode::Release()
{
	glDeleteShader(this->id);
}

void Shader::Use() const
{
	glUseProgram(ID);
}

void Shader::Create()
{
	ID = glCreateProgram();
}

void Shader::Release()
{
	glDeleteProgram(this->ID);
}

void Shader::Link()
{
	glLinkProgram(ID);
};


void Shader::UnUse()
{
	glUseProgram(0);
}

void Ogl::Gut::Shader::Delete() const
{
	glDeleteShader(ID);
}

void Ogl::Gut::Shader::Bind(const std::string &name, unsigned int binding)
{
	glUniformBlockBinding(ID, GetUniformBlockIndex(name), binding);
}

unsigned int Ogl::Gut::Shader::GetUniformBlockIndex(const std::string &name)
{
	return glGetUniformBlockIndex(ID, name.c_str());
}

Ogl::Gut::Shader::~Shader()
{
	Delete();
}
