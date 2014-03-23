#include "TextureManager.h"

using namespace GaltEngine;


TextureManager::TextureManager(std::string textureFiles)
{
	if (!readFile(textureFiles))
	{
		std::cerr << "Error reading from texture file!\n";
	}
}

bool TextureManager::readFile(std::string textureFiles)
{
	ifstream file;
	file.open(textureFiles);

	if (!file)
	{
		std::cerr << "Couldn't open texture files!\n";
		return false;
	}

	//read each texture and push to the vector
	std::string textureFile;
	while (!file.eof())
	{
		file >> textureFile;

		sf::Texture tempTexture;
		if (!tempTexture.loadFromFile(textureFile))
		{
			std::cerr << "Texture file " << textureFile << " couldn't be found!\n";
		}
		textures.push_back(tempTexture);
	}
	return true;
}

/***
*Texture ID is given by the position in the vector plus
*1. Thus the texture ID with the value of 1, is the first
*Texture read in the file
***/
sf::Texture& TextureManager::findTexture(int textureID)
{
	if (textureID > textures.size())
	{
		std::cerr << "Texture ID out of bounds!\n";
		return textures[0];
	}
	return textures[textureID - 1];
}