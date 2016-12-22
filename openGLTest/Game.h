#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <GL/glew.h>
#include "Window.h"
#include "Shapes.h"
#include "Shader.h"

class Game
{
public:
	Game();
	~Game();

	void handleInput();
	void update();
	void render();

	void restartClock();

	sf::Time getElapsed();
	Window *getWindow();

private:
	Window window;
	Shapes *shape;
	//Shader *shader;
	sf::Clock clock;
	float elapsed;
};

