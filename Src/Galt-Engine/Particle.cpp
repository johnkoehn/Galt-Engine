#include "Particle.h"

using namespace GaltE;

Particle::Particle(const ParticleData& data)
{
	position = new PhyVec<float>(data.xPos, data.yPos);
	velocity = new PhyVec<float>(data.xVel, data.yVel);
	mass = data.mass;
	lifeTime = data.lifeTime;
	dead = false;
	timePassed = 0;
	haveLifeTime = lifeTime > 0;

	//set the vertex array using sfml point
	particle = new sf::VertexArray(sf::Points, 1);
	(*particle)[0].position = position->getVector2f();
}

Particle::~Particle()
{
	delete position;
	delete velocity;
}

void Particle::update(float deltaT)
{
	position->x += (velocity->x * deltaT);
	position->y += (velocity->y * deltaT);

	//if the particle has a life time, update the time passed
	if (haveLifeTime)
	{
		timePassed += deltaT;
	}
}

double Particle::momentum()
{
	return mass * velocity->magnitude();
}

void Particle::setLifeTime(float newTime)
{
	haveLifeTime = true;

	lifeTime = newTime;
}

void Particle::increaseLifeTime(float additionalTime)
{
	haveLifeTime = true;
	lifeTime += additionalTime;
}

bool Particle::isDead()
{
	//check if the particle is on a timer, if so check if its lifeTime has expired
	if (haveLifeTime)
	{
		dead = lifeTime <= timePassed;
	}
	
	return dead;
}