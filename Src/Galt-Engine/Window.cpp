#include "Window.h"

using namespace GaltE;

Window::Window(std::string fileName)
{
	if (!loadConfig(fileName))
	{
		std::cerr << "Failed to load configurations for new window!" << std::endl;
		return;
	}
	createWin();
}

Window::Window(int width, int height, bool fullscreen, std::string name)
{
	winWidth = width;
	winHeight = height;
	std::string winName = name;
	open = true;
	winFullScreen = fullscreen;
	
	//set default background color
	color = sf::Color::Black;
	
	createWin();
}

bool Window::loadConfig(std::string fileName)
{
	std::ifstream file;
	file.open(fileName);

	if (!file)
	{
		return false;
	}

	file >> winWidth;
	file >> winHeight;
	file >> winName;
	file >> winFullScreen;

	return true;

}

void Window::exit()
{
	std::cout << "Closing!\n";
	open = false;
	window.close();
}

void Window::createWin()
{
	if (winFullScreen)
	{
		window.create(sf::VideoMode(winWidth, winHeight), winName, sf::Style::Fullscreen);
	}
	else
	{
		window.create(sf::VideoMode(winWidth, winHeight), winName);
	}
}

void Window::setColor(sf::Color mColor)
{
	color = mColor;
}

void Window::clear()
{
	window.clear(color);
}

void Window::display()
{
	window.display();
}

bool Window::pollEvent()
{
	return window.pollEvent(winEvent);
}