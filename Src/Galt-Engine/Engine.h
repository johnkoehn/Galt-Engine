#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Sprite.h"
#include "Map.h"
#include "SpriteManager.h"
#include <fstream>

using std::ifstream;

namespace GaltEngine
{
	class Engine
	{
	private:
		int winWidth;
		int winHeight;
		sf::RenderWindow window;
		std::string winTitle;
		sf::Event event;

		//object containg the level map
		Map map;
		int tileWidth;
		int tileHeight;

		//object to manage the sprites and textures
		SpriteManager sManager;

		bool createMap(std::string mapFile, std::string tileFile);
		bool readLevel(std::string mapFile, std::vector<int>& level);
		void checkKeyInput();

	public:

		//TODO make a text file containing the information for the other text files!
		Engine(int fwidth = 800, int fheight = 600, std::string ftitle = "Default", std::string mapFile = "default.txt", int ftileWidth = 32, int ftileHeight = 32, std::string tileFile = "tileset1.png", std::string texturesFile = "textures.txt", std::string spritesFile = "sprites.txt");
		~Engine();

		//mutators/accessors
		int getWidth();
		int getHeight();
		std::string getTitle();

		void runGame();
	};
}

#endif