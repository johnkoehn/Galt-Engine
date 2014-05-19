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
	private:
		Type x;
		Type y;

	public:
		/**
		* Give the xCoordinate and yCoordinate
		*/
		PhyVec(Type xCoordinate, Type yCoordinate);

		/**
		* Change x and y value by an amount
		*/
		void updatePos(Type deltaX, Type deltaY);

		/**
		* Change x value by an amount
		*/
		void updateX(Type deltaX);

		/**
		* Change y value by an amount
		*/
		void updateY(Type deltaY);

		/**
		* Set x and y value
		*/
		void setPos(Type newX, Type newY);

		/**
		* Set x value
		*/
		void setX(Type newX);

		/**
		* set y value
		*/
		void setY(Type setY);

		/**
		* get the magnitude of the vector
		*/
		Type magnitude();

		/**
		* Get the angle between two vectors
		* returned angle is an int to prevent rounding 
		* issues
		*/
		int getAngleBetween(const PhyVec& vec);

		/**
		* Calculate the dot product between the 
		* two vectors
		*/
		Type dotProduct(const PhyVec& vec);

		/**
		* Operator to preform the dot proudct
		*/
		Type operator*(const PhyVec& vec);


	};
}
#endif