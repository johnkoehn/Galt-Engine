#include "Engine.h"
using namespace GaltEngine;
using std::vector;

//TODO make a text file containing the information for the other text files!
Engine::Engine(int fwidth, int fheight, std::string ftitle, std::string mapFile, int ftileWidth, int ftileHeight, std::string tileFile, std::string texturesFile, std::string spritesFile, bool fborderCollision) : window(sf::VideoMode(fwidth, fheight), ftitle), sManager(spritesFile, texturesFile)
{
	winWidth = fwidth;
	winHeight = fheight;
	winTitle = ftitle;
	borderCollision = fborderCollision;
	atXBorder = false;

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
	//initialize the map
	map.mapSet(tileFile, mapFile, tileHeight, tileWidth);

	//have the map read the level
	if (!map.readLevel())
	{
		std::cerr << "Invalid file!\n";
		return false;
	}

	//now create the map
	map.load();

	return true;
}

/****************************************************
*Keyboard input can only move the player in the Engine
*Player is always represented by the first sprite
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

	//need to find the center location of the sprite
	double xCenter = playerSprite->getWidth() / 2;
	double yCenter = playerSprite->getHeight() / 2;

	//now find the (x,y) position of the center of the sprite
	double xPos = playerSprite->getX() + xCenter;
	double yPos = playerSprite->getY() + yCenter;

	//initialize the view
	playerView.setCenter(sf::Vector2f(xPos, yPos));
	playerView.setSize(sf::Vector2f(winWidth, winHeight));
}

void Engine::scroll(double deltaX, double deltaY)
{
	if (borderCollision)
	{
		if (!checkBorderCollision(deltaX, deltaY))
		{
			playerView.move(deltaX, deltaY);
		}
	}
	//playerView.move(deltaX, deltaY);
}

/**
*Functions checks if the camera's view has collided with the border
*if so, the function returns true, otherwise it returns false
*/
bool Engine::checkBorderCollision(double deltaX, double deltaY)
{
	sf::Vector2f centerLocation = playerView.getCenter();

	//check if collision testing is done in the x or y
	if (deltaX > 0 || deltaX < 0)
	{
		//see if the view collides with the edge of the map with the add on of the deltaX
		int cameraXExtrusion = centerLocation.x + (winWidth / 2 + .5) + deltaX;

		std::cout << "Camera Extrusion: " << cameraXExtrusion << "\n";
		if (cameraXExtrusion - winWidth < 0 || cameraXExtrusion > map.getMapWidth())
		{
			std::cout << "At boarder!\n";
			//now see if the camera extrusion is at the border (if not put it there)
			if (!(cameraXExtrusion - deltaX == 0) && !atXBorder)
			{
				//figure how to make it more precise
				atXBorder = true;
			}
			return true;
		}

		if (cameraXExtrusion > map.getMapWidth())
		{
			if (!(cameraXExtrusion - deltaX == map.getMapWidth()))
			{
				double difference = map.getMapWidth() - winWidth - cameraXExtrusion;
				std::cout << difference << "\n";
				playerView.move(difference, 0);
			}
			return true;
		}
		return false;
	}
	else
	{
		return false;
	}

}