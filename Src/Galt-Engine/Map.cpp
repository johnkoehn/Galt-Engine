#include "Map.h"

using namespace GaltEngine;

bool Map::load(const std::string& tilesetFile, sf::Vector2u tileSize, const std::vector<int>& tiles, unsigned int width, unsigned int height)
{
	//load the texture for the map
	if (!m_tileset.loadFromFile(tilesetFile))
	{
		std::cout << "Failed to find tilesetFile!\n";
		return false;
	}

	//resize the vertex array to fit the level size
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	for (unsigned int i = 0; i < width; ++i)
	{
		for (unsigned int j = 0; j < height; ++j)
		{
			//check for going out of the vector tiles bounds
			if ((i + (j*width)) >= tiles.size())
			{
				std::cerr << "Out of bounds for tiles vector, aborting!";
				return false;
			}

			//get the current tile number
			int tileNumber = tiles[i + (j * width)];

			//find its position in the tileset texture
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

			//get a pointer to the current tile's quad
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			//define its 4 corners
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			//define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}
	}
	return true;
}


void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//apply the transfrom
	states.transform *= getTransform();

	//apply the tileset texture
	states.texture = &m_tileset;

	//draw the vertex array
	target.draw(m_vertices, states);
}