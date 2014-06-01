#include "Particle.h"

using namespace GaltE;

Particle::Particle(const PhyVec<float>& pos, const PhyVec<float>& vel, double mMass, float mLifeTime)
{
	*position = pos;
	*velocity = vel;
	mass = mMass;
	lifeTime = mLifeTime;
	dead = false;

	if (lifeTime <= 0)
	{
		haveLifeTime = false;
	}
	else
	{
		haveLifeTime = true;
	}
	time = new Timer();
}

Particle::Particle(float xPos, float yPos, float xVel, float yVel, double mMass, float mLifeTime)
{
	position = new PhyVec<float>(xPos, yPos);
	velocity = new PhyVec<float>(xVel, yVel);
	mass = mMass;
	lifeTime = mLifeTime;
	dead = false;

	if (lifeTime <= 0)
	{
		haveLifeTime = false;
	}
	else
	{
		haveLifeTime = true;
	}
	time = new Timer();
}

Particle::~Particle()
{
	delete position;
	delete velocity;
	delete time;
}

void Particle::updatePos(float deltaT)
{
	position->x += (velocity->x * deltaT);
	position->y += (velocity->y * deltaT);
}

double Particle::momentum()
{
	return mass * velocity->magnitude();
}

void Particle::setLifeTime(float newTime)
{
	haveLifeTime = true;

	//get the time since the particle was created and add its value for lifetime 
	lifeTime = time->getTimeElapsed() + newTime;
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
		if (lifeTime <= time->getTimeElapsed())
		{
			dead = true;
		}
	}
	
	return dead;
}

void Particle::operator+(float additionalTime)
{
	this->increaseLifeTime(additionalTime);
}