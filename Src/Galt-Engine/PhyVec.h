#ifndef PHYVEC_H
#define PHYVEC_H

#include "Main.h"

namespace GaltE
{
	template<class Type>
	/**
	* Class represents a vector in the context of physics
	*/
	class PhyVec
	{
	public:
		/**
		* This is a Dan recommandation and I agree with it
		*/
		Type x;
		Type y;

		/**
		* Give the xCoordinate and yCoordinate
		*/
		PhyVec(Type xCoordinate, Type yCoordinate)
		{
			x = xCoordinate;
			y = yCoordinate;
		}

		/**
		* Default Constructor, sets x and y to zero
		*/
		PhyVec()
		{
			x = 0;
			y = 0;
		}

		~PhyVec()
		{

		}

		/**
		* Change x and y value by an amount
		*/
		void updatePos(Type deltaX, Type deltaY)
		{
			x += deltaX;
			y += deltaY;
		}

		/**
		* Change x value by an amount
		*/
		void updateX(Type deltaX)
		{
			x += deltaX;
		}

		/**
		* Change y value by an amount
		*/
		void updateY(Type deltaY)
		{
			y += deltaY;
		}

		/**
		* Set x and y value
		*/
		void setPos(Type newX, Type newY)
		{
			x = newX;
			y = newY;
		}

		/**
		* Set x value
		*/
		void setX(Type newX)
		{
			x = newX;
		}

		/**
		* set y value
		*/
		void setY(Type setY)
		{
			y = setY;
		}

		/**
		* get the magnitude of the vector
		*/
		Type magnitude() const
		{
			return (Type)sqrt((x*x) + (y*y));
		}

		/**
		* get the magnitude of the vector using the double data type
		*/
		double magnitudeD() const
		{
			return (double)sqrt((x*x) + (y*y));
		}

		/**
		* Get the angle between two vectors
		* returned angle is a double in radians
		*/
		double getAngleBetween(const PhyVec& vec)
		{
			//must use double magnitude to get right value
			return (double) acos(dotProduct(vec) / (vec.magnitudeD() * magnitudeD()));
		}

		/**
		* Calculate the dot product between the
		* two vectors
		*/
		Type dotProduct(const PhyVec& vec)
		{
			return (vec.x * x) + (vec.y * y);
		}

		/**
		* Returns a Vector2f of the x and y values 
		*/
		sf::Vector2f getVector2f() const { return sf::Vector2f((float)x, (float)y); }

		/**
		* Operator to preform the dot proudct
		*/
		Type operator*(const PhyVec& vec)
		{
			return dotProduct(vec);
		}

		/**
		* Accessors
		*/
		Type getX() { return x; }
		Type getY() { return y; }


	};
}
#endif