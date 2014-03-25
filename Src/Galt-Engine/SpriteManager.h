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
		//sf::Sprite findSprite(int spriteID); Need to look into how to make this function

	public:
		SpriteManager(std::string filename, std::string texturesFile);
		void add(Sprite newSprite);
		void updatePosition(int spriteID, double deltaX, double deltaY);
		void displaySprites(sf::RenderWindow& window);


	};
}

#endif