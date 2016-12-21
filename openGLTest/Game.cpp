#include "Game.h"
#include <string>
#include "Triangle.h"


Game::Game() : 
	elapsed(0.0f), 
	window("myRPG", sf::Vector2u(800, 600))
{
	// Initialize GLEW
	glewExperimental = GL_TRUE;
	glewInit();
	glViewport(0, 0, window.getWindowSize().x, window.getWindowSize().y);
	glEnable(GL_DEPTH_TEST);

	// Reset clock
	clock.restart();

	// Initialize shape
	shape = new Triangle(this);
}


Game::~Game()
{
	delete shape;
}

void Game::handleInput()
{
	shape->handleInput();
}

void Game::update()
{
	while (window.getRenderWindow()->pollEvent(window.event)) 
	{
		window.update();
	}
}

void Game::render()
{
	// Clear to black context window
	window.beginDraw();
	
	// Render shape
	shape->render();

	// Swap buffers
	window.endDraw();
}

void Game::restartClock()
{
	elapsed += clock.restart().asSeconds();
}


sf::Time Game::getElapsed()
{
	return clock.getElapsedTime();
}

Window *Game::getWindow()
{
	return &window;
}
