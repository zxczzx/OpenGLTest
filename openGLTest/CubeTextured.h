#pragma once
#include "Cube.h"
#include <chrono>

class CubeTextured : public Cube
{
public:
	CubeTextured();
	~CubeTextured();

	void render(glm::vec3 position) override;
	virtual void setup() override;

private:
	GLuint texture;
	GLuint specularMap;
};

