#include "Engine.h"
using namespace GaltEngine;
using std::vector;

//TODO make a text file containing the information for the other text files!
Engine::Engine(int fwidth, int fheight, std::string ftitle, std::string mapFile, int ftileWidth, int ftileHeight, std::string tileFile, std::string texturesFile, std::string spritesFile) : window(sf::VideoMode(fwidth, fheight), ftitle), sManager(spritesFile, texturesFile)
{
	winWidth = fwidth;
	winHeight = fheight;
	winTitle = ftitle;

	//create map
	if (!createMap(mapFile, tileFile, ftileHeight, ftileWidth))
	{
		std::cerr << "Failed to create map, Abort!\n";
	}

	//create the view based off player's position
	setView();
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
		
		//check for new window events that occurred since the last loop iteration
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

		//set the view 
		window.setView(playerView);

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

bool Engine::createMap(std::string mapFile, std::string tileFile, int tileHeight, int tileWidth)
{
	//initilize the map
	map.mapSet(tileFile, mapFile, tileHeight, tileWidth);

	//have the map read the level
	if (!map.readLevel())
	{
		std::cerr << "Invaild file!\n";
		return false;
	}

	//now create the map
	map.load();

	return true;
}

/****************************************************
*Keyboard input can only move the player in the Engine
*Player is always repersented by the first sprite
*Scroll with the player
*****************************************************/
void Engine::checkKeyInput()
{
	double changePos = playerMoveSpeed * timeDelta;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//move player up
		sManager.updatePosition(1, 0, -(changePos));
		scroll(0, -changePos);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		//move player down
		sManager.updatePosition(1, 0, (changePos));
		scroll(0, changePos);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		//move player right
		sManager.updatePosition(1, changePos, 0);
		scroll(changePos, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		//move player left
		sManager.updatePosition(1, -(changePos), 0);
		scroll(-changePos, 0);
	}
}

void Engine::setView()
{
	//get the player1 sprite for the location to center the view on
	Sprite* playerSprite = sManager.getSprite(1);

	//initialize the view
	playerView.setCenter(sf::Vector2f(playerSprite->getX(), playerSprite->getY()));
	playerView.setSize(sf::Vector2f(winWidth, winHeight));
}

void Engine::scroll(double deltaX, double deltaY)
{
	playerView.move(deltaX, deltaY);
}