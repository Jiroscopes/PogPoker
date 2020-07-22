#pragma once
#include "TextureManager.h"

class Table
{
private:
	SDL_Texture* texture;
	SDL_Rect mBox, tBox;
public:
	Table();
	void render();
};