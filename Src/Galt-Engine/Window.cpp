#include "Window.h";

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
	quit = false;
	winFullScreen = fullscreen;
	
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

}

void Window::exit()
{
	quit = false;
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