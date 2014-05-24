#ifndef TIMER_H
#define TIMER_H

#include "Main.h"

namespace GaltE
{
	/**
	* Class acts as a timer, giving the time since the class object
	* was created in seconds
	*/
	class Timer
	{
	private:
		sf::Clock * clock;
		sf::Time deltaT;

	public:
		/**
		* Starts the timer
		*/
		Timer();

		/**
		* Basic deconstructor
		*/
		~Timer();

		/**
		* Gets the time elapsed since the timer was last started
		*/
		float getTimeElapsed();

		/**
		* Restarts the clock and returns the time since the timer was last started
		*/
		float restart();

	};
}

#endif