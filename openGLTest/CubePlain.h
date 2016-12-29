#pragma once
#include "Cube.h"

class CubePlain : public Cube
{
public:
	CubePlain();
	~CubePlain();

	void render(glm::vec3 position) override;
	virtual void setup() override;
};

