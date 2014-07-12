#define WIN32_LEAN_AND_MEAN 1

#define WIN32 1

//SFML related
#ifdef WIN32
	#pragma once
	#define _CRT_SECURE_NO_WARNINGS 1


	#include <Windows.h>

	#ifdef _DEBUG
		#pragma comment (lib, "sfml-audio-s-d.lib")
		#pragma comment (lib, "sfml-graphics-s-d.lib")
		#pragma comment (lib, "sfml-system-s-d.lib")
		#pragma comment (lib, "sfml-window-s-d.lib")
		#pragma comment (lib, "Galt Engine-d.lib")
	#else
		#pragma comment (lib, "sfml-audio-s.lib")
		#pragma comment (lib, "sfml-graphics-s.lib")
		#pragma comment (lib, "sfml-system-s.lib")
		#pragma comment (lib, "sfml-window-s.lib")
		#pragma comment (lib, "Galt Engine.lib")
	#endif



	#pragma comment(lib, "glew.lib")
	#pragma comment(lib, "freetype.lib")
	#pragma comment(lib, "jpeg.lib")
	#pragma comment(lib, "opengl32.lib")
	#pragma comment(lib, "winmm.lib")
	#pragma comment(lib, "gdi32.lib")


#endif



#include "Includes.h"

using namespace GaltE;

const float yCMovement = 20;
const float xCMovement = 20;

int main()
{

	//create the window
	std::string title = "Engine V.01";
	Window window(800, 600, false, title);

	window.setColor(sf::Color::Blue);

	//draw some rectangles for testing
	sf::RectangleShape shape1(sf::Vector2f(40, 50));
	shape1.setFillColor(sf::Color::Black);
	shape1.setPosition(200, 200);

	sf::RectangleShape shape2(sf::Vector2f(50, 50));
	shape2.setFillColor(sf::Color::Green);
	shape2.setPosition(1000, 1000);

	//camera test
	Camera camera1(sf::FloatRect(0, 0, 800, 600));

	//Get Event
	sf::Event * winEvent = window.getEvent();

	//Start a timer
	Timer time;
	float deltaT = 0;

	//Set up KeyInput
	KeyInput keyInput;

	//Particle design pratice
	//Particle p1();
	//Particle p2();
	//p1 = p2;


	//particle emitter test
	ParticleEmitter emitter(100, 100, 1000, sf::Color::Red, 2.0f);

	ParticleEmitter emitter2(60, 60, 100, sf::Color::Red, 1.0f);
	emitter2.burst(200);


	while (window.isOpen())
	{
		window.clear();

		//get change in time
		deltaT = time.restart();
		std::cout << deltaT << std::endl;

		//check for keyboard input
		if (keyInput.W())
		{
			camera1.move(0, -(yCMovement * deltaT));
		}
		if (keyInput.S())
		{
			camera1.move(0, yCMovement * deltaT);
		}
		if (keyInput.A())
		{
			camera1.move(-(xCMovement * deltaT), 0);
		}
		if (keyInput.D())
		{
			camera1.move(xCMovement * deltaT, 0);
		}
		emitter.draw(window, deltaT);
		emitter2.draw(window, deltaT);
		emitter.move(30 * deltaT, 30 * deltaT);
		window.draw(shape1);
		window.draw(shape2);
		window.setCamera(camera1);
		window.display();

		//check for new window events that occured since the last loop iteration
		if (window.pollEvent())
		{
			//if a close requested event occurs, close the window
			if ((*winEvent).type == sf::Event::Closed)
			{
				window.exit();
			}
		}
	}

	return 0;
}