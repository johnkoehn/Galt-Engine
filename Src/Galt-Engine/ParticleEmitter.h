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
		bool started;

		/**
		* Method updates the particles position, removes particles that
		* have gone over their lifeTime and adds new ones based on the intensity
		*/
		void update(float timeDelta);

		/**
		* adds the number of particles that need to be added
		*/
		void addParticles(int particlesToAdd);

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
		* This creates a burst of particles
		*/
		void burst(int amount);

		/**
		* Method updates the particles positions and removes "dead" particles
		*/
		void updateParticles(float timeDelta);

		/**
		* Method updates the particles and then draw them to the screen
		*/
		void draw(Window& window, float timeDelta);

		/**
		* Draws the particles to the screen
		*/
		void draw(Window& window);

		/**
		* Method sets the intensity of the emitter to zero
		*/
		void end() { mIntensity = 0; }

		/**
		* Moves the particle by the x and y value given
		*/
		void move(float deltaX, float deltaY);
	};
}

#endif