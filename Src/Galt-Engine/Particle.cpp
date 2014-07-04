#include "Particle.h"

using namespace GaltE;

Particle::Particle(const ParticleData& data)
{
	position = new PhyVec<float>(data.xPos, data.yPos);
	originalX = data.xPos;
	originalY = data.yPos;

	velocity = new PhyVec<float>(data.xVel, data.yVel);

	mass = data.mass;
	lifeTime = data.lifeTime;
	alive = true;
	timePassed = 0.0f;

	//set the vertex array using sfml point
	particle.setPrimitiveType(sf::Points);
	particle.resize(1);
	particle[0].color = data.particleColor;
	particle[0].position = position->getVector2f();
}

Particle::~Particle()
{
}

void Particle::update(float timeDelta)
{
	//if the particle is alive, update position and timePassed
	if (alive)
	{
		position->x += (velocity->x * timeDelta);
		position->y += (velocity->y * timeDelta);
		
		timePassed += timeDelta;
		isAlive();
	}

}

double Particle::momentum()
{
	return mass * velocity->magnitude();
}

void Particle::setLifeTime(float newTime)
{
	lifeTime = newTime;
}

void Particle::increaseLifeTime(float additionalTime)
{
	lifeTime += additionalTime;
}

bool Particle::isAlive()
{
	//check if lifetime exceeded
	if (timePassed >= lifeTime)
	{
		alive = false;
	}
	
	return alive;
}

void Particle::drawParticle(Window& window)
{	
	if (alive)
	{
		//update the particle position
		particle[0].position = position->getVector2f();
		window.draw(particle);
	}

}

void Particle::reset()
{
	alive = true;
	timePassed = 0;

	position->x = originalX;
	position->y = originalY;
}