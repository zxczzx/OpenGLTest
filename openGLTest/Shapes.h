#pragma once
#include <GL/glew.h>
#include "Shader.h"

class Shapes
{
public:
	Shapes();
	~Shapes();

	virtual void handleInput();
	virtual void update();
	virtual void render();

protected:
	GLuint vao;
	GLuint vbo;
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgram;
	GLint posAttrib;
	Shader *shader;
};

