#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>

namespace GaltEngine
{
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
	};
}
#endif