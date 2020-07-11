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
	int x, y;
	SDL_Rect currentBox = this->getBox();
	SDL_GetMouseState(&x, &y);
	SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
	if ((x > currentBox.x && x < (currentBox.x + 80)) && (y > currentBox.y && y < (currentBox.y + 80) ))
	{
		SDL_SetRenderDrawColor(Game::renderer, 0, 175, 175, 255);
		SDL_RenderFillRect(Game::renderer, &currentBox);
		SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 0);
	}
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
