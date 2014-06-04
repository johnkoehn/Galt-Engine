#include "ParticleEmitter.h"

using namespace GaltE;

ParticleEmitter::ParticleEmitter(float xPos, float yPos, int intensity, sf::Color particleColor, float particleLifeTime)
{
	mData.xPos = xPos;
	mData.yPos = yPos;
	mIntensity = intensity;
	mData.particleColor = particleColor;
	mData.lifeTime = particleLifeTime;
	time = NULL;
	extraTime = 0;

	srand(std::time(NULL));
}

void ParticleEmitter::update()
{
	float timeDelta = time->restart();
	std::list<Particle>::iterator i;
	i = mParticles.begin();

	//update old particles and eliminate those that exceeded their lifeTime
	while (i != mParticles.end())
	{
		i->update(timeDelta);
		if (i->isDead())
		{
			i = mParticles.erase(i);
		}
		else
		{
			++i;
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

void ParticleEmitter::draw(Window& window)
{
	if (time == NULL)
	{
		std::cerr << "Particle Emitter hasn't started!\n";
		return;
	}
	update();
	std::list<Particle>::iterator i;
	for (i = mParticles.begin(); i != mParticles.end(); ++i)
	{
		i->drawParticle(window);
	}
}

void ParticleEmitter::begin(int amount)
{
	addParticles(amount);
	time = new Timer();
}