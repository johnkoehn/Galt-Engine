#ifndef VECTOR2I_H
#define VECTOR2I_H

#include "main.h"

namespace GaltE
{
	/**
	* Class contains an x and y integer value, can return a sf::vector2i also
	*/
	class Vector2i
	{
	private:
		int x, y;

	public:
		/**
		* Returns the x value
		*/
		int x();

		/**
		* Returns the y value
		*/
		int y();

		/**
		* Returns an sf::vector2i
		*/
		sf::Vector2i getSFMLVec();
	};
}

#endif