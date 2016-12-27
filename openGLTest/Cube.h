#pragma once
#include "Shapes.h"
#include "Shader.h"

class Cube : public Shapes
{
public:
	Cube();
	~Cube();

	void render(glm::vec3 position) override;

	void setup(Shader *shade);

private:
	GLint uniColor;
	GLuint texture;
	GLuint texture2;
	Shader *shader;
};

