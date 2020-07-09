#pragma once
#include "SDL.h"
#include "tile.h"

const int TOTAL_TILES = 100;

class Map
{
private:
	SDL_Rect srcRect, destRect;
	int screenWidth, screenHeight;
	int mapSize = 100;
	int mapArray[100] = { 0 };
	Tile* tileSet[TOTAL_TILES];
public:
	Map(int width, int height);
	void draw();
};