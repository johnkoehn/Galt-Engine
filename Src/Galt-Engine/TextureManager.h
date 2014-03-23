#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

using std::ifstream;
using std::vector;

namespace GaltEngine
{
	class TextureManager
	{
	private:
		vector<sf::Texture> textures;

		bool readFile(std::string textureFile);

	public:
		TextureManager(std::string textureFiles);
		void addTexture(std::string textureName);
		sf::Texture& findTexture(int textureID);

	};
}



#endif