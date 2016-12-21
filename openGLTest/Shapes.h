#pragma once
#include <GL/glew.h>
#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shapes
{
public:
	Shapes();
	virtual ~Shapes();

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

