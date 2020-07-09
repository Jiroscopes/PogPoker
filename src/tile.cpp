#include "tile.h"
#include "game.h"

Tile::Tile(int x, int y, int type)
{
	mBox.x = x;
	mBox.y = y;
	mBox.h = TILE_HEIGHT;
	mBox.w = TILE_WIDTH;

	mType = type;
}

void Tile::render()
{
	SDL_RenderDrawRect(Game::renderer, &mBox);
}

int Tile::getType()
{
	return mType;
}

SDL_Rect Tile::getBox()
{
	return mBox;
}
