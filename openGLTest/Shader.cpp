#include "Shader.h"



Shader::Shader(const GLchar * vertexPath, const GLchar * fragmentPath)
{
	// 1. Retrieve the vertex/fragment source code from filePath
	std::string vertexCode;
	std::string fragmentCode;

	// Open files
	std::ifstream vShaderFile(vertexPath, std::ios::in | std::ios::binary);;
	std::ifstream fShaderFile(fragmentPath, std::ios::in | std::ios::binary);;
	std::stringstream vShaderStream;
	std::stringstream fShaderStream;

	if (vShaderFile)
	{
		// Read file's buffer contents into streams
		vShaderStream << vShaderFile.rdbuf();
		vShaderFile.close();
	}
	else
	{
		//LOG ERROR
	}

	if (fShaderFile)
	{
		// Read file's buffer contents into streams
		fShaderStream << fShaderFile.rdbuf();
		fShaderFile.close();
	}
	else
	{
		// LOG ERROR
	}

	// Convert stream into string
	vertexCode = vShaderStream.str();
	fragmentCode = fShaderStream.str();

	const GLchar *vShaderCode = vertexCode.c_str();
	const GLchar *fShaderCode = fragmentCode.c_str();
	// 2. Compile shaders
	GLuint vertex, fragment;
	GLint success;
	// Vertex Shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	// Print compile errors if any
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		//LOG ERROR
	}
	// Fragment Shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	// Print compile errors if any
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		//LOG ERROR
	}
	// Shader Program
	program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	// Print linking errors if any
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		GLchar infoLog[512];
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		//LOG ERROR
	}
	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

Shader::~Shader()
{
}

void Shader::Use()
{
	glUseProgram(program);
}
