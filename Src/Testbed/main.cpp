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



#include <iostream>
#include "..\Galt-Engine\Window.h"
#include "..\Galt-Engine\Camera.h"
#include <ctime>

int main()
{
	//prepare a clock
	std::clock_t start;
	double duration;

	start = std::clock();
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	//create the window
	std::string title = "Engine V.01";
	GaltE::Window window(800, 600, false, title);

	window.setColor(sf::Color::Blue);

	//draw some rectangles for testing
	sf::RectangleShape shape1(sf::Vector2f(40, 50));
	shape1.setFillColor(sf::Color::Black);
	shape1.setPosition(200, 200);

	sf::RectangleShape shape2(sf::Vector2f(50, 50));
	shape2.setFillColor(sf::Color::Green);
	shape2.setPosition(1000, 1000);

	//camera test
	GaltE::Camera camera1(sf::FloatRect(50, 50, 400, 300));
	GaltE::Camera camera2(sf::FloatRect(800, 800, 400, 300));

	//camera1.zoom(.25);
	//camera1.move(0, 100);
	//camera1.setRotation(20);
	//camera1.setCenter(sf::Vector2f(0,0));
	camera1.setViewport(sf::FloatRect(0, 0, 0.5, 1));
	//camera2.setViewport(sf::FloatRect(0.5, 0, 0.5, 1));

	//Get Event
	sf::Event * winEvent = window.getEvent();

	while (window.isOpen())
	{
		window.clear();
		window.draw(shape1);
		window.draw(shape2);
		window.setCamera(camera1);
		//window.setCamera(camera2);
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