#ifndef MOUSE_H
#define MOUSE_H

#include "Main.h"

namespace GaltE
{
	/**
	* Enum of differnet mouse buttons
	*/
	enum  MouseButtons {
		Left,
		Right,
		Middle,
		XButton1,
		XButton2,
		None
	}

	/**
	* Class gets input from the mouse, 
	* like SFML Mouse, it is static
	*/
	class Mouse
	{
	public:
		/**
		* Checks if a mouse button is being pressed
		*/
		static bool isButtonPressed(MouseButtons button);

		/**
		* Returns the position of the mouse in desktop coordinates
		*/
		//TODO Add a basic point vector
		//static Vector2i getPositon();

		/**
		* Returns the position of mouse in the window coordinates
		*/
		//static Vector2i getPoisiton(const Window &window);

		/**
		* Sets the position of the mouse in desktop coordinates
		*/
		//static void setPosition(const Vector2i &position);

		/**
		* Sets the poitions of the mouse in window coordinates
		*/
		//static void setPosition(const Vector2i &position, const Window &window);
	};
}

#endif