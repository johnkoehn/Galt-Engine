#include "Timer.h"

using namespace GaltE;

Timer::Timer()
{
	clock = new sf::Clock();
}

Timer::~Timer()
{
	delete clock;
}

float Timer::getTimeElapsed()
{
	deltaT = clock->getElapsedTime();
	return deltaT.asSeconds();
}

float Timer::restart()
{
	deltaT = clock->restart();
	return deltaT.asSeconds();
}