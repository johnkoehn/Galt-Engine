#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <iostream>

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

		//vector containing the various textures (data will eventually be moved into a different class)
		std::vector<sf::Texture> textures; 

		//vector containg all the sprite (data will eventually be moved into a different class)
		std::vector<sf::Sprite> sprites;

	public:
		Engine(int fwidth = 800, int fheight = 600, std::string ftitle = "Default") : window(sf::VideoMode(fwidth, fheight), ftitle)
		{
			winWidth = fwidth;
			winHeight = fheight;
			winTitle = ftitle;

			//sprite testing
			sf::Texture newTexture;
			if (!newTexture.loadFromFile("sprite1.png"))
			{
				std::cerr << "Failed to load texture\n";
				return;
			}
			textures.push_back(newTexture);

			//now we can create the sprite
			sf::Sprite newSprite;
			newSprite.setTexture(textures[0]);
			sprites.push_back(newSprite);
		};
		~Engine();

		//mutators/accessors
		int getWidth();
		int getHeight();
		std::string getTitle();

		void runGame();
	};
}

#endif