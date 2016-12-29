#pragma once
#include "Cube.h"

class CubeTextured : public Cube
{
public:
	CubeTextured();
	~CubeTextured();

	void render(glm::vec3 position) override;
	virtual void setup() override;

private:
	GLuint texture;
	GLuint texture2;
};

