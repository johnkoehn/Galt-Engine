#ifndef PARTICLE_H
#define PARTICLE_H

#include "main.h"
#include "Window.h"
#include "Timer.h"
#include "PhyVec.h"

namespace GaltE
{
	/**
	* This class contains the necessary data to make a particle
	* Particles have various features, such as their current location,
	* velocity and mass. Particles will also have the option to have a emittion
	* time. If the time is succeded the particle is considered to be "dead"
	*/
	class Particle
	{
	private:
		PhyVec<float> position;
		PhyVec<float> velocity;
		double mass;
		float lifetime;
		bool dead;
		bool haveLifetime;

	public:
		/**
		* If you which for no lifeTimer, set the inital lifetime value 
		* to zero.
		*/
		Particle(const PhyVec<float>& pos, const PhyVec<float>& vel, double mass, float lifetime);
	};
}


#endif