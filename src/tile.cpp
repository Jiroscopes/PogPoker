#include "tile.h"
#include "game.h"
#include "TextureManager.h"

Tile::Tile(int x, int y, int type, SDL_Texture* texture)
{
	tileTexture = texture;
	mType = type;

	// Tile display rect
	mBox.x = x;
	mBox.y = y;
	mBox.h = TILE_HEIGHT;
	mBox.w = TILE_WIDTH;

	// Texture rect
	tBox.x = type * TILE_WIDTH;
	tBox.y = 0;
	tBox.h = TILE_HEIGHT;
	tBox.w = TILE_WIDTH;
}

void Tile::render()
{
	int x, y;
	SDL_RenderCopy(Game::renderer, tileTexture, &tBox, &mBox);
	//SDL_RenderDrawRect(Game::renderer, &mBox);
}

int Tile::getType()
{
	return mType;
}

SDL_Rect Tile::getBox()
{
	return mBox;
}
