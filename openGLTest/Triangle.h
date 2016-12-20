#pragma once
#include "Shapes.h"
#include "Shader.h"
#include "Game.h"
#include <chrono>

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
	std::chrono::time_point<std::chrono::steady_clock> t_start;
};

