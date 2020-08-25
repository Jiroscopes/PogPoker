#pragma once
#include "SDL.h"
#include "tile.h"

const int TOTAL_TILES = 144; // Tiles Wide x Tiles Tall

class Map
{
private:
	int screenWidth, screenHeight;
	Tile* tileSet[TOTAL_TILES];
	SDL_Texture* mMap;
	bool showGrid;
public:
	Map(int width, int height, const char* fileName, bool SHOW_GRID = false);
	bool setTiles(Tile* tiles[]);
	void draw();
};