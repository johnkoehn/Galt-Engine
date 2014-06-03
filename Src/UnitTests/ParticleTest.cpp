/*#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../Src/Galt-Engine/Particle.h"
#include "SFML/Graphics.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(ParticleTest)
	{
	private:
		GaltE::Particle* particle1;
		GaltE::ParticleData data;

		void setParticles()
		{
			data.xPos = 10;
			data.yPos = 10;
			data.lifeTime = 10.0f;
			data.mass = 5;
			data.xVel = 15;
			data.yVel = 10;
			data.particleColor = sf::Color::Red;
			particle1 = new GaltE::Particle(data);
		}

	public:
		TEST_METHOD(CheckLifeTime)
		{
			setParticles();
			particle1->update(5.0f);
			Assert::AreEqual(5.0f, particle1->getTimePassed());
		}
	};
}*/

#include "stdafx.h"