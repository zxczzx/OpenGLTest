#include "Game.h"


Game::Game() : 
	elapsed(0.0f), 
	window("myRPG", sf::Vector2u(800, 600))
{
	window.getRenderWindow()->setMouseCursorVisible(false);
	//window.getRenderWindow()->setMouseCursorGrabbed(true);

	sf::Mouse::setPosition(sf::Vector2i(400, 300), *dynamic_cast<sf::Window*>(window.getRenderWindow()));

	// Initialize GLEW
	glewExperimental = GL_TRUE;
	glewInit();
	glViewport(0, 0, window.getWindowSize().x, window.getWindowSize().y);
	glEnable(GL_DEPTH_TEST);

	// Reset clock
	clock.restart();

	// Initialize world
	world = new World();
}


Game::~Game()
{
	//delete world;
}

void Game::handleInput()
{
	world->handleInput();
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
	world->render();

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
