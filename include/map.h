#pragma once
#include "SDL.h"
#include "tile.h"
#include "Layer.h"
#include <vector>

const int TOTAL_TILES = 144; // Tiles Wide x Tiles Tall

class Map
{
private:
	const int TILE_HEIGHT = 80;
	const int TILE_WIDTH = 80;

	int screenWidth, screenHeight;
	bool showGrid;

	Tile* tileSet[TOTAL_TILES];

	SDL_Texture* mMap;
	SDL_Texture* debugTileTexture = nullptr;

	std::vector<Layer*> mapLayers;

public:
	Map(int width, int height, const char* fileName, bool SHOW_GRID = false);
	bool setTiles(Tile* tiles[]);
	bool setDebugGrid();
	void draw();
};