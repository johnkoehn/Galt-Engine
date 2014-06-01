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
	* time. If the time is succeded the particle is considered to be "dead."
	* Other options will later be added to let a particle be considered "dead."
	*/
	class Particle
	{
	private:
		PhyVec<float>* position;
		PhyVec<float>* velocity;
		double mass;
		float lifeTime;
		bool dead;
		bool haveLifeTime;
		Timer* time;

	public:
		/**
		* If you wish for no lifeTimer, set the inital lifetime value 
		* to zero or a negative value.
		*/
		Particle(const PhyVec<float>& pos, const PhyVec<float>& vel, double mMass, float mLifeTime);

		Particle(float xPos, float yPos, float xVel, float yVel, double mMass, float mLifeTime);

		~Particle();

		/**
		* Updates the position of the particle based on the change in time. This change in time should be given from the particle emitter since
		* the last round of updates
		*/
		void updatePos(float deltaT);

		/**
		* Changes the particle's velocity x value
		*/
		void setVelX(float x) { velocity->x = x; }

		/**
		* changes the particle's velocity y value
		*/
		void setVelY(float y) { velocity->y = y; }

		/**
		* Changes the particle's position x value
		*/
		void setPosX(float x) { position->x = x; }

		/**
		* changes the particle's position y value
		*/
		void setPosY(float y) { position->y = y; }

		/**
		* Increases the particle's velocity x value
		* by given amount
		*/
		void velXInc(float deltaX) { velocity->x += deltaX; }

		/**
		* Increases the particle's velocity y value
		* by given amount
		*/
		void velYInc(float deltaY) { velocity->y += deltaY; }

		/**
		* Increases the particle's position x value
		* by given amount
		*/
		void posXInc(float deltaX) { position->x += deltaX; }

		/**
		* Increases the particle's position y value
		* by given amount
		*/
		void posYInc(float deltaY) { position->y += deltaY; }

		/**
		* Set the particle to being dead
		*/
		void setDead() { dead = true; }

		/**
		* Increase the mass of the particle
		*/
		void increaseMass(float extraMass) { mass += extraMass; }

		/**
		* Sets the mass of the particle
		*/
		void setMass(float newMass) { mass = newMass; }

		/**
		* Set the lifetime of the particle. If the particle didn't have a lifeTime Before, it will
		* now be set to have a lifeTime.
		*/
		void setLifeTime(float newTime);

		/**
		* Increases the lifetime the particle has. If the particle wasn't set to have a lifeTime before, it will
		* now be set to have a lifeTime.
		*/
		void increaseLifeTime(float additionalTime);

		/**
		* Checks if the particle is dead
		*/
		bool isDead();

		/**
		* Get the particle's velocity as a PhyVec
		*/
		PhyVec<float> getVelocitiy() { return *velocity; }

		/**
		* Get the particle's position as a PhyVec
		*/
		PhyVec<float> getPosition() { return *position; }

		/**
		* Get the time that has passed in seconds since the particle was emitted
		*/
		float getTimePassed() { return time->getTimeElapsed(); }

		/**
		* Get the pointer of the timer object of the particle
		*/
		Timer* getTimer() { return time; }

		/**
		* Returns the calculated momentum of the particle
		*/
		double momentum();

		/**
		* Returns the mass of the particle
		*/
		double getMass() { return mass; }

		/**
		* Operator allows you to add additional time to a particle's lifeTime
		* Example: particle1 += 0.5f
		*/
		void operator+(float additionalTime);

	};
}


#endif