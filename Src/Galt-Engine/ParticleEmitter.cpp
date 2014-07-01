#include "ParticleEmitter.h"

using namespace GaltE;

#define ClEANTIME 5.5f

ParticleEmitter::ParticleEmitter(float xPos, float yPos, int intensity, sf::Color particleColor, float particleLifeTime)
{
	mData.xPos = xPos;
	mData.yPos = yPos;
	mIntensity = intensity;
	mData.particleColor = particleColor;
	mData.lifeTime = particleLifeTime;
	mExtraTime = 0;
	mTotalTime = 0;
	mTimeSinceClean = 0;
	mParticles.reserve(0);

	//set seed
	srand(std::time(NULL));
}

ParticleEmitter::~ParticleEmitter()
{
}

void ParticleEmitter::update(float timeDelta)
{
	mTotalTime += timeDelta;
	mTimeSinceClean += timeDelta;
	mExtraTime += timeDelta;

	//update old particles and eliminate those that exceeded their lifeTime
	for (int i = 0; i < mParticles.size(); i++)
	{
		mParticles[i].update(timeDelta);
		if (mParticles[i].isDead())
		{
			mParticles.erase(mParticles.begin() + i);
		}
	}

	//now add particles based on intensity * deltaT
	int particlesToAdd = (int)(mIntensity * timeDelta);

	if (particlesToAdd >= 1)
	{
		//TODO We have an inconsitent extraTime, eventually, someTime will be left out, thus less particles will get add
		//then should be
		mExtraTime = 0;
		addParticles(particlesToAdd);
	}

	//check if memory cleanup in necessary
	/*if (mTimeSinceClean > ClEANTIME)
	{
		cleanUp();
		mTimeSinceClean = 0;
	}*/
}

void ParticleEmitter::addParticles(int particlesToAdd)
{
	for (int i = 0; i < particlesToAdd; i++)
	{
		//get random velocities
		mData.xVel = (20 + (rand() % 10));
		if ((int)(rand() % 2))
		{
			mData.xVel *= -1;
		}

		mData.yVel = (float)(20 + (rand() % 10));
		if ((int)(rand() % 2))
		{
			mData.yVel *= -1;
		}

		Particle tempParticle(mData);
		mParticles.push_back(tempParticle);
	}
}

void ParticleEmitter::draw(Window& window, float timeDelta)
{
	if (time == NULL)
	{
		std::cerr << "Particle Emitter hasn't started!\n";
		return;
	}
	update(timeDelta);
	for (int i = 0; i < mParticles.size(); i++)
	{
		mParticles[i].drawParticle(window);
	}
}

void ParticleEmitter::begin(int amount)
{
	/*
	* To calculate the maximum number of particles needed for the vector to hold 
	* we use the following formula:
	* (Intensity * particle lifetime or cleanup time (depending on which is longer)) + inital burst value + 0.5
	*/
	float multiplyer = 0;
	if (ClEANTIME > mData.lifeTime)
	{
		multiplyer = ClEANTIME;
	}
	else
	{
		multiplyer = mData.lifeTime;
	}
	int maxSize = (int)((mIntensity * multiplyer) + amount + 0.5);
	mParticles.reserve(maxSize);
	addParticles(amount);
}

void ParticleEmitter::cleanUp()
{
	for (int i = 0; i < mParticles.size(); i++)
	{
		if (mParticles[i].isDead())
		{
			mParticles.erase(mParticles.begin() + i);
		}
	}
}