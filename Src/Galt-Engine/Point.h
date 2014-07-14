#ifndef POINT_H
#define POINT_H

namespace GaltE
{
	template<class Type>

	/**
	* Class contains an x and y value
	*/
	class Point
	{
	public:
		Type x;
		Type y;

		/**
		* Give the x and y value to create the point object
		*/
		Point(Type xVal, Type yVal)
		{
			x = xVal;
			y = yVal;
		}
	};
}

#endif