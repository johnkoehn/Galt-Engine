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

	//Get Event
	sf::Event * winEvent = window.getEvent();

	while (window.isOpen())
	{
		window.clear();
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