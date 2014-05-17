#include "Camera.h"

using namespace GaltE;

Camera::Camera(sf::FloatRect rect)
{
	view.reset(rect);
}

Camera::Camera(sf::Vector2f center, sf::Vector2f size)
{
	view.setCenter(center);
	view.setSize(size);
}

Camera::Camera()
{

}

void Camera::setView(sf::FloatRect rect)
{
	view.reset(rect);
}