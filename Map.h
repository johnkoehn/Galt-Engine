#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <iostream>

namespace GaltEngine
{
	class Map : public sf::Drawable, public sf::Transformable
	{
	private:
		sf::VertexArray m_vertices;
		sf::Texture m_tileset;
		/*
		std::string tilesetFile;
		int tileHeight;
		int tileWidth;
		const int* map; //an array of integers containg the map

		//map width is measured in tiles
		int mapWidth;
		int mapHeight;
		*/

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	public:
		/***
		*tileSize is a vector containg the size of the tiles
		*tiles is an array of integers repersenting the map
		*width and height are the map width and height in tiles
		***/
		bool load(const std::string& tilesetFile, sf::Vector2u tileSize, const std::vector<int>& tiles, unsigned int width, unsigned int height);

	};
}

#endif