#include "tile.h"
#include "game.h"
#include "TextureManager.h"

Tile::Tile(int x, int y, int type, SDL_Texture* texture)
{
	tileTexture = texture;
	mType = type;

	//std::cout << texture << std::endl;

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
	//SDL_Rect currentBox = ;
	//SDL_GetMouseState(&x, &y);
	//SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
	//if ((x > currentBox.x && x < (currentBox.x + 80)) && (y > currentBox.y && y < (currentBox.y + 80) ))
	//{
	//	SDL_SetRenderDrawColor(Game::renderer, 0, 175, 175, 255);
	//	SDL_RenderFillRect(Game::renderer, &currentBox);
	//	SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 0);
	//}
	//int type = this->getType();
	//std::cout << tBox.x << std::endl;
	//SDL_Texture* test = TextureManager::LoadTexture("../assets/map-tileset.png");
	//std::cout << "Test: " << tileTexture << std::endl;
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
