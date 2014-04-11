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
		bool quit;
		bool winFullScreen;
		std::string winName;
		sf::RenderWindow window;

		/**
		* Method loads the window configurations from a file
		*/
		bool loadConfig(std::string fileName);

		/**
		* Method initilaizes the window
		*/
		void createWin();
	public:
		/**
		* Constructor for reading the infromation from a file
		*/
		Window(std::string fileName);
		
		/**
		* Constructor with basic information
		*/
		Window(int width, int height, bool fullscreen, std::string name);

		/**
		*Constructors and Mutators
		*/
		int getWidth() { return winWidth;  }
		int getHeight() { return winHeight; }
		std::string getName() { return winName; }
		//void setFullScreen();
		void exit();

	};
}


#endif