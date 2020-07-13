#include "map.h"
#include "game.h"
#include <iostream>
#include <fstream>
#include "TextureManager.h"

Map::Map(int width, int height)
{
	screenWidth = width;
	screenHeight = height;
	const char* path = "../assets/map-tileset.png";

	mMap = TextureManager::LoadTexture(path);
	std::cout << "Map load:" << mMap << std::endl;
	if (setTiles(tileSet, mMap))
	{
		printf("Map loaded!\n");
	}
	else {
		printf("Map loading failed!\n");
	}
}

bool Map::setTiles(Tile* tiles[], void* mapPTR)
{

	bool tilesLoaded = true;
	int tileType = -1;
	int i, j;

	// TODO: Move these and make them constants
	int TILE_HEIGHT = 80;
	int TILE_WIDTH = 80;

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
				tiles[i] = new Tile(x, y, tileType, mMap);
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

void Map::draw()
{
	int i;
	//SDL_Rect renderQuad = { 80, 0, 80, 80 };
	SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
	//std::cout << tileSet[0]->getBox().w << std::endl;
	for (i = 0; i < TOTAL_TILES; i++)
	{
		//SDL_RenderCopy(Game::renderer, mMap, &renderQuad, &tileSet[i]->getBox());
		tileSet[i]->render();
	}
	SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 0);
}