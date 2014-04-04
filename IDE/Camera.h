<<<<<<< HEAD
#ifndef CAMERA_H
#define CAMERA_H
=======
#ifndef MAP_H
#define MAP_H
>>>>>>> 4a21d6aa2ece5d2edf1e3381d4fb643a19d3b998

#include <SFML/Graphics.hpp>

namespace GaltEngine
{
<<<<<<< HEAD
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

=======
	/***********
	*This class is the base class for the camera view.
	*Other classes can be drived from this class for a more controlled
	*and unquie camera view, such as a spriteCamera which tracks
	*a sprite
	*/
	class Camera
	{
	private:
		double xCenter;
		double yCenter;
		double cameraWidth;
		double cameraHeight;
		sf::View view;

	public:
		Camera(double fxCenter, double fyCenter, double fcameraWidth, double fcameraHeight);
		Camera();
		void setView(double fxCenter, double fyCenter, double fcameraWidth, double fcameraHeight);
		void move(double deltaX, double deltaY);
		double getX();
		double getY();
	};
}
>>>>>>> 4a21d6aa2ece5d2edf1e3381d4fb643a19d3b998
#endif