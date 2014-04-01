#include "Camera.h"
using namespace GaltEngine;

Camera::Camera(double fxCenter, double fyCenter, double fcameraWidth, double fcameraHeight)
{
	xCenter = fxCenter;
	yCenter = fyCenter;
	cameraWidth = fcameraWidth;
	cameraHeight = fcameraHeight;

	view.setCenter(sf::Vector2f(xCenter, yCenter));
	view.setSize(sf::Vector2f(cameraWidth, cameraHeight));
}

//An empty iniliazation
Camera::Camera()
{
	xCenter = 0;
	yCenter = 0;
	cameraWidth = 0;
	cameraHeight = 0;

	view.setCenter(sf::Vector2f(xCenter, yCenter));
	view.setSize(sf::Vector2f(cameraWidth, cameraHeight));
}

void Camera::setView(double fxCenter, double fyCenter, double fcameraWidth, double fcameraHeight)
{
	xCenter = fxCenter;
	yCenter = fyCenter;
	cameraWidth = fcameraWidth;
	cameraHeight = fcameraHeight;

	view.setCenter(sf::Vector2f(xCenter, yCenter));
	view.setSize(sf::Vector2f(cameraWidth, cameraHeight));
}
void Camera::move(double deltaX, double deltaY)
{
	xCenter += deltaX;
	yCenter += deltaY;

	view.move(deltaX, deltaY);
}

double Camera::getX()
{
	return xCenter;
}

double Camera::getY()
{
	return yCenter;
}