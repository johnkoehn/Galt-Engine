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
	/***
	*TEST CODE
	***/
	const int level[] =
	{
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
	};

	Map map;
	if (!map.load("tileset1.png", sf::Vector2u(32, 32), level, 16, 8))
		return;

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
		window.clear(sf::Color::Blue);

		//draw the map
		window.draw(map);

		//update the sprites
		sprites[0].newPosition(30, 40);

		//now draw sprites
		window.draw(sprites[0].getSprite());


		//start the new frame
		window.display();
	}
}