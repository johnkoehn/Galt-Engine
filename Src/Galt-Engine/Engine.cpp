#include "Engine.h"
using namespace GaltEngine;
using std::vector;

//TODO make a text file containing the information for the other text files!
Engine::Engine(int fwidth, int fheight, std::string ftitle, std::string mapFile, int ftileWidth, int ftileHeight, std::string tileFile, std::string texturesFile, std::string spritesFile) : window(sf::VideoMode(fwidth, fheight), ftitle), sManager(spritesFile, texturesFile)
{
	winWidth = fwidth;
	winHeight = fheight;
	winTitle = ftitle;
	tileWidth = ftileWidth;
	tileHeight = ftileHeight;

	//create map
	if (!createMap(mapFile, tileFile))
	{
		std::cerr << "Failed to create map, Abort!\n";
	}
};

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

		//calculate time delta
		elapsed = clock.restart();
		timeDelta = elapsed.asSeconds();

		//update the sprites
		checkKeyInput();
		
		//disable window to be passed to another thread
		window.setActive(false);

		//now draw sprites
		sManager.displaySprites(window);

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
	int mapWidth = 30; //winWidth / tileWidth;
	int mapHeight = 30; // winHeight / tileHeight;

	//now create the map
	map.load(tileFile, sf::Vector2u(tileWidth, tileHeight), level, mapWidth, mapHeight);

	return true;
}

bool Engine::readLevel(std::string mapFile, std::vector<int>& level)
{
	ifstream indata;
	indata.open(mapFile);

	//to avoid the vector constantly resizing will set a capacity
	int capacity = 500;
	level.resize(capacity);

	if (!indata)
	{
		return false;
	}

	//read the text file for all the integers
	int readInt;
	int i = 0;
	while (!indata.eof())
	{
		indata >> readInt;
		level[i] = readInt;

		i += 1;
		if (!(i < capacity))
		{
			capacity += 250;
			level.resize(capacity);
		}
	}

	indata.close();
	return true;
}

/****************************************************
*Keyboard input can only move the player in the Engine
*Player is always repersented by the first sprite
*****************************************************/
void Engine::checkKeyInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//move player up
		sManager.updatePosition(1, 0, -(playerMoveSpeed * timeDelta));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		//move player down
		sManager.updatePosition(1, 0, (playerMoveSpeed * timeDelta));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		//move player right
		sManager.updatePosition(1, playerMoveSpeed* timeDelta, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		//move player left
		sManager.updatePosition(1, -(playerMoveSpeed * timeDelta), 0);
	}
}