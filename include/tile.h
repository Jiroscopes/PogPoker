#pragma once
#include "SDL.h"

class Tile
{
private:
	const int TILE_WIDTH = 32;
	const int TILE_HEIGHT = 32;
	SDL_Rect mBox;
	int mType;
public:
	Tile(int x, int y, int type);
	void render();
	int getType();
	SDL_Rect getBox();
};