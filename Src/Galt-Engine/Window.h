#ifndef WINDOW_H
#define WINDOW_H

#include "Main.h"
#include "Camera.h"

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
		bool open;
		bool winFullScreen;
		std::string winName;
		sf::RenderWindow window;
		sf::Event winEvent;
		sf::Color color;

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
		* Method causes the window to close, and sets open to false
		*/
		void exit();

		/**
		* Method returns a pointer of winEvent
		*/
		sf::Event* getEvent()	{ return &winEvent;	}

		/**
		* Method sets a color for the screen
		*/
		void setColor(sf::Color color);

		/**
		* Method clears the screen for preperation for the next frame
		*/
		void clear();

		/**
		* Method displays the new frame
		*/
		void display();

		/**
		* Method polls for a window event
		*/
		bool pollEvent();

		/**
		* Sets the window to use the camera
		*/
		void setCamera(Camera& camera);

		/**
		* Draws a Drawable object to the window
		*/
		void draw(const sf::Drawable& drawable);

		/**
		*Basic
		*/
		int getWidth()			{ return winWidth;  }
		int getHeight()			{ return winHeight; }
		std::string getName()	{ return winName;   }
		bool isOpen()			{ return open;      }
		

	};
}


#endif