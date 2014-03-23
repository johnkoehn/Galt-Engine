#include "Sprite.h"
using namespace GaltEngine;

Sprite::Sprite(double fxPos, double fyPos, double fwidth, double fheight, const sf::Texture &texture)
{
	xPos = fxPos;
	yPos = fyPos;
	width = fwidth;
	height = fheight;

	//set the sprite with the new texture
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(xPos, yPos));
}

Sprite::~Sprite()
{

}

/***
*MUTATORS/ACCESSORS
***/
double Sprite::getX()
{
	return xPos;
}

double Sprite::getY()
{
	return yPos;
}

double Sprite::getWidth()
{
	return width;
}

double Sprite::getHeight()
{
	return height;
}

sf::Sprite& Sprite::getSprite()
{
	return sprite;
}

void Sprite::updatePosition(double changeX, double changeY)
{
	xPos += changeX;
	yPos += changeY;

	//move the spirte
	sprite.move(sf::Vector2f(changeX, changeY));
}

void Sprite::newPosition(double newX, double newY)
{
	xPos = newX;
	yPos = newY;

	//update the position
	sprite.setPosition(sf::Vector2f(xPos, yPos));
}

void Sprite::newX(double newX)
{
	xPos = newX;

	//update the position
	sprite.setPosition(sf::Vector2f(xPos, yPos));
}

void Sprite::newY(double newY)
{
	yPos = newY;

	//update the position
	sprite.setPosition(sf::Vector2f(xPos, yPos));
}