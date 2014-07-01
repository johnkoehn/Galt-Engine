#ifndef PARTICLE_EMTIIER_H
#define PARTICLE_EMITTER_H

#include "Main.h"
#include "Particle.h"

namespace GaltE
{
	/**
	* Class allows for the emitting of particles.
	* The class at this current state is very bare bones 
	* and will be missing features such as having particles 
	* deaccelerate over time and a randomness factor 
	*/
	class ParticleEmitter
	{
	private:
		ParticleData mData;
		int mIntensity;
		std::vector<Particle> mParticles;
		float mExtraTime;
		float mTotalTime;

		/**
		* Method updates the particles position, removes particles that
		* have gone over their lifeTime and adds new ones based on the intensity
		*/
		void update(float timeDelta);

		/**
		* adds the number of particles that need to be added
		*/
		void addParticles(int particlesToAdd);

		/**
		* Method updates the particles positions and removes "dead" particles
		*/
		void updateParticles(float timeDelta);

	public:
		/*
		* Intensity if the amount of particles being emitted per second,
		* the position values are where the particles will be emitted
		* and the color is the color of the particles from the emitter
		* particleLifeTime is the time in seconds each particle will be alive
		*/
		ParticleEmitter(float xPos, float yPos, int intensity, sf::Color particleColor, float particleLifeTime);
		~ParticleEmitter();

		/**
		* This starts the emitting of particles, pass in the amount of inital particles 
		* to create.
		*/
		void begin(int amount);

		/**
		* Method updates the particles and then draw them to the screen
		*/
		void draw(Window& window, float timeDelta);

		/**
		* Method sets the intensity of the emitter to zero
		*/
		void end() { mIntensity = 0; }
	};
}

#endif