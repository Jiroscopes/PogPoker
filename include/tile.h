#pragma once
#include "SDL.h"

class Tile
{
private:
	const int TILE_WIDTH = 80;
	const int TILE_HEIGHT = 80;
	SDL_Rect mBox;
	int mType;
public:
	Tile(int x, int y, int type);
	void render();
	int getType();
	SDL_Rect getBox();
};