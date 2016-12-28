#pragma once
#include "Shapes.h"
#include "Shader.h"

class Cube : public Shapes
{
public:
	Cube(ShapeType type);
	~Cube();

	void render(glm::vec3 position) override;

	void setup();

	ShapeType getShapeType();
	Shader *getShader();

private:
	GLint uniColor;
	GLuint texture;
	GLuint texture2;
	Shader *shader;
	ShapeType shapeType;
};

