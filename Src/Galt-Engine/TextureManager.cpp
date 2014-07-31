#include "TextureManager.h"

using namespace GaltE;

TextureManager::TextureManager()
{

}

bool TextureManager::readFile(std::string fileName)
{
	std::ifstream file;
	file.open(fileName);

	if (!file)
	{
		std::cerr << "Failed to open texture file list named " << fileName;
		return false;
	}

	//read each texture and push to the vector
	std::string textureFile;
	while (!file.eof())
	{
		file >> textureFile;

		addTexture(textureFile);
	}
	return true;
}

bool TextureManager::addTexture(std::string textureFile)
{
	Texture tempTexture;
	if (!tempTexture.loadFromFile(textureFile))
	{
		std::cerr << "Texture file " << textureFile << " couldn't be found!\n";
		return false;
	}
	textures.push_back(tempTexture);

	return true;
}

Texture& TextureManager::getTexture(int textureID)
{
	return textures[textureID - 1];
}