#include "Texture.h"

using namespace GaltE;

Texture::Texture()
{

}

bool Texture::loadFromFile(const std::string &filename)
{
	if (!texture.loadFromFile(filename))
	{
		std::cerr << "Failed to load file ''" << filename << "'' to create the texture!\n";
		return false;
	}
	return true;
}

bool Texture::create(unsigned width, unsigned height)
{
	if (!texture.create(width, height))
	{
		std::cerr << "Failed to create a texture with " << width << " width and " << height << " height!";
		return false;
	}
	return true;
}

void Texture::setSmooth(bool smooth)
{
	texture.setSmooth(smooth);
}

sf::Texture Texture::getSFTexture()
{
	return texture; 
}