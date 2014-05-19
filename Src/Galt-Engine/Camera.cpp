#include "Camera.h"

using namespace GaltE;

Camera::Camera(const sf::FloatRect& rect)
{
	view.reset(rect);
}

Camera::Camera(const sf::Vector2f& center, const sf::Vector2f& size)
{
	view.setCenter(center);
	view.setSize(size);
}

Camera::Camera()
{

}

void Camera::setView(const sf::FloatRect& rect)
{
	view.reset(rect);
}

void Camera::setCenter(const sf::Vector2f& coordinates)
{
	view.setCenter(coordinates);
}

void Camera::setSize(const sf::Vector2f& size)
{
	view.setSize(size);
}

void Camera::setRotation(float angle)
{
	view.setRotation(angle);
}

void Camera::rotate(float angle)
{
	view.rotate(angle);
}

void Camera::move(float deltaX, float deltaY)
{
	view.move(deltaX, deltaY);
}

void Camera::setViewport(sf::FloatRect& rect)
{
	//test to make sure all componenets are between 1 and 0 inclusive
	if (!(rect.left <= 1) || !(rect.left >= 0))
	{
		rect.left = 0;
		std::cerr << "View port left value greater then 1 or less then 0\n";
	}
	
	if (!(rect.top <= 1) || !(rect.top >= 0))
	{
		rect.top = 0;
		std::cerr << "View port top value greater then 1 or less then 0\n";
	}
	
	if (!(rect.width <= 1) || !(rect.width >= 0))
	{
		rect.width = 1;
		std::cerr << "View port width value greater then 1 or less then 0\n";
	}
	
	if (!(rect.height <= 1) || !(rect.height >= 0))
	{
		rect.height = 1;
		std::cerr << "View port width value greater then 1 or less then 0\n";
	}

	view.setViewport(rect);
}

void Camera::zoom(float factor)
{
	view.zoom(factor);
}