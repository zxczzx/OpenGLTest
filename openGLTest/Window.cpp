#include "Window.h"

Window::Window()
{
	setup("Window", sf::Vector2u(640, 480));
}

Window::Window(const std::string & title, const sf::Vector2u & size)
{
	setup(title, size);
}

Window::~Window()
{
	destroy();
}

void Window::beginDraw()
{
	window.clear(sf::Color::Black);
}

void Window::endDraw()
{
	window.display();
}

void Window::update()
{
	if (event.type == sf::Event::Closed) {
		isdone = true;
	}
	else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
		isdone = true;
	}
}

bool Window::isDone()
{
	return isdone;
}

bool Window::isFullscreen()
{
	return isfullscreen;
}

sf::Vector2u Window::getWindowSize()
{
	return windowSize;
}

sf::RenderWindow* Window::getRenderWindow()
{
	return &window;
}

void Window::toggleFullscreen()
{
	isfullscreen = !isfullscreen;
	destroy();
	create();
}

void Window::draw(sf::Drawable & drawable)
{
	window.draw(drawable);
}

void Window::setup(const std::string & title, const sf::Vector2u & size)
{
	windowTitle = title;
	windowSize = size;
	isfullscreen = false;
	isdone = false;
	create();
}

void Window::destroy()
{
	window.close();
}

void Window::create()
{
	auto style = (isfullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	window.create({ windowSize.x, windowSize.y, 32 }, windowTitle, style);
}
