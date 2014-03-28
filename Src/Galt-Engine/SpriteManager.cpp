#include "SpriteManager.h"

using namespace GaltEngine;

SpriteManager::SpriteManager(std::string filename, std::string texturesFile) : textureManager(texturesFile)
{
	if (!readFile(filename))
	{
		std::cerr << "Error initalizing sprite class";
	}
}

/*****************************************************
*Text file contains the sprite information. Cotains
*the following information: the texture id, sprite ID,
*position(x,y) coordinates and size (width, height) of the
*sprite
******************************************************/

bool SpriteManager::readFile(std::string filename)
{
	//open the file
	ifstream spriteFile;

	spriteFile.open(filename);
	//check for valid file
	if (!spriteFile)
	{
		std::cerr << "Invalid file for sprites!\n";
		return false;
	}

	int textureID;
	int spriteID;
	double xPos;
	double yPos;
	double width;
	double height;
	//read infromation, create new sprite
	while (!spriteFile.eof())
	{
		spriteFile >> textureID;
		spriteFile >> spriteID;
		spriteFile >> xPos;
		spriteFile >> yPos;
		spriteFile >> width;
		spriteFile >> height;

		//create sprite and push it to the list
		Sprite tempSprite(xPos, yPos, width, height, textureManager.findTexture(textureID), spriteID);
		sprites.push_back(tempSprite);
	}
	return true;
}

void SpriteManager::add(Sprite newSprite)
{
	sprites.push_back(newSprite);
}

void SpriteManager::displaySprites(sf::RenderWindow& window)
{
	list<Sprite>::iterator i;

	//loop through sprites and display each sprite
	for (i = sprites.begin(); i != sprites.end(); ++i)
	{
		window.draw((*i).getSprite());
	}
}

void SpriteManager::updatePosition(int spriteID, double deltaX, double deltaY)
{
	list<Sprite>::iterator i;

	//find the sprite
	for (i = sprites.begin(); i != sprites.end(); ++i)
	{
		if (spriteID == (*i).getID())
		{
			(*i).updatePosition(deltaX, deltaY);
			break;
		}
	}

}

Sprite* SpriteManager::getSprite(int spriteID)
{
	//create a pointer to a Sprite
	Sprite* tempSprite;

	list<Sprite>::iterator i;

	//find the sprite
	for (i = sprites.begin(); i != sprites.end(); ++i)
	{
		if (spriteID == (*i).getID())
		{
			tempSprite = &(*i);
			return tempSprite;
		}
	}

	std::cerr << "No sprited with ID: " << spriteID;
	return NULL;
}

//function iteriates throught the list and returns the address to the sprite
/*sf::Sprite SpriteManager::findSprite(int spriteID)
{
	list<Sprite>::iterator i;

	for (i = sprites.begin(); i != sprites.end(); ++i)
	{
		if (spriteID == (*i).getID())
		{
			return *i;
		}
	}
} */