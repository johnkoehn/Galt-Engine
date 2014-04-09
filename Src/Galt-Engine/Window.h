#ifndef WINDOW_H
#define WINDOW_H

#include "Main.h"

namespace GaltE
{
	/**
	* Class is used for running the game window
	* contains all the various configuration options,
	* such as if the window should be fullscreen, size, etc
	* also deals with getting events and keeping track of when to 
	* exit
	*/
	class Window
	{
	private:
		int winWidth;
		int winHeight;
		bool fullscreen;
		bool quit;
		sf::RenderWindow window;
		sf::Event event;

	public:
		/**
		* Constructor for reading the infromation from a file
		*/
		Window(std::string fileName);
		
		/**
		* Constructor with basic information
		*/
		Window(int width, int height, bool fullscreen, std::string title);

		/**
		*Constructors and Mutators
		*/
		int getWidth() { return winWidth;  }
		int getHeight() { return winHeight; }
		void setFullScreen() { fullscreen = true; }
		void quite() { quit = true;  }

	};
}


#endif