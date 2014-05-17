#ifndef CAMERA_H
#define CAMERA_H

#include "Main.h"

namespace GaltE
{
	/**
	* The camera class is used to set a view within the window (thus what the user sees will be what the view is)
	* Will have the ability to zoom in and out and rotate. 
	* The view will also have the ability to move
	*/
	class Camera
	{
	private:
		sf::View view;

	public:
		/**
		* Constructor using a rectangle to describe the camera view. Thus, the first 
		* two coordinates are the global top left x and y positions of the camera.
		* The next to values in the sf::FloatRect describe the width and height
		**/
		Camera(sf::FloatRect rect);

		/**
		* Constructor using two vectors to describe the camera's view, the first 
		* being the camera's center global coordinates, the second being the size
		* of the camera
		*/
		Camera(sf::Vector2f center, sf::Vector2f size)
		{
			view.setCenter(center);
			view.setSize(size);
		}

		/**
		* A defualt constructor, where the camera has zero size and center at the origin
		*/
		Camera()
		{

		}

		/**
		* Method sets the view of the camera using a rectangle to describe its top left position
		* and size
		*/
		void setView(sf::FloatRect rect);
	};
}

#endif