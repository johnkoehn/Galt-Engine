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
		double const playerMoveSpeed = 20.0; //will change this to be set in a text file or will have sprites be able to have a speed value

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

		//Objects used to calculate the time between each frame
		sf::Clock clock;
		sf::Time elapsed;
		double timeDelta;

		//object used for centering the player's view and scrolling
		sf::View playerView; //TODO Prehapes create a player class?

		bool createMap(std::string mapFile, std::string tileFile);
		bool readLevel(std::string mapFile, std::vector<int>& level);
		void checkKeyInput();
		void setView();
		void scroll(double deltaX, double deltaY);

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