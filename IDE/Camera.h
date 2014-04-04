#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>

namespace GaltEngine
{
	/***
	*Generic camera class
	***/
	class Camera
	{
	private:
		double xPos;
		double yPos;
		double width;
		double height;
		sf::View view;

	public:
		Camera();
		Camera(double xPos, double yPos, double cameraWidth, double cameraHeight);
		void set(double xPos, double yPos, double cameraWidth, double cameraHeight);
		void move(double deltaX, double deltaY);

		double getX() { return xPos; }
		double getY() { return yPos; }
		double getWidth() { return width; }
		double getHeight() { return height; }
	};
}

#endif