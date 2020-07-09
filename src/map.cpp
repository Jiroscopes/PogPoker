#include "map.h"
#include "game.h"
#include <iostream>

Map::Map(int width, int height)
{
	//int i;
	//for (i = 0; i < TOTAL_TILES; i++)
	//{
	//	tileSet[i] = new Tile(i * 80, 0, 0);
	//}

	int numWide = width / 80;
	int numTall = height / 80;
	int total = numWide * numTall;
	screenWidth = width;
	screenHeight = height;
	setTiles(tileSet);
}

void Map::setTiles(Tile* tiles[])
{
	int i, j;
	int TILE_HEIGHT = 80;
	int TILE_WIDTH = 80;

	// offsets
	int x = 0;
	int y = 0;

	for (i = 0; i < TOTAL_TILES; i++)
	{
		tiles[i] = new Tile(x, y, 0);
		x += TILE_WIDTH;

		// if we've reached the edge of the screen

		if (x >= screenWidth)
		{
			// reset x, move y down
			x = 0;
			y += TILE_HEIGHT;
		}
	}
}

void Map::draw()
{
	int i;
	SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
	for (i = 0; i < TOTAL_TILES; i++)
	{
		tileSet[i]->render();
	}
	SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 0);
}