#include "map.h"
#include "game.h"
#include <iostream>
#include <fstream>
#include "TextureManager.h"

Map::Map(int width, int height, const char* fileName, bool SHOW_GRID)
{
	screenWidth = width;
	screenHeight = height;
	const char* path = fileName;

	// Debug grid?
	showGrid = SHOW_GRID;

	// Load the map texture
	mMap = TextureManager::LoadTexture(path);

	// Set the tiles based on the map file
	if (setTiles(tileSet))
	{
		printf("Map loaded!\n");
	}
	else {
		printf("Map loading failed!\n");
	}

	// Debug grid
	if (SHOW_GRID)
	{
		// Load debug texture
		debugTileTexture = TextureManager::LoadTexture("../assets/white-border-debug.png");

		if (setDebugGrid())
		{
			printf("Debug Map loaded!\n");
		}
		else
		{
			printf("Debug Map loading failed!\n");
		}
	}
}

bool Map::setTiles(Tile* tiles[])
{

	bool tilesLoaded = true;
	int tileType = -1;
	int i;

	// offsets
	int x = 0;
	int y = 0;

	std::ifstream map("../assets/main.map");

	if (map.fail())
	{
		printf("Unable to load map file!\n");
		tilesLoaded = false;
	}
	else
	{

		Layer* newLayer = new Layer(TOTAL_TILES);

		// Add our layer to the array
		mapLayers.push_back(newLayer);

		std::vector<Tile*>* layerTiles = newLayer->getVector();

		for (i = 0; i < TOTAL_TILES; i++)
		{
			map >> tileType;

			if (map.fail())
			{
				printf("Error loading map: Unexpected end of file!\n");
				tilesLoaded = false;
				break;
			}
			// If tileType is valid
			
			if (tileType >= 0)
			{
				layerTiles->at(i) = new Tile(x, y, tileType, mMap);
			}
			else {
				printf("Error loading map: Invalid tile type at %d!\n", i);
				tilesLoaded = false;
				break;
			}

			x += TILE_WIDTH;

			// if we've reached the edge of the screen
			if (x >= screenWidth)
			{
				// reset x, move y down
				x = 0;
				y += TILE_HEIGHT;
			}
		}
		map.close();
	}

	return tilesLoaded;
}

bool Map::setDebugGrid()
{

	if (!showGrid)
	{
		return false;
	}

	int i;

	// offsets
	int x = 0;
	int y = 0;

	Layer* newLayer = new Layer(TOTAL_TILES);

	// Add our layer to the array
	mapLayers.push_back(newLayer);

	std::vector<Tile*>* layerTiles = newLayer->getVector();

	for (i = 0; i < TOTAL_TILES; i++)
	{
		layerTiles->at(i) = new Tile(x, y, 0, debugTileTexture);

		x += TILE_WIDTH;

		// if we've reached the edge of the screen
		if (x >= screenWidth)
		{
			// reset x, move y down
			x = 0;
			y += TILE_HEIGHT;
		}
	}
	return true;
}

void Map::draw()
{
	int i;

	for (Layer* layer: mapLayers)
	{
		std::vector<Tile*>* layerTiles = layer->getVector();

		for (i = 0; i < TOTAL_TILES; i++)
		{
			layerTiles->at(i)->render();
		}
	}

	SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 0);
}