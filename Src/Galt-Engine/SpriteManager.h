#ifndef SPRITEMANAGER
#define SPRITEMANAGER

#include "Sprite.h"
#include <list>
#include <fstream>
#include "TextureManager.h"

using std::ifstream;
using std::list;

namespace GaltEngine
{
	class SpriteManager
	{
	private:
		list<Sprite> sprites;
		TextureManager textureManager;

		bool readFile(std::string filename);

	public:
		SpriteManager(std::string filename, std::string texturesFile);
		void add(Sprite newSprite);
		//void update(); will work on later
		void displaySprites(sf::RenderWindow& window);


	};
}

#endif