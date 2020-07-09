#pragma once
#include "SDL.h"
#include "tile.h"

const int TOTAL_TILES = 194;



class Map
{
private:
	int screenWidth, screenHeight;
	Tile* tileSet[TOTAL_TILES];
public:
	Map(int width, int height);
	void setTiles(Tile* tiles[]);
	void draw();
};