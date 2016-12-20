#pragma once
#include "Shapes.h"
#include "Shader.h"
#include "Game.h"
#include <chrono>
#include <glm/glm.hpp>
#include <vector>

class Triangle : public Shapes
{
public:
	Triangle(Game *game);
	~Triangle() override;

	void handleInput() override;
	void update() override;
	void render() override;

private:
	GLint uniColor;
	GLuint texture;
	GLuint texture2;
	Game *_game;
	std::vector<glm::vec3> cubePositions;
	std::chrono::time_point<std::chrono::steady_clock> t_start;
};
