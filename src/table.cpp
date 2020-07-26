#include "table.h"
#include "game.h"
Table::Table()
{
	texture = TextureManager::LoadTexture("../assets/table-3.png");
	mBox.x = 80;
	mBox.y = 80;
	mBox.w = 1120;
	mBox.h = 560;

	tBox.x = 0;
	tBox.y = 0;
	tBox.w = 1120;
	tBox.h = 560;

}

void Table::render()
{
	SDL_RenderCopy(Game::renderer, texture, &tBox, &mBox);
}