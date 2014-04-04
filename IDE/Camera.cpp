#include "Camera.h"
using namespace GaltEngine;

<<<<<<< HEAD
Camera::Camera()
{
	xPos = 0;
	yPos = 0;
	width = 0;
	height = 0;
}

Camera::Camera(double xPos, double yPos, double cameraWidth, double cameraHeight)
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->width = cameraWidth;
	this->height = cameraHeight;

	view.setCenter(sf::Vector2f(xPos, yPos));
	view.setSize(sf::Vector2f(width, height));
}

void Camera::move(double deltaX, double deltaY)
{
	xPos += deltaX;
	yPos += deltaY;
	view.move(deltaX, deltaY);
=======
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
>>>>>>> 4a21d6aa2ece5d2edf1e3381d4fb643a19d3b998
}