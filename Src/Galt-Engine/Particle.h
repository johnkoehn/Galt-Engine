#ifndef PARTICLE_H
#define PARTICLE_H

#include "main.h"
#include "Window.h"
#include "Timer.h"
#include "PhyVec.h"

namespace GaltE
{
	/**
	* Structure is used to pass data on the particle
	*/
	struct ParticleData
	{
		float xPos, yPos;
		float xVel, yVel;
		double mass;
		float lifeTime;
		sf::Color particleColor;
	};

	/**
	* This class contains the necessary data to make a particle
	* Particles have various features, such as their current location,
	* velocity and mass. Particles will have an emittion
	* time. If the time is succeded the particle is considered to be "dead."
	* Other options will later be added to let a particle be considered "dead."
	* Something imporatant to note about using the particle system is that the timePassed only increases
	* after particle update is called.
	*/
	class Particle
	{
	private:
		sf::VertexArray particle;
		PhyVec<float>* position;
		PhyVec<float>* velocity;
		double mass;
		bool alive;
		float lifeTime;
		float timePassed;

		Particle() {}
		Particle& operator=(Particle const&) {}

	public:
		

		/**
		* If you wish for no lifeTimer, set the inital lifetime value 
		* to zero or a negative value.
		*/
		Particle(const ParticleData& data);

		~Particle();

		/**
		* Updates the position of the particle based on the change in time. This change in time should be given from the particle emitter since
		* the last round of updates
		*/
		void update(float timeDelta);

		/**
		* Changes the velocity of the particle
		*/
		void setVel(float x, float y);

		/**
		* Changes the particle's velocity x value
		*/
		void setVelX(float x) { velocity->x = x; }

		/**
		* Changes the particle's velocity y value
		*/
		void setVelY(float y) { velocity->y = y; }

		/**
		* Change the position of the particle
		*/
		void setPos(float x, float y);
		
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
		void setDead() { alive = false; }

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
		* Checks if the particle is alive
		*/
		bool isAlive();

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
		float getTimePassed() { return timePassed; }

		/**
		* Returns the calculated momentum of the particle
		*/
		double momentum();

		/**
		* Returns the mass of the particle
		*/
		double getMass() { return mass; }

		/**
		* Method draws the particle to the window
		*/
		void drawParticle(Window& window);

		/**
		* Method resets the particle, having time start at zero again and the position return to the origin
		*/
		void reset(float xPos, float yPos);

	};

}


#endif