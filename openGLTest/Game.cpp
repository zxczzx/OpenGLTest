#include "Game.h"
#include <string>
#include "Triangle.h"


Game::Game() : 
	elapsed(0.0f), 
	window("myRPG", sf::Vector2u(800, 600))
{
	window.getRenderWindow()->setMouseCursorVisible(false);
<<<<<<< Updated upstream
	//window.getRenderWindow()->setMouseCursorGrabbed(true);

	sf::Mouse::setPosition(sf::Vector2i(400, 300), *dynamic_cast<sf::Window*>(window.getRenderWindow()));

=======
	window.getRenderWindow()->setMouseCursorGrabbed(true);
>>>>>>> Stashed changes
	// Initialize GLEW
	glewExperimental = GL_TRUE;
	glewInit();
	glViewport(0, 0, window.getWindowSize().x, window.getWindowSize().y);
	glEnable(GL_DEPTH_TEST);

	// Reset clock
	clock.restart();

	// Initialize shape
	shape = new Triangle(this, shader);

	shader = new Shader("VertexSource.glsl", "FragmentSource.glsl");
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
	
	// Clear the colorbuffer
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Activate container
	shader->Use();

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
