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
*the following information: the texture id, position
*(x,y) coordinates and size (width, height) of the
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
	double xPos;
	double yPos;
	double width;
	double height;
	//read infromation, create new sprite
	while (!spriteFile.eof())
	{
		spriteFile >> textureID;
		spriteFile >> xPos;
		spriteFile >> yPos;
		spriteFile >> width;
		spriteFile >> height;

		//create sprite and push it to the list
		Sprite tempSprite(xPos, yPos, width, height, textureManager.findTexture(textureID));
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