#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

using std::ifstream;

namespace GaltEngine
{
	class Map : public sf::Drawable, public sf::Transformable
	{
	private:
		sf::VertexArray m_vertices;
		sf::Texture m_tileset;
		int tileHeight;
		int tileWidth;
		std::vector<int>* tiles;
		std::string* tilesetFile;
		std::string* mapFile;

		//These values are measured in the number of tiles that fit into the map
		int mWidthTiles;
		int mHeightTiles;

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void getMapInfo();

	public:
		Map(std::string ftilesetFile, std::string fmapFile, int ftileHeight, int ftileWidth);
		Map();
		~Map();
		void mapSet(std::string ftilesetFile, std::string fmapFile, int ftileHeight, int ftileWidth);
		bool readLevel();

		int getMapWidth();
		int getMapHeight();
		int getMapWidthT(); //width of map in tiles
		int getMapHeightT(); //height of map in tiles

		/***
		*tileSize is a vector containg the size of the tiles
		*tiles is an array of integers repersenting the map
		*width and height are the map width and height in tiles
		***/
		bool load();

	};
}

#endif