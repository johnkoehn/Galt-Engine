#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>

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

	public:
		Engine(int fwidth = 800, int fheight = 600, std::string ftitle = "Default") : window(sf::VideoMode(fwidth, fheight), ftitle)
		{
			winWidth = fwidth;
			winHeight = fheight;
			winTitle = ftitle;
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