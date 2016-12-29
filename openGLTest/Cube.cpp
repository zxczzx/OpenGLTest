#include "Cube.h"


Cube::Cube()
{
}


Cube::~Cube()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}


void Cube::render(glm::vec3 position)
{
}

void Cube::setup()
{
}

Shader *Cube::getShader()
{
	return shader;
}
