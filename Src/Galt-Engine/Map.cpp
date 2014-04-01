#include "Map.h"

using namespace GaltEngine;

Map::Map(std::string ftilesetFile, std::string fmapFile, int ftileHeight, int ftileWidth)
{
	//initalize pointers
	tilesetFile = new std::string;
	mapFile = new std::string;
	tiles = new std::vector<int>;

	*tilesetFile = ftilesetFile;
	*mapFile = fmapFile;
	tileWidth = ftileWidth;
	tileHeight = ftileHeight;
}

Map::Map()
{
	//initalize pointers
	tilesetFile = new std::string;
	mapFile = new std::string;
	tiles = new std::vector<int>;
}

Map::~Map()
{
	if (tiles != NULL)
	{
		delete tiles;
	}

	if (tilesetFile != NULL)
	{
		delete tilesetFile;
	}

	if (mapFile != NULL)
	{
		delete mapFile;
	}
}

/***
*Used for constructing map later
***/
void Map::mapSet(std::string ftilesetFile, std::string fmapFile, int ftileHeight, int ftileWidth)
{
	*tilesetFile = ftilesetFile;
	*mapFile = fmapFile;
	tileWidth = ftileWidth;
	tileHeight = ftileHeight;
}

bool Map::readLevel()
{
	ifstream indata;
	indata.open(*mapFile);

	//to avoid the vector constantly resizing will set a capacity
	int capacity = 500;
	tiles->resize(capacity);

	if (!indata)
	{
		std::cerr << "Failed to find the level file!\n";
		return false;
	}

	//read the text file for all the integers
	int readInt;
	int i = 0;
	while (!indata.eof())
	{
		indata >> readInt;
		(*tiles)[i] = readInt;

		i += 1;
		if (!(i < capacity))
		{
			capacity += 250;
			tiles->resize(capacity);
		}
	}

	indata.close();

	//get mWidthTiles and mHeightTiles
	getMapInfo();
	
	//no longer need mapFile
	delete mapFile;
	mapFile = NULL;
	return true;
}

bool Map::load()
{
	//load the texture for the map
	if (!m_tileset.loadFromFile(*tilesetFile))
	{
		std::cout << "Failed to find tilesetFile!\n";
		return false;
	}

	//create a vector containg the tileSize
	sf::Vector2u tileSize = sf::Vector2u(tileWidth, tileHeight);

	//resize the vertex array to fit the level size
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(mWidthTiles * mHeightTiles * 4);

	for (unsigned int i = 0; i < mWidthTiles; ++i)
	{
		for (unsigned int j = 0; j < mHeightTiles; ++j)
		{
			//check for going out of the vector tiles bounds
			if ((i + (j*mWidthTiles)) >= tiles->size())
			{
				std::cerr << "Out of bounds for tiles vector, aborting!";
				return false;
			}

			//get the current tile number
			int tileNumber = (*tiles)[i + (j * mWidthTiles)];

			//find its position in the tileset texture
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

			//get a pointer to the current tile's quad
			sf::Vertex* quad = &m_vertices[(i + j * mWidthTiles) * 4];

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

	//free memorey
	delete tilesetFile;
	tilesetFile = NULL;

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

void Map::getMapInfo()
{
	ifstream file;
	file.open(*mapFile);

	std::string dummyString; //used to get # of columns
	int c = 0;				 //used to get # of rows

	//get map height
	while (!file.eof())
	{
		getline(file, dummyString);
		c++;
	}
	mHeightTiles = c;
	file.close();

	//now get columns
	std::stringstream is(dummyString);
	int n;
	c = 0;

	while (is >> n)
	{
		c++;
	}
	mWidthTiles = c;

	delete mapFile;
	mapFile = NULL;
}

int Map::getMapHeight()
{
	return mHeightTiles * tileHeight;
}

int Map::getMapWidth()
{
	return mWidthTiles * tileWidth;
}

int Map::getMapHeightT()
{
	return mWidthTiles;
}

int Map::getMapWidthT()
{
	return mHeightTiles;
}
