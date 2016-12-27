#pragma once
#include "Window.h"
#include "World.h"
class World;

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
	World *world;
	sf::Clock clock;
	float elapsed;
};

