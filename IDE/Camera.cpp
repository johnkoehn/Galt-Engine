#include "Camera.h"
using namespace GaltEngine;

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
}