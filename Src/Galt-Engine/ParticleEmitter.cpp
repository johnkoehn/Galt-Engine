#include "ParticleEmitter.h"

using namespace GaltE;

#define MAXPARTICLES 10000

ParticleEmitter::ParticleEmitter(float xPos, float yPos, int intensity, sf::Color particleColor, float particleLifeTime)
{
	mData.xPos = xPos;
	mData.yPos = yPos;
	mIntensity = intensity;
	mData.particleColor = particleColor;
	mData.lifeTime = particleLifeTime;
	extraTime = 0;
	mParticles.reserve(MAXPARTICLES);

	//set seed
	srand(std::time(NULL));
}

ParticleEmitter::~ParticleEmitter()
{
}

void ParticleEmitter::update(float timeDelta)
{
	//update old particles and eliminate those that exceeded their lifeTime
	for (int i = 0; i < mParticles.size(); i++)
	{
		mParticles[i].update(timeDelta);
		if (mParticles[i].isDead())
		{
			mParticles.erase(mParticles.begin()+i);
		}
	}

	//now add particles based on intensity * deltaT
	int particlesToAdd = (int)mIntensity * (timeDelta + extraTime);
	
	if (particlesToAdd == 0)
	{
		extraTime += timeDelta;
	}
	else
	{
		extraTime = 0;
		addParticles(particlesToAdd);
	}
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
	addParticles(amount);
}