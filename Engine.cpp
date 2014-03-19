#include "SFML_STATIC.h"
#include "Engine.h"
using namespace GaltEngine;
using std::vector;

Engine::~Engine()
{

}

int Engine::getWidth()
{
	return winWidth;
}

int Engine::getHeight()
{
	return winHeight;
}

std::string Engine::getTitle()
{
	return winTitle;
}

void Engine::runGame()
{
	//loop runs constantly
	while (window.isOpen())
	{
		
		//check for new window events that occured since the last loop iteration
		if (window.pollEvent(event))
		{
			//if a close requested event occurs, close the window
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//clear the window and prep for new frame
		window.clear(sf::Color::Green);

		//update the sprites

		//now draw sprites
		window.draw(sprites[0]);

		//start the new frame
		window.display();
	}
}