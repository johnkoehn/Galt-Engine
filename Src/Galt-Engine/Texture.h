#ifndef TEXTURE_H
#define TEXTURE_H

#include "Main.h"

namespace GaltE
{
	/**
	* Class encapsulates an sfml texture. Currently the texture class is a very simple
	* form of the sfml texture class. 
	*/
	class Texture
	{
	private:
		sf::Texture texture;

	public:
		/**
		* Defualt constructor 
		*/
		Texture();

		/**
		* Loads an image from a file, returns false if it failed
		*/
		bool loadFromFile(const std::string &filename);

		/**
		* Creates a texture with the given width and height, returns false if failed
		*/
		bool create(unsigned width, unsigned height);

		/**
		* Sets if the texture is smooth or not
		* Set the texture to be smooth if scaleing is occuring
		*/
		void setSmooth(bool smooth);

		/**
		* Returns the sfml texture
		*/
		sf::Texture getSFTexture();


	};
}

#endif
