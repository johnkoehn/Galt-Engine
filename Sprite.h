#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>
#include <iostream>

namespace GaltEngine
{
	class Sprite
	{
	private:
		//sprite information
		double xPos;
		double yPos;
		double width;
		double height;

		//sprite object for sfml
		sf::Sprite sprite;

		/*** 
		*IMPORTANT SELFNOTE
		*currently, no way to have an animated sprite exisit
		*to do this, we will need to overhaul the way we deal with textures
		*remeber this for future refernece
		***/

	public:
		Sprite(double fxPos, double fyPos, double fwidth, double fheight, const sf::Texture &texture);
		~Sprite();

		//mutators & accessors
		double getX();
		double getY();
		double getWidth();
		double getHeight();
		sf::Sprite& getSprite();
		void updatePosition(double changeX, double changeY);
		void newPosition(double newX, double newY);
		void newX(double newX);
		void newY(double newY);


	};
}

#endif SPRITE_H