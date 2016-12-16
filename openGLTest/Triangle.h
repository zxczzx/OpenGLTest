#pragma once
#include "Shapes.h"
#include "Shader.h"
#include <chrono>

class Triangle : public Shapes
{
public:
	Triangle();
	~Triangle();

	void handleInput() override;
	void update() override;
	void render() override;

private:
	GLint uniColor;
	std::chrono::time_point<std::chrono::steady_clock> t_start;
};

