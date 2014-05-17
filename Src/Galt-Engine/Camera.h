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
		Camera(const sf::FloatRect& rect);

		/**
		* Constructor using two vectors to describe the camera's view, the first 
		* being the camera's center global coordinates, the second being the size
		* of the camera
		*/
		Camera(const sf::Vector2f& center, const sf::Vector2f& size);

		/**
		* A defualt constructor, where the camera has zero size and center at the origin
		*/
		Camera();

		/**
		* Method sets the view of the camera using a rectangle to describe its top left position
		* and size
		*/
		void setView(const sf::FloatRect& rect);

		/**
		* Set the center of the camera's view using global cooridnates
		*/
		void setCenter(const sf::Vector2f& coordinates);

		/**
		* Set the size of the camera's view
		*/
		void setSize(const sf::Vector2f& size);

		/**
		* Rotate the view of the camera in degrees. Note, this sets the rotation,
		* so using this method will always set the rotation relative to 0 degrees
		*/
		void setRotation(float angle);

		/**
		* rotate the view relative to the current orientation
		*/
		void rotate(float angle);

		/**
		* Move the camera based on its current location
		*/
		void move(float deltaX, float deltaY);

		/**
		* Method sets the view to part of the window. Thus the first
		* value of the floatRect is the amount of offset from the right side of the screen
		* second is the amount of offset from the left side of the screen
		* the third is the amount of the x view it will show, the fourth is the amount of y view it will show
		* These values must be from 0 to 1
		*/
		void setViewport(sf::FloatRect& rect);

		/**
		* Method takes a factor to zoom the screen out by. Thus a factor of less then 1
		* zooms out, greater zooms in
		*/
		void zoom(float factor);
	};
}

#endif