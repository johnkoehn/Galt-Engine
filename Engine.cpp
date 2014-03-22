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

bool Engine::createMap(std::string mapFile, std::string tileFile)
{
	//create a vector to hold the integers representing the map
	std::vector<int> level;

	if (!readLevel(mapFile, level))
	{
		std::cerr << "Invaild file!\n";
		return false;
	}

	//caclulate the map width and height in tiles (I'll figure this out later)
	int mapWidth = 23; //winWidth / tileWidth;
	int mapHeight = 16; // winHeight / tileHeight;

	//now create the map
	map.load(tileFile, sf::Vector2u(tileWidth, tileHeight), level, mapWidth, mapHeight);

	return true;
}

bool Engine::readLevel(std::string mapFile, std::vector<int>& level)
{
	ifstream indata;
	indata.open(mapFile);

	if (!indata)
	{
		return false;
	}

	//read the text file for all the integers
	int readInt;
	while (!indata.eof())
	{
		indata >> readInt;
		level.push_back(readInt);
	}

	indata.close();
	return true;
}