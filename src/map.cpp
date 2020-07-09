#include "map.h"
#include "game.h"

Map::Map(int width, int height)
{
	int i;
	for (i = 0; i < TOTAL_TILES; i++)
	{
		tileSet[i] = new Tile(i * 32, 0, mapArray[i]);
	}
	screenWidth = width;
	screenHeight = height;
}

void Map::draw()
{
	int i;
	SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
	for (i = 0; i < mapSize; i++)
	{
		tileSet[i]->render();
	}
	SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 0);
}